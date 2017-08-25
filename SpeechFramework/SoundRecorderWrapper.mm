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

#import "SoundRecorder.hh"

@implementation SoundRecorderWrapper

- (instancetype)init {
    self = [super init];
    if (self) {
        // Create the data model.
        if (@available(iOS 11.0, *)) {
            _spellingBeeModel = [SpellingBee new];
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
                                             withOptions:(AVAudioSessionCategoryOptionDefaultToSpeaker | AVAudioSessionCategoryOptionDuckOthers)
                                                   error:nil];
            
            dispatch_queue_t queue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0);
            dispatch_async(queue, ^{
                recordSound();
            });
        }
        else {
            NSLog(@"Permission denied");
        }
    }];
    
    [NSTimer scheduledTimerWithTimeInterval:0.05 target:self selector:@selector(tick) userInfo:nil repeats:YES];
    
}

- (void)setPaused:(bool)p {
    setPause(p);
}

- (void)clear {
    clearImagesAndRaws();
}

- (void)stop {
    stop();
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

    if (lastImageAndRaw(m, v)) {
        CVPixelBufferRef ref;
        matToPixelBuffer(m, ref);
        
        SpellingBeeInput *input = [[SpellingBeeInput alloc] initWithInput1:ref];
        NSError *error;
        SpellingBeeOutput *prediction = [_spellingBeeModel predictionFromFeatures:input error:&error];
                
        auto str = join(v,",");
        NSData *data = [NSData dataWithBytes:v.data() length:sizeof(int16_t)*v.size()];
        
        if (self.onMadeSound != nil) {
            self.onMadeSound(data, prediction.output1);
        }
    }
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

@end
