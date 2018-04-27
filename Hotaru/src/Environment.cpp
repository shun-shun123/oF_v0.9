//
//  Environment.cpp
//  ofxOpenNi_examples
//
//  Created by 斉藤俊介 on 2018/04/21.
//

#include "Environment.hpp"

Environment::Environment() {
    arduino.connect("/dev/cu.usbmodem14311", 57600);
    ofToggleFullscreen();
    for (int i = 0; i < PARTICLE_NUM; i++) {
        particles[i] = {ofRandom(3, 7), ofVec2f(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight())), ofVec2f(ofRandom(-2, 2), ofRandom(1, 3))};
    }
}

void Environment::setSeason() {
    ofPushStyle();
    ofSetColor(getSeason());
    updateFall();
    for (int i = 0; i < PARTICLE_NUM; i++) {
        ofDrawCircle(particles[i].pos, particles[i].size);
    }
    ofPopStyle();
}

float Environment::arduinoTemparature() {
    arduino.update();
    int analog = arduino.getAnalog(0);
    float temparature = calcTemparature(analog);
    return temparature;
}

float Environment::convertAnalogToDigital(int analog) {
    float digital = analog * (5.0 / 1023.0);
    return digital;
}

float Environment::calcTemparature(int analog) {
    float digital = convertAnalogToDigital(analog);
    float temparature = digital * 100;
    
    // temparatureの上限下限を設定する処理
    if (temparature < -10) {
        temparature = 10;
    }
    if (temparature > 50) {
        temparature = 50;
    }
    
    return temparature;
}

ofColor Environment::getSeason() {
    float hue = ofMap(arduinoTemparature(), -10, 50, 40, 170);
    ofColor color = ofColor::fromHsb(hue, 255, 255);
    ofDrawBitmapString(hue, 50, 50);
    ofDrawBitmapString(ofGetFrameRate(), 50, 100);
    return color;
}

void Environment::updateFall() {
    for (int i = 0; i < PARTICLE_NUM; i++) {
        particles[i].pos += particles[i].vel;
        if (particles[i].pos.x < 0) {
            particles[i].pos.x = ofGetWidth();
        }
        if (particles[i].pos.x > ofGetWidth()) {
            particles[i].pos.x = 0;
        }
        if (particles[i].pos.y > ofGetHeight()) {
            particles[i].pos.y = 0;
        }
    }
}
