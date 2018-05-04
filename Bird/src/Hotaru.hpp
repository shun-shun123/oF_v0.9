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

#endif /* Hotaru_hpp */

class Hotaru {
    public :
        Hotaru();
        void move();
        ofVec3f getPosition();
    private :
        void bound(ofVec3f position);
        ofSpherePrimitive hotaru;
        ofVec3f position;
        ofVec3f velocity;
        ofVec3f separate;
};
