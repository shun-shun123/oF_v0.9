//
//  Hotaru.hpp
//  Bird
//
//  Created by 斉藤俊介 on 2018/05/04.
//

#ifndef Hotaru_hpp
#define Hotaru_hpp

#include <stdio.h>
#include "ofMain.h"
#include "Box.hpp"

#endif /* Hotaru_hpp */

class Hotaru {
    public :
        Hotaru();
        void move(int state);
        ofVec3f getPosition();
        ofVec3f getVelocity();
        void applyForce(ofVec3f force);
        void hitBox(vector<Box>& box, ofVec3f _position);
    
    private :
        int halfWidth = ofGetWidth() / 2;
        void bound(ofVec3f position);
        ofSpherePrimitive hotaru;
        ofVec3f position;
        ofVec3f velocity;
        ofVec3f separate;
        ofVec3f alignForce;
        ofVec3f distance;
};
