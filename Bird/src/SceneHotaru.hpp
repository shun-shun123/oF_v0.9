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
#include "ofxPostGlitch.h"

#define NUM 30

#endif /* SceneHotaru_hpp */

class SceneHotaru : public ofBaseApp {
    public :
        void setup();
        void update();
        void draw();
        void keyPressed(int key);
        void connectBox(vector<Box> box);
        void updateForce();
    private :
        ofFbo myFbo;
        ofxPostGlitch myGlitch;
        ofCamera camera;
        vector<Box> box;
        Hotaru hotaru;
        vector<Particle> particles;
        int state = 1;
        int index = 0;
        ofVec3f force;
        ofVec3f middle;
        Particle particle;
    
        // vertex data for connectBox
        ofVec3f boxVerts[NUM];
        ofVbo myVbo;
};
