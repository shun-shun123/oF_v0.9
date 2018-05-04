//
//  Hotaru.cpp
//  Bird
//
//  Created by 斉藤俊介 on 2018/05/04.
//

#include "Hotaru.hpp"

Hotaru::Hotaru() {
    position = ofVec3f(ofRandomWidth(), ofRandomHeight(), -ofRandomWidth());
    velocity = ofVec3f(ofRandom(-5, 5), ofRandom(-5, 5), ofRandom(-5, 5));
}

void Hotaru::move() {
    bound(position);
    position += velocity;
    hotaru.setPosition(position);
//    hotaru.set(100, 30);
//    hotaru.drawWireframe();
}

void Hotaru::bound(ofVec3f position) {
    if (position.x < 0 || position.x > ofGetWidth() * 2) {
        velocity.x *= -1;
    }
    if (position.y < 0 || position.y > ofGetHeight() * 2) {
        velocity.y *= -1;
    }
    if (position.z > ofGetWidth() * 2 || position.z < 0) {
        velocity.z *= -1;
    }
}

ofVec3f Hotaru::getPosition() {
    return this->position;
}
