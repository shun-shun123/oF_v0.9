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
    
    for (int i = 0; i < NUM; i++) {
        box.push_back(Box());
        middle += box[i].getPosition();
    }
    middle /= (float)NUM;
    
    light.enable();
    light.setPointLight();
    light.setPosition(hotaru.getPosition());
    // 鏡面反射光の色
    light.setSpecularColor(ofFloatColor(1.0, 1.0, 1.0));
    // 拡散反射光の色
    light.setDiffuseColor(ofFloatColor(0.7, 0.7, 0.7));
    // 環境反射光の色
    light.setAmbientColor(ofFloatColor(0.7, 0.7, 0.8, 1.0));
}

void SceneHotaru::update() {
//    updateForce();
    myFbo.begin();
    ofClear(0);
    light.setPosition(hotaru.getPosition());
    switch (state) {
        case 0 :
            camera.setPosition(box[index].getPosition());
            camera.lookAt(hotaru.getPosition());
            break;
        case 1 :
            camera.setPosition(hotaru.getPosition());
            camera.lookAt(hotaru.getVelocity() * 2.0);
            break;
        case 2 :
            camera.setPosition(0, ofGetWidth() * 2, ofGetWidth());
            camera.lookAt(ofVec3f(0, 0, 0));
            break;
    }
    camera.begin();
    connectBox(box);
    light.enable();
    for (int i = 0; i < box.size(); i++) {
        if (index == i) {
            continue;
        }
        box[i].draw();
    }
    hotaru.hitBox(box, hotaru.getPosition());
    hotaru.move(state);
    camera.end();
    myFbo.end();
}

void SceneHotaru::draw() {
//    myGlitch.generateFx();
    myFbo.draw(0, 0);
}

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

void SceneHotaru::updateForce() {
    ofVec3f force = box[0].getPosition() / hotaru.getPosition();
    force /= hotaru.getPosition().distance(box[0].getPosition());
    force *= ofRandom(4, 6);
    hotaru.applyForce(force);
}

void SceneHotaru::connectBox(vector<Box> box) {
    ofMesh mesh;
    float distance;
    for (int i = 0; i < box.size(); i++) {
        mesh.addVertex(box[i].getPosition());
        mesh.addColor((ofFloatColor)box[i].getColor());
    }
    glLineWidth(2.0);
    mesh.setMode(OF_PRIMITIVE_LINE_LOOP);
    mesh.draw();
}
