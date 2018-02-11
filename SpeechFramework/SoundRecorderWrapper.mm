//
//  SoundRecorderWrapper.m
//  SpellingBee
//
//  Created by Daniel Oberg on 2017-06-24.
//  Copyright © 2017 Daniel Oberg. All rights reserved.
//

#import "SoundRecorderWrapper.h"

#include <vector>

#import <AVFoundation/AVFoundation.h>
#import <AVFoundation/AVAudioSession.h>
#import <CoreVideo/CVPixelBuffer.h>

#import <opencv2/imgcodecs/ios.h>
#import <AZSClient/AZSClient.h>

#import "SpellingBee.h"
#import "SoundRecorder.hh"

@implementation SoundRecorderWrapper

- (instancetype)init {
    self = [super init];
    if (self) {
        // Create the data model.
        if (@available(iOS 11.0, *)) {
            _spellingBeeModel = [SpellingBee new];
            _secToIgnoreOnSuccess = 0.4;
            _ignoreToTime = 0.0;
        } else {
            // Fallback on earlier versions
        }
        
    }
    return self;
}


- (void)checkForPermissionAndStart {
    [[AVAudioSession sharedInstance] requestRecordPermission:^(BOOL granted) {
        if (granted) {
            [[AVAudioSession sharedInstance] setCategory:AVAudioSessionCategoryPlayAndRecord
                                                    mode:AVAudioSessionModeVoiceChat
                                                 options:AVAudioSessionCategoryOptionDuckOthers
                                                   error:nil];
            dispatch_queue_t queue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0);
            dispatch_async(queue, ^{
                init();
                recordSound();
            });
        }
        else {
            NSLog(@"Permission denied");
        }
    }];
    
    if (_timer == nil)
        _timer = [NSTimer scheduledTimerWithTimeInterval:0.05 target:self selector:@selector(tick) userInfo:nil repeats:YES];
}

- (void)setPaused:(BOOL)p {
    setPause((bool)p);
}

- (void)clear {
    clearImagesAndRaws();
}

- (void)stop {
    stop();
    [_timer invalidate];
    _timer = nil;
}

bool matToPixelBuffer(cv::Mat mat, CVPixelBufferRef &pixelBuffer) {
    CVPixelBufferCreate(kCFAllocatorDefault, mat.cols, mat.rows, kCVPixelFormatType_OneComponent8, NULL, &pixelBuffer);
    
    size_t bufferWidth = CVPixelBufferGetWidth(pixelBuffer);
    size_t bufferHeight = CVPixelBufferGetHeight(pixelBuffer);
    size_t rowBytes = CVPixelBufferGetBytesPerRow(pixelBuffer);
    size_t pixelBytes = rowBytes/bufferWidth;
    
    CVPixelBufferLockBaseAddress(pixelBuffer, 0);
    unsigned char *base = (unsigned char *)
    CVPixelBufferGetBaseAddress(pixelBuffer);
    
    for ( int row = 0; row < bufferHeight; row++ ) {
        for ( int column = 0; column < bufferWidth; column++ ) {
            
            unsigned char *pixelAddress = (base + (row * rowBytes) +
            (column * pixelBytes));
            unsigned char p = mat.at<unsigned char>(row, column);
            *pixelAddress = p;
        }
    }
    
    return true;
}

- (void)tick {
    cv::Mat m;
    std::vector<int16_t> v;

    if (lastImageAndRaw(m, v) && self.ignoreToTime < [[NSDate date] timeIntervalSince1970]) {
        CVPixelBufferRef ref;
        matToPixelBuffer(m, ref);
        
        SpellingBeeInput *input = [[SpellingBeeInput alloc] initWithInput1:ref];
        NSError *error;
        SpellingBeeOutput *prediction = [_spellingBeeModel predictionFromFeatures:input error:&error];
                
        auto str = join(v,",");
        NSData *data = [NSData dataWithBytes:v.data() length:sizeof(int16_t)*v.size()];
        
        if (self.onMadeSound != nil) {
            if (self.onMadeSound(data, prediction.output1)) {
                self.ignoreToTime = [[NSDate date] timeIntervalSince1970] + self.secToIgnoreOnSuccess;
            }
        }
    }
}

- (void)dealloc {
    stop();
}

template <typename T>
std::string join(const T& v, const std::string& delim) {
    std::ostringstream s;
    for (const auto& i : v) {
        if (&i != &v[0]) {
            s << delim;
        }
        s << i;
    }
    return s.str();
}

-(void)uploadBlobToContainer: (NSString *)romaji withData:(NSData *)data {
    NSError *accountCreationError;
    
    // Create a storage account object from a connection string.
    AZSCloudStorageAccount *account = [AZSCloudStorageAccount accountFromConnectionString:@"DefaultEndpointsProtocol=https;AccountName=brutaljapanese;AccountKey=7W04u3TDzNie7B8wZboHNOflPhKcRrxfyF8Bx/7D21dSa9ewMQrAtYtSBc1blyMuUuUb8ffTcWy+JPSWlnD7WQ==;EndpointSuffix=core.windows.net" error:&accountCreationError];
    
    if(accountCreationError){
        NSLog(@"Error in creating account.");
    }
    
    // Create a blob service client object.
    AZSCloudBlobClient *blobClient = [account getBlobClient];
    
    // Create a local container object.
    AZSCloudBlobContainer *blobContainer = [blobClient containerReferenceFromName:[NSString stringWithFormat:@"raw-%@", romaji]];
    
    [blobContainer createContainerIfNotExistsWithAccessType:AZSContainerPublicAccessTypeContainer requestOptions:nil operationContext:nil completionHandler:^(NSError *error, BOOL exists)
     {
         if (error) {
             NSLog(@"Error in creating container.");
         }
         else {
             NSString *blobname = [[NSString stringWithFormat:@"%@",[[[NSUUID UUID] UUIDString] stringByReplacingOccurrencesOfString:@"-" withString:@""]] lowercaseString];
             
             // Create a local blob object
             AZSCloudBlockBlob *blockBlob = [blobContainer blockBlobReferenceFromName:blobname];
             
             // Upload blob to Storage
             [blockBlob uploadFromData:data completionHandler:^(NSError *error) {
                 if (error){
                     NSLog(@"Error in creating blob.");
                 }
             }];
         }
     }];
}

@end
