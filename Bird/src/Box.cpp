//
//  Box.cpp
//  Bird
//
//  Created by 斉藤俊介 on 2018/05/04.
//

#include "Box.hpp"

Box::Box() {
    position = ofVec3f(ofRandomWidth() * spread, ofRandomHeight() * spread, -ofRandomWidth() * spread);
    size = ofRandom(50, 150);
    color = ofColor::fromHsb(ofRandom(255), 255, ofRandom(200, 255));
}

void Box::set() {
    box.setPosition(position);
    box.set(size);
    ofPushStyle();
    ofSetColor(color);
    box.draw();
    ofPopStyle();
}

ofVec3f Box::getPosition() {
    return position;
}
