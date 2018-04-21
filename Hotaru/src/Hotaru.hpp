//
//  Hotaru.hpp
//  ofxOpenNi_examples
//
//  Created by 斉藤俊介 on 2018/04/16.
//

#ifndef Hotaru_hpp
#define Hotaru_hpp

#include <stdio.h>
#include "ofMain.h"

#endif /* Hotaru_hpp */
class Hotaru {
    public :
        Hotaru();
        void move();
        void update();
    protected :
        void stop();
        void fly();
        void shine();
        ofImage hotaru[4];
        ofVec2f pos, vel;
        float yRatio[3];
        float spark[3];
};
