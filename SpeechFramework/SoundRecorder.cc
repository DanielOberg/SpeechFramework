//
//  SoundRecorder.m
//  SpellingBee
//
//  Created by Daniel Oberg on 2017-06-24.
//  Copyright © 2017 Daniel Oberg. All rights reserved.
//

#include "SoundRecorder.hh"

#include <algorithm>
#include <cstddef>
#include <map>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <unordered_set>
#include <vector>
#include <string>
#include <thread>
#include <iostream>
#include <chrono>

#include <OpenAL/al.h>
#include <OpenAL/alc.h>
#include <glob.h>

#include <boost/lockfree/spsc_queue.hpp>

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/ml.hpp>

#include "aquila/aquila.h"
#include "aquila/source/FramesCollection.h"
#include "aquila/transform/Mfcc.h"
#include "aquila/source/WaveFile.h"


const int SRATE = 44100;
const int SSIZE = 44100*0.4; //1024;

boost::lockfree::spsc_queue<std::tuple<cv::Mat, std::vector<int16_t> > > imagesAndRaws{40};
static bool isPaused = false;
static bool shouldStop = false;
static bool isRunning = false;

void init() {
    isPaused = false;
    shouldStop = false;
}

void setPause(bool p) {
    isPaused = p;
}

bool lastImageAndRaw(cv::Mat &image, std::vector<int16_t> &data) {
    std::tuple<cv::Mat, std::vector<int16_t> > result;
    bool isOk = imagesAndRaws.pop(result);
    image = std::get<0>(result);
    data = std::get<1>(result);
    return isOk;
}

void clearImagesAndRaws() {
    for (int i=0; i<10; i++)
        imagesAndRaws.pop();
}

bool isSilence(const cv::Mat &img) {
    double min, max;
    cv::Point minLoc;
    cv::Point maxLoc;
    cv::minMaxLoc(img, &min, &max, &minLoc, &maxLoc);
//    std::cout << max << std::endl;
    
    if (maxLoc.x > 75)
        return true;
    
    bool silence = max < 0.80;
    return silence;
}

bool soundToImage(Aquila::SignalSource buffer, cv::Mat &resultingImage) {
    uint16_t FRAME_SIZE = 128; // 44100 / 100; // 44100 samples per second
    uint16_t MFCCS = 12;
    const int MAX_WIDTH = 100;

    
    Aquila::FramesCollection frames(buffer, FRAME_SIZE);
    Aquila::Mfcc mfcc(FRAME_SIZE);
    
    cv::Mat1f mfccMat(0, MFCCS);
    
    for (const Aquila::Frame& frame : frames) {
        auto mfccValues = mfcc.calculate(frame, MFCCS);
        
        auto firstMfccs = std::vector<double>(mfccValues.begin(), mfccValues.begin()+MFCCS);
        
        cv::Mat1f row = cv::Mat1f::zeros(1, MFCCS);
        
        for (int i = 0; i < MFCCS; i++) {
            row.col(i) = firstMfccs.at(i);
        }
        mfccMat.push_back(row);
    }
    mfccMat = mfccMat.t();
    
    if (isSilence(mfccMat(cv::Rect(0,0,MAX_WIDTH,mfccMat.rows)))) {
        return false;
    }
    
    cv::Mat1f normalized;
    cv::normalize(mfccMat, normalized, 0, 1, cv::NORM_MINMAX);
    
    cv::Mat1f deltaMfccs(normalized.rows, normalized.cols);
    {
        for (int r = 0; r < normalized.rows; r++) {
            for (int c = 0; c < normalized.cols; c++) {
                int h = (c - 1 == -1)? c : c - 1;
                int j = (c + 1 == normalized.cols)? c : c + 1;
                
                double result = (normalized[r][j] - normalized[r][h]);
                deltaMfccs[r][c] = result;
            }
        }
    }
    cv::normalize(deltaMfccs, deltaMfccs, 0, 1, cv::NORM_MINMAX);
    
    cv::Mat1f deltaDeltaMfccs(deltaMfccs.rows, deltaMfccs.cols);
    {
        for (int r = 0; r < deltaMfccs.rows; r++) {
            for (int c = 0; c < deltaMfccs.cols; c++) {
                int h = (c - 1 == -1)? c : c - 1;
                int j = (c + 1 == deltaMfccs.cols)? c : c + 1;
                
                double result = (deltaMfccs[r][j] - deltaMfccs[r][h]);
                deltaDeltaMfccs[r][c] = result;
            }
        }
    }
    cv::normalize(deltaDeltaMfccs, deltaDeltaMfccs, 0, 1, cv::NORM_MINMAX);
    
    cv::Mat concatenated;
    
    cv::vconcat(normalized, deltaMfccs, concatenated);
    cv::vconcat(concatenated, deltaDeltaMfccs, concatenated);
    
    int xmin = mfccMat.cols - 1;
    int xmax = 0;
    for (int x = 0; x < mfccMat.cols; x++) {
        for (int y = 0; y < mfccMat.rows; y++) {
            auto pixel = mfccMat[y][x];
            
            if (pixel > 0.3) {
                if (x < xmin) {
                    xmin = x;
                }
                if (x > xmax) {
                    xmax = x;
                }
            }
        }
    }
    
    if (xmin + 3 >= xmax) {
        xmin = 0;
        xmax = mfccMat.cols - 1;
    }
    
    
//    if (xmax-xmin > MAX_WIDTH)
//        xmax = xmin + MAX_WIDTH;
    
    xmax = MAX_WIDTH;
    xmin = 0;
    
    cv::Mat out = cv::Mat::zeros(concatenated.rows, MAX_WIDTH, concatenated.type());
    concatenated(cv::Rect(xmin,0, xmax - xmin,concatenated.rows)).copyTo(out(cv::Rect(0,0, xmax - xmin,concatenated.rows)));
    
    cv::Mat grayImage;
    out.convertTo(grayImage, CV_8U, 255.0);
    
    resultingImage = grayImage;
    return true;
}

