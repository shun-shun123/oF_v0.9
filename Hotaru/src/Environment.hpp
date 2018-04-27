//
//  Environment.hpp
//  ofxOpenNi_examples
//
//  Created by 斉藤俊介 on 2018/04/21.
//

#ifndef Environment_hpp
#define Environment_hpp

#include <stdio.h>
#include "ofMain.h"

#endif /* Environment_hpp */

//#define PARTICLE_NUM = 100

class Environment {
    public :
        Environment();
        void setSeason();
    private :
        float arduinoTemparature();
        float convertAnalogToDigital(int analog);
        float calcTemparature(int analog);
        void updateFall();
        ofFloatColor* getSeason();
        ofArduino arduino;
        static const int PARTICLE_NUM = 50;
        float particleSize[PARTICLE_NUM];
        ofVec2f particlePos[PARTICLE_NUM];
        ofVec2f particleVel[PARTICLE_NUM];
        ofFloatColor particleColor[PARTICLE_NUM];
        ofVbo particleVbo;
};
