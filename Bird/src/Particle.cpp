//
//  Particle.cpp
//  Bird
//
//  Created by 斉藤俊介 on 2018/05/11.
//

#include "Particle.hpp"

Particle::Particle() {
    Particle(ofVec3f(0, 0, 0), ofColor::fromHsb(0, 0, 0));
}

Particle::Particle(ofVec3f _position, ofColor _color) {
    this->position = _position;
    this->startPos = _position;
    this->color = _color;
    this->velocity = ofVec3f(ofRandom(-3, 3), ofRandom(5), ofRandom(-3, 3));
    particle.setPosition(_position);
    particle.set(ofRandom(1, 3), 10);
}

void Particle::flow() {
    update();
    ofPushStyle();
    ofSetColor(color);
    particle.draw();
    ofPopStyle();
}

void Particle::stay() {
    ofPushStyle();
    ofSetColor(color);
    particle.draw();
    ofPopStyle();
}

void Particle::update() {
    position += velocity;
    particle.setPosition(position);
    if (startPos.distance(position) >= 200) {
        isThreshold = true;
    }
}

bool Particle::check() {
    return isThreshold;
}
