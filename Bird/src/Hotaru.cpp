//
//  Hotaru.cpp
//  Bird
//
//  Created by 斉藤俊介 on 2018/05/04.
//

#include "Hotaru.hpp"

Hotaru::Hotaru() {
    
    this->position = ofVec3f(ofRandom(-halfWidth, halfWidth), ofRandom(-halfWidth, halfWidth), ofRandom(-halfWidth * 2, 0));
    this->velocity = ofVec3f(ofRandom(-5.0, 5.0), ofRandom(-5.0, 5.0), ofRandom(-5.0, 5.0));
    this->size = 50;
}

Hotaru::Hotaru(int _size) {
    this->position = ofVec3f(ofRandom(-halfWidth, halfWidth), ofRandom(-halfWidth, halfWidth), ofRandom(-halfWidth * 2, 0));
    this->velocity = ofVec3f(ofRandom(-5.0, 5.0), ofRandom(-5.0, 5.0), ofRandom(-5.0, 5.0));
    this->size = _size;
}

void Hotaru::applyForce(ofVec3f force) {
    velocity += force;
}

void Hotaru::move(int state) {
    bound(position);
    position += velocity;
    hotaru.setPosition(position);
    if (state != 1) {
        hotaru.set(size, 30);
        hotaru.draw();
    }
    for (int i = 0; i < particles.size(); i++) {
        if (particles[i].check())
            particles[i].stay();
        else
            particles[i].flow();
    }
}

void Hotaru::hitBox(vector<Box>& box, ofVec3f hotaruPos) {
    for (int j = 0; j < box.size(); j++) {
        if (position.distance(box[j].getPosition()) <= box[j].getSize() + 25) {
            particles.push_back(Particle(box[j].getPosition(), box[j].getColor()));
            particles[particles.size() - 1].setup();
            box.erase(box.begin() + j);
            break;
        }
    }
}

void Hotaru::bound(ofVec3f position) {
    int halfWidth = ofGetWidth() / 2;
    if (position.x <= -halfWidth || position.x >= halfWidth) {
        velocity.x *= -1.0;
    }
    if (position.y <= -halfWidth || position.y >= halfWidth) {
        velocity.y *= -1.0;
    }
    if (position.z >= 0 || position.z <= -halfWidth * 2) {
        velocity.z *= -1.0;
    }
}

ofVec3f Hotaru::getPosition() {
    return this->position;
}

ofVec3f Hotaru::getVelocity() {
    return this->velocity;
}

int Hotaru::getSize() {
    return this->size;
}
