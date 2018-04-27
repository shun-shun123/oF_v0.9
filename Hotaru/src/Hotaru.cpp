//
//  Hotaru.cpp
//  ofxOpenNi_examples
//
//  Created by 斉藤俊介 on 2018/04/16.
//

#include "Hotaru.hpp"

Hotaru::Hotaru() {
    pos = ofVec2f(ofRandom(0, ofGetWidth()), ofRandom(400, ofGetHeight() - 400));
    yRatio[0] = ofRandom(0.0005, 0.001);
    yRatio[1] = ofRandom(0.001, 0.002);
    yRatio[2] = ofRandom(0.002, 0.003);
    vel = ofVec2f(ofRandom(1.0, 3.0), 0);
    for (int i = 0; i < 4; i++) {
        hotaru[i].load("hotaru.png");
    }
    spark[0] = ofRandom(500, 1000);
    spark[1] = ofRandom(1000, 1400);
    spark[2] = ofRandom(1000, 1600);
    sound.load("鈴虫の音.mp3");
    sound.setVolume(0.4);
    sound.setLoop(true);
}

void Hotaru::update() {
    // sinの合成で上下に少し乱れた動きをする
    pos.y += sin(yRatio[0] * ofGetElapsedTimeMillis()) * 1.5 + sin(yRatio[1] * ofGetElapsedTimeMillis()) * 1.5 + sin(yRatio[2] * ofGetElapsedTimeMillis());
    pos += vel;
    if (pos.x >= ofGetWidth()) {
        pos.x = 0;
    }
    if (pos.y < 0) {
        pos.y = ofGetHeight();
    }
    if (pos.y > ofGetHeight()) {
        pos.y = 0;
    }
}

void Hotaru::move() {
    for (int i = 0; i < 4; i++) {
        hotaru[i].draw(pos);
    }
    // 以下は発光の周期
    if (ofGetElapsedTimeMillis() % 1000 >= spark[0]) {
        for (int i = 0; i < 4; i++) {
            hotaru[i].draw(pos);
        }
    }
    if (ofGetElapsedTimeMillis() % 1200 >= spark[1]) {
        for (int i = 0; i < 4; i++) {
            hotaru[i].draw(pos);
        }
    }
    if (ofGetElapsedTimeMillis() % 1400 >= spark[2]) {
        for (int i = 0; i < 4; i++) {
            hotaru[i].draw(pos);
        }
    }
}

void Hotaru::cry() {
    sound.play();
}

void Hotaru::setPan(float pan) {
    sound.setPan(pan);
}
