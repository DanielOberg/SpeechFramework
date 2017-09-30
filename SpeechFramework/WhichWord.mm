//
//  WhichWord.m
//  SpellingBee
//
//  Created by Daniel Oberg on 2017-06-25.
//  Copyright © 2017 Daniel Oberg. All rights reserved.
//

#import "WhichWord.h"

#include <map>
#include <vector>

#include <boost/locale.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/lexical_cast.hpp>

#import <AZSClient/AZSClient.h>

#import "japanese.hh"

@implementation JapaneseWordNSObject
@synthesize hiragana;
@synthesize kanji;
@synthesize explanation;
@synthesize romaji;
@synthesize kanaArray;
@synthesize romajiArray;
@end


@implementation WhichWord

boost::locale::generator gen_;
std::vector<std::string> currentRomanjis_;
std::vector<std::string> currentKanas_;
JapaneseWord currentWord_;

@synthesize wordIndex;
@synthesize charIndex;
@synthesize points;

- (id)init {
    if ( self = [super init] ) {
        wordIndex = 0;
        charIndex = 0;
        currentWord_ = japaneseWords.at(0);
        
        auto word = japaneseWords.at(wordIndex);
        updateCurrentRomanjis(word);
        
        std::cout << std::endl << currentRomanjis_.at(charIndex) << std::endl;

        return self;
    }
    
    return nil;
}

- (void)update {
        charIndex = 0;
        currentWord_ = japaneseWords.at(wordIndex);
        
        auto word = japaneseWords.at(wordIndex);
        updateCurrentRomanjis(word);
}


template<typename A, typename B>
std::pair<B,A> flip_pair(const std::pair<A,B> &p)
{
    return std::pair<B,A>(p.second, p.first);
}

template<typename A, typename B>
std::map<B,A> flip_map(const std::map<const A, const B> &src)
{
    std::map<B,A> dst;
    transform(src.begin(), src.end(), inserter(dst, dst.begin()), flip_pair<A,B>);
    return dst;
}

std::vector<std::pair<std::string, std::string>> kanaListAll() {
    const auto hiraganaToRomaji = flip_map(romajiToHiragana);
    std::vector<std::pair<std::string, std::string>> hiraganaList;
    transform(hiraganaToRomaji.begin(), hiraganaToRomaji.end(), back_inserter(hiraganaList), [](const std::pair<std::string, std::string>& val){return val;} );
    std::sort(hiraganaList.begin(), hiraganaList.end(), [](const std::pair<std::string, std::string> & a, const std::pair<std::string, std::string> & b){ return a.first.size() > b.first.size(); });
    
    const auto katakanaToRomaji = flip_map(romajiToKatakana);
    std::vector<std::pair<std::string, std::string>> kanaList;
    transform(hiraganaList.begin(), hiraganaList.end(), back_inserter(kanaList), [](const std::pair<std::string, std::string>& val){return val;} );
    transform(katakanaToRomaji.begin(), katakanaToRomaji.end(), back_inserter(kanaList), [](const std::pair<std::string, std::string>& val){return val;} );
    
    std::sort(kanaList.begin(), kanaList.end(), [](const std::pair<std::string, std::string> & a, const std::pair<std::string, std::string> & b){ return a.first.size() > b.first.size(); });

    return kanaList;
}

void updateCurrentRomanjis(JapaneseWord word) {
    auto hiragana = word.hiragana;
    auto kanaList = kanaListAll();

    currentRomanjis_.clear();
    while (hiragana.size() > 0) {
        for(const auto &hiraganaCharacter : kanaList) {
            if (boost::starts_with(hiragana, hiraganaCharacter.first)) {
                const auto romanjiCharacter = hiraganaCharacter.second;
        
                currentRomanjis_.push_back(romanjiCharacter);
                currentKanas_.push_back(hiraganaCharacter.first);
        
                hiragana.erase(0, hiraganaCharacter.first.size());
                break;
            }
        }
    }
}

+ (NSArray<NSString*> *) kanaForIndex:(NSInteger) wordIndex {
    auto word = japaneseWords.at((wordIndex < 0) ? 0 : wordIndex);
    auto hiragana = word.hiragana;
    auto kanaList = kanaListAll();
    
    NSMutableArray *result = [NSMutableArray new];
    
    while (hiragana.size() > 0) {
        for(const auto &hiraganaCharacter : kanaList) {
            if (boost::starts_with(hiragana, hiraganaCharacter.first)) {
                [result addObject:[NSString stringWithUTF8String:hiraganaCharacter.first.c_str()]];
                
                hiragana.erase(0, hiraganaCharacter.first.size());
                break;
            }
        }
    }
    return result;
}