void stop() {
    shouldStop = true;
}

int recordSound() {
    if (isRunning)
        return 0;
    
    isRunning = true;
    imagesAndRaws.reset();
    
    alGetError();
    ALCdevice *device = alcCaptureOpenDevice(nullptr, SRATE, AL_FORMAT_MONO16, SSIZE);
    if (alGetError() != AL_NO_ERROR || !device) {
        isRunning = false;
        isPaused = false;
        shouldStop = false;
        
        return 0;
    }
    alcCaptureStart(device);
    if (alGetError() != AL_NO_ERROR || !device) {
        isRunning = false;
        isPaused = false;
        shouldStop = false;
        
        return 0;
    }
    std::vector<int16_t> big_buffer;

    while (shouldStop == false) {
        while (isPaused && !shouldStop)
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        
        ALint samples_available;
        alcGetIntegerv(device, ALC_CAPTURE_SAMPLES, (ALCsizei)sizeof(ALint), &samples_available);
        if (samples_available > 0)
        {
            std::vector<int16_t> buffer_int16;

            buffer_int16.resize(samples_available);
            
            alcCaptureSamples(device, &buffer_int16[0], samples_available);
            
            big_buffer.insert(big_buffer.end(), buffer_int16.begin(), buffer_int16.end());
            
            while (big_buffer.size() >= SSIZE) {
                std::vector<double> buffer_double;

                buffer_double.resize(SSIZE);
                for (int i=0; i < SSIZE; i++)
                    buffer_double[i] = ((double)big_buffer[i]) / INT16_MAX;
                
                Aquila::SignalSource signalSource(buffer_double, SRATE);
                cv::Mat img;
                auto isOk = soundToImage(signalSource, img);

                if (isOk) {
                    imagesAndRaws.push(std::make_tuple(img, big_buffer));
                }
                
                big_buffer.erase(big_buffer.begin(), big_buffer.begin() + (SSIZE / 6));
            }
        }
    }
    
    alcCaptureStop(device);
    alcCaptureCloseDevice(device);
    
    isRunning = false;
    isPaused = false;
    shouldStop = false;
    return 0;
}
