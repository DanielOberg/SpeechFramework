//
//  SoundRecorder.h
//  SpellingBee
//
//  Created by Daniel Oberg on 2017-06-24.
//  Copyright © 2017 Daniel Oberg. All rights reserved.
//

// To listen use /Applications/VLC.app/Contents/MacOS/VLC --demux=rawaud --rawaud-channels 1 --rawaud-samplerate 44100

#ifndef SoundRecorder_h
#define SoundRecorder_h

#include <vector>

#include <opencv2/core.hpp>
    
int recordSound();
bool lastImageAndRaw(cv::Mat &image, std::vector<int16_t> &data);
void clearImagesAndRaws();
void setPause(bool pause);
void stop();
void init();

#endif /* SoundRecorder_h */