+ (NSArray<NSString*> *) romajiForIndex:(NSInteger) wordIndex {
    auto word = japaneseWords.at((wordIndex < 0) ? 0 : wordIndex);
    auto hiragana = word.hiragana;
    auto kanaList = kanaListAll();
    
    NSMutableArray *result = [NSMutableArray new];
    
    while (hiragana.size() > 0) {
        for(const auto &hiraganaCharacter : kanaList) {
            if (boost::starts_with(hiragana, hiraganaCharacter.first)) {
                [result addObject:[NSString stringWithUTF8String:hiraganaCharacter.second.c_str()]];
                
                hiragana.erase(0, hiraganaCharacter.first.size());
                break;
            }
        }
    }
    return result;
}

+ (NSArray<NSString*> *) kanaAllAvailable {
    NSMutableArray<NSString*> *mutableArray = [[NSMutableArray alloc] init];
    auto kanaList = kanaListAll();

    for(const auto &hiraganaCharacter : kanaList) {
        const auto kanaCharacter = hiraganaCharacter.first;
        [mutableArray addObject:[NSString stringWithUTF8String:kanaCharacter.c_str()]];
    }
    
    return mutableArray;
}

+ (NSArray<NSString*> *) romanjiAllAvailable {
    NSMutableArray<NSString*> *mutableArray = [[NSMutableArray alloc] init];
    auto kanaList = kanaListAll();
    
    for(const auto &hiraganaCharacter : kanaList) {
        const auto kanaCharacter = hiraganaCharacter.second;
        [mutableArray addObject:[NSString stringWithUTF8String:kanaCharacter.c_str()]];
    }
    
    return mutableArray;
}

- (NSString *) romanjiChar {
    return [NSString stringWithUTF8String:currentRomanjis_.at(charIndex).c_str()];
}

- (NSString *) kanaChar {
    auto romanji = currentRomanjis_.at(charIndex);
    return [NSString stringWithUTF8String:romajiToKatakana.at(romanji).c_str()];
}

- (JapaneseWordNSObject *) currentWord {
    return [self wordAtIndex:self.wordIndex];
}

- (JapaneseWordNSObject *) formerWord {
    return [self wordAtIndex:self.wordIndex-1];
}

- (JapaneseWordNSObject *) wordAtIndex:(NSInteger) wordIndex {
    wordIndex = (wordIndex < 0) ? 0 : wordIndex;
    auto word = japaneseWords.at(wordIndex);
    
    JapaneseWordNSObject *obj = [JapaneseWordNSObject new];
    obj.explanation = [NSString stringWithUTF8String:word.explanation.c_str()];
    obj.hiragana = [NSString stringWithUTF8String:word.hiragana.c_str()];
    obj.kanji = [NSString stringWithUTF8String:word.kanji.c_str()];
    obj.romaji = [NSString stringWithUTF8String:word.romaji.c_str()];
    obj.kanaArray = [WhichWord kanaForIndex:wordIndex];
    obj.romajiArray = [WhichWord romajiForIndex:wordIndex];
    
    return obj;
}

- (NSUInteger) getPoints {
    return points;
}

- (NSArray *) kanaCurrentWord {
    NSMutableArray<NSString*> *mutableArray = [[NSMutableArray alloc] init];
    auto kanaList = currentKanas_;
    
    for(const auto &kanaCharacter : kanaList) {
        [mutableArray addObject:[NSString stringWithUTF8String:kanaCharacter.c_str()]];
    }
    
    return mutableArray;
}

- (void)nextChar {
    points += 10;
    charIndex++;
    
    if (charIndex >= currentRomanjis_.size()) {
        wordIndex = (wordIndex + 1) % japaneseWords.size();
        auto word = japaneseWords.at(wordIndex);
        updateCurrentRomanjis(word);
        
        std::cout << std::endl << std::endl << "Your word is " << word.explanation << std::endl;

        charIndex = 0;
    }
    
    std::cout << std::endl << currentRomanjis_.at(charIndex) << std::endl;
}

-(void)uploadBlobToContainer: (NSString *)hiragana withData:(NSData *)data {
    NSError *accountCreationError;
    
    // Create a storage account object from a connection string.
    AZSCloudStorageAccount *account = [AZSCloudStorageAccount accountFromConnectionString:@"DefaultEndpointsProtocol=https;AccountName=brutaljapanese;AccountKey=7W04u3TDzNie7B8wZboHNOflPhKcRrxfyF8Bx/7D21dSa9ewMQrAtYtSBc1blyMuUuUb8ffTcWy+JPSWlnD7WQ==;EndpointSuffix=core.windows.net" error:&accountCreationError];
    
    if(accountCreationError){
        NSLog(@"Error in creating account.");
    }
    
    // Create a blob service client object.
    AZSCloudBlobClient *blobClient = [account getBlobClient];
    
    // Create a local container object.
    AZSCloudBlobContainer *blobContainer = [blobClient containerReferenceFromName:[NSString stringWithFormat:@"raw-%@", hiragana]];
    
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
