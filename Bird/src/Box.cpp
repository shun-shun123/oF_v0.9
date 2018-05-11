//
//  Box.cpp
//  Bird
//
//  Created by 斉藤俊介 on 2018/05/04.
//

#include "Box.hpp"

Box::Box() {
    int halfWidth = ofGetWidth() / 2;
    this->position = ofVec3f(ofRandom(-halfWidth, halfWidth), ofRandom(-halfWidth, halfWidth), ofRandom(-halfWidth * 2, 0));
    this->size = ofRandom(30, 100);
    this->color = ofColor::fromHsb(ofRandom(255), 255, 255);
    box.setPosition(this->position);
    box.set(this->size);
}

void Box::draw() {
    ofPushStyle();
    ofSetColor(color);
    box.draw();
    ofPopStyle();
}

ofVec3f Box::getPosition() {
    return this->position;
}

int Box::getSize() {
    return this->size;
}

ofColor Box::getColor() {
    return this->color;
}
