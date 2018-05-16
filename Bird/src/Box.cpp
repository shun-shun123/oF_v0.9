//
//  Box.cpp
//  Bird
//
//  Created by 斉藤俊介 on 2018/05/04.
//

#include "Box.hpp"

Box::Box() {
    int halfWidth = ofGetWidth() / 2;
    position = ofVec3f(ofRandom(-halfWidth, halfWidth), ofRandom(-halfWidth, halfWidth), ofRandom(-halfWidth * 2, 0));
    size = ofRandom(30, 100);
    color = ofFloatColor::fromHsb(ofRandom(1.0), 1.0, 1.0);
    box.setPosition(position);
    box.set(size);
}

Box::~Box() {
    cout << "Box destructor is called" << endl;
}

void Box::draw() {
    ofPushStyle();
    ofSetColor(color);
    box.draw();
    ofPopStyle();
}

ofVec3f Box::getPosition() {
    return position;
}

int Box::getSize() {
    return size;
}

ofFloatColor Box::getColor() {
    return color;
}
