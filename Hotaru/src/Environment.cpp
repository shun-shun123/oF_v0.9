//
//  Environment.cpp
//  ofxOpenNi_examples
//
//  Created by 斉藤俊介 on 2018/04/21.
//

#include "Environment.hpp"

Environment::Environment() {
    arduino.connect("/dev/cu.usbmodem14311", 57600);
    arduino.sendDigitalPinMode(10, ARD_OUTPUT);
}

void Environment::setSeason() {
    // Todo シーズンを描画する関数を選択する
    float temparature = arduinoTemparature();
    if (temparature <= 30 && temparature >= 20) {
        spring();
    } else if (temparature > 30) {
        summer();
    } else if (temparature < 20 && temparature >= 10) {
        autumn();
    } else {
        winter();
    }
}

float Environment::arduinoTemparature() {
    arduino.update();
    float digital = arduino.getAnalog(0);
    return digital;
}

void Environment::spring() {
    ofSetColor(ofColor::fromHsb(100, 255, 255, 100));
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
}

void Environment::summer() {
    ofSetColor(ofColor::fromHsb(150, 255, 255, 100));
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
}

void Environment::autumn() {
    ofSetColor(ofColor::fromHsb(200, 255, 255, 100));
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
}

void Environment::winter() {
    ofSetColor(ofColor::fromHsb(255, 255, 255, 100));
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
}
