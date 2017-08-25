//
//  WhichWord.h
//  SpellingBee
//
//  Created by Daniel Oberg on 2017-06-25.
//  Copyright © 2017 Daniel Oberg. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface JapaneseWordNSObject : NSObject
@property NSString * hiragana;
@property NSString * kanji;
@property NSString * explanation;
@property NSString * romaji;
@end


@interface WhichWord : NSObject

- (id)init;
- (void)update;
- (void)nextChar;

- (JapaneseWordNSObject *) currentWord;
- (JapaneseWordNSObject *) formerWord;

- (NSString *) romanjiChar;
- (NSString *) kanaChar;

@property NSUInteger wordIndex;
@property NSUInteger charIndex;
@property NSUInteger points;

-(void)uploadBlobToContainer: (NSString *)hiragana withData:(NSData *)dataStr;
@end
