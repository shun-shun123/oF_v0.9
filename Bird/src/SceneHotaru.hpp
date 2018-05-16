//
//  SceneHotaru.hpp
//  Bird
//
//  Created by 斉藤俊介 on 2018/05/09.
//

#ifndef SceneHotaru_hpp
#define SceneHotaru_hpp

#include <stdio.h>
#include "ofMain.h"
#include "Hotaru.hpp"

#define NUM 30

#endif /* SceneHotaru_hpp */

class SceneHotaru : public ofBaseApp {
    public :
        ~SceneHotaru();
        void setup();
        void update();
        void draw();
        void keyPressed(int key);
        void connectBox(vector<Box *> box);
        void initialize();
        bool getFinish();
        vector<Particle *> getParticles();
    private :
        vector<Box *> box;
        ofFbo myFbo;
        ofCamera camera;
        Hotaru hotaru;
        int state = 1;
        int index = 0;
        ofVec3f tmpPos;
        ofVec3f middle;
        ofLight light;
        bool isFinished = false;
};
