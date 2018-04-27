//
//  Environment.cpp
//  ofxOpenNi_examples
//
//  Created by 斉藤俊介 on 2018/04/21.
//

#include "Environment.hpp"

#define MIN_TEMPARATURE 20
#define MAX_TEMPARATURE 30

Environment::Environment() {
    arduino.connect("/dev/cu.usbmodem14311", 57600);
    ofToggleFullscreen();
    for (int i = 0; i < PARTICLE_NUM; i++) {
        particleSize[i] = ofRandom(3, 5);
        particlePos[i] = ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
        particleVel[i] = ofVec2f(ofRandom(-3, 3), ofRandom(1, 3));
        particleColor[i].setHsb(0.5, 1.0, 1.0);
    }
    particleVbo.setVertexData(particlePos, PARTICLE_NUM, GL_DYNAMIC_DRAW);
    particleVbo.setColorData(particleColor, PARTICLE_NUM, GL_DYNAMIC_DRAW);
    glPointSize(4.0);
}

void Environment::setSeason() {
    ofPushStyle();
    updateFall();
    particleVbo.draw(GL_POINTS, 0, PARTICLE_NUM);
    ofPopStyle();
    ofDrawBitmapString(ofGetFrameRate(), 50, 100);
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
    if (temparature < MIN_TEMPARATURE) {
        temparature = MIN_TEMPARATURE;
    }
    if (temparature > MAX_TEMPARATURE) {
        temparature = MAX_TEMPARATURE;
    }
    
    return temparature;
}

ofFloatColor* Environment::getSeason() {
    float hue = ofMap(arduinoTemparature(), MIN_TEMPARATURE, MAX_TEMPARATURE, 40.0 / 255.0, 170.0 / 255.0);
    for (int i = 0; i < PARTICLE_NUM; i++) {
        particleColor[i] = ofFloatColor::fromHsb(hue, 1.0, 1.0);
    }
    return particleColor;
}

void Environment::updateFall() {
    for (int i = 0; i < PARTICLE_NUM; i++) {
        particlePos[i] += particleVel[i];
//        if (particlePos[i].x < 0) {
//            particlePos[i].x = ofGetWidth();
//        }
//        if (particlePos[i].x > ofGetWidth()) {
//            particlePos[i].x = 0;
//        }
        if (particlePos[i].y > ofGetHeight()) {
            particlePos[i].y = 0;
        }
    }
    particleVbo.updateVertexData(particlePos, PARTICLE_NUM);
    particleVbo.updateColorData(getSeason(), PARTICLE_NUM);
    ofDrawBitmapString(particleColor[0].getHue(), 50, 50);
}
