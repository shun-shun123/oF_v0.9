//
//  Box.hpp
//  Bird
//
//  Created by 斉藤俊介 on 2018/05/04.
//

#ifndef Box_hpp
#define Box_hpp

#include <stdio.h>
#include "ofMain.h"
#endif /* Box_hpp */

class Box {
    public :
        Box();
        void set();
        ofVec3f getPosition();
    private :
        ofBoxPrimitive box;
        ofVec3f position;
        ofVec3f middle;
        ofColor color;
        int size;
        static const int spread = 2;
};
