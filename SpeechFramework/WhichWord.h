//
//  WhichWord.h
//  SpellingBee
//
//  Created by Daniel Oberg on 2017-06-25.
//  Copyright © 2017 Daniel Oberg. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface JapaneseWordNSObject : NSObject
@property (strong, nonatomic) NSString * hiragana;
@property (strong, nonatomic) NSString * kanji;
@property (strong, nonatomic) NSString * explanation;
@property (strong, nonatomic) NSString * romaji;
@property (strong, nonatomic) NSArray * romajiArray;
@property (strong, nonatomic) NSArray * kanaArray;
@end


@interface WhichWord : NSObject

- (id)init;
- (void)update;
- (void)nextChar;

- (JapaneseWordNSObject *) currentWord;
- (JapaneseWordNSObject *) formerWord;

- (NSString *) romanjiChar;
- (NSString *) kanaChar;
- (NSArray *) kanaCurrentWord;

+ (NSArray *) kanaAllAvailable;
+ (NSArray *) romanjiAllAvailable;

@property NSInteger wordIndex;
@property NSInteger charIndex;
@property NSInteger points;

-(void)uploadBlobToContainer: (NSString *)hiragana withData:(NSData *)dataStr;
@end
