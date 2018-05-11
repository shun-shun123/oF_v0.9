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
        void flow();
        bool check();
        void stay();
    private :
        void update();
        ofSpherePrimitive particle;
        ofVec3f startPos;
        ofVec3f position;
        ofColor color;
        ofVec3f velocity;
        bool isThreshold;
};
