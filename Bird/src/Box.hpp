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
        void draw();
        void connect(vector<Box> box, int myIndex);
        ofVec3f getPosition();
        int getSize();
    private :
        ofBoxPrimitive box;
        ofVec3f position;
        ofColor color;
        int size;
};
