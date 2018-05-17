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
        ~Particle();
        Particle(ofVec3f _position, ofColor _color);
        void setup();
        void draw();
        void flow();
        bool check();
        void align(ofImage img, int row);
    private :
        vector<ofImage> textures;
        static const int NUM = 50;
        ofVec3f startPos;
        ofVec3f friction = ofVec3f(0.97, 0.97, 0.97);
        bool isThreshold = false;
    protected :
        ofVbo vbo;
        ofVec3f verts[NUM];
        ofFloatColor colors[NUM];
        ofVec3f normals[NUM];
        ofShader mPointSprite;
        void update();
        ofVec3f velocity[NUM];
};
