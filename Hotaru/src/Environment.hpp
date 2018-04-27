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
        ofColor getSeason();
        ofArduino arduino;
        struct Particle {
            float size;
            ofVec2f pos;
            ofVec2f vel;
        };
        static const int PARTICLE_NUM = 15;
        Particle particles[PARTICLE_NUM];
};
