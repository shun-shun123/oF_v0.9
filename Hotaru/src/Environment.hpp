//
//  Environment.hpp
//  ofxOpenNi_examples
//
//  Created by 斉藤俊介 on 2018/04/21.
//

#ifndef Environment_hpp
#define Environment_hpp

#include <stdio.h>
#include "ofMain.h"

#endif /* Environment_hpp */
class Environment {
    public :
        Environment();
        void setSeason();
    private :
        float arduinoTemparature();
        void spring();
        void summer();
        void autumn();
        void winter();
        ofArduino arduino;
};
