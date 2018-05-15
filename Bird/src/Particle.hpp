//
//  Particle.hpp
//  Bird
//
//  Created by 斉藤俊介 on 2018/05/11.
//

#ifndef Particle_hpp
#define Particle_hpp

#include <stdio.h>
#include "ofMain.h"

#endif /* Particle_hpp */

class Particle {
    public :
        Particle();
        Particle(ofVec3f _position, ofColor _color);
        void setup();
        void draw();
        void flow();
        bool check();
        void stay();
    private :
        vector<ofImage> textures;
        static const int NUM = 100;
        ofVbo vbo;
        ofVec3f verts[NUM];
        ofFloatColor colors[NUM];
        ofVec3f normals[NUM];
        ofShader mPointSprite;
        void update();
        ofVec3f startPos;
        ofVec3f position;
        ofColor color;
        ofVec3f velocity[NUM];
        bool isThreshold = false;
};
