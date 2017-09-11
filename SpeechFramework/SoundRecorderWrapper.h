//
//  SoundRecorderWrapper.h
//  SpellingBee
//
//  Created by Daniel Oberg on 2017-06-24.
//  Copyright © 2017 Daniel Oberg. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class SpellingBee;

@interface SoundRecorderWrapper : NSObject
@property (weak, nonatomic) UIImageView *imageView;
@property (weak, nonatomic) UILabel *mostLikelyClass;

@property (strong, nonatomic) SpellingBee *spellingBeeModel;

@property (assign, nonatomic) double secToIgnoreOnSuccess;
@property (assign, nonatomic) double ignoreToTime;

@property (nonatomic, copy) BOOL (^onMadeSound)(NSData *, NSDictionary *probabilities);

- (void)checkForPermissionAndStart;
- (void)clear;
- (void)setPaused:(BOOL)p;
- (void)stop;
- (void)dealloc;
@end

