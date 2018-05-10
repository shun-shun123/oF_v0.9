//
//  SceneHotaru.cpp
//  Bird
//
//  Created by 斉藤俊介 on 2018/05/09.
//

#include "SceneHotaru.hpp"

void SceneHotaru::setup() {
    ofBackground(0);
    ofSetVerticalSync(true);
    ofSetDepthTest(true);
    
    myFbo.allocate(ofGetWidth(), ofGetWidth());
    myGlitch.setup(&myFbo);
    myGlitch.setFx(OFXPOSTGLITCH_GLOW, true);
    
    hotaru.push_back(Hotaru());
    
    for (int i = 0; i < NUM; i++) {
        box.push_back(Box());
        middle += box[i].getPosition();
    }
    middle /= (float)NUM;
}

void SceneHotaru::update() {
    cout << box.size() << endl;
    myFbo.begin();
    ofClear(0);
    switch (state) {
        case 0 :
            camera.setPosition(box[index].getPosition());
            camera.lookAt(hotaru[0].getPosition());
            break;
        case 1 :
            camera.setPosition(hotaru[0].getPosition());
            camera.lookAt(hotaru[0].getVelocity() * 2.0);
            break;
        case 2 :
            camera.setPosition(0, ofGetWidth() * 2, ofGetWidth());
            camera.lookAt(ofVec3f(0, 0, 0));
            break;
    }
//    updateForce();
    camera.begin();
    for (int i = 0; i < box.size(); i++) {
        if (index == i) {
            continue;
        }
        box[i].connect(box, i);
        box[i].draw();
    }
    for (int i = 0; i < hotaru.size(); i++) {
        hotaru[i].move(state);
    }
    camera.end();
    myFbo.end();
    hotaru[0].hitBox(box, hotaru);
}

void SceneHotaru::draw() {
//    myGlitch.generateFx();
    myFbo.draw(0, 0);
}

//void SceneHotaru::updateForce() {
//    int count = 0;
//    for (int i = 0; i < box.size(); i++) {
//        if (hotaru.getPosition().distance(box[i].getPosition()) <= 50.0) {
//            force += hotaru.getPosition();
//            count++;
//        }
//    }
//    force /= count;
//    hotaru.applyForce(force);
//}

void SceneHotaru::keyPressed(int key) {
    switch (key) {
        case '2' :
            state = 2;
            break;
        case '1' :
            state = 1;
            index = (int)ofRandom(box.size());
            break;
        case '0' :
            state = 0;
            break;
    }
}
