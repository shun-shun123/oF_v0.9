//
//  SceneHotaru.cpp
//  Bird
//
//  Created by 斉藤俊介 on 2018/05/09.
//

#include "SceneHotaru.hpp"

SceneHotaru::~SceneHotaru() {
    cout << "SceneHotaru destructor is called" << endl;
}

void SceneHotaru::setup() {
    ofBackground(0);
    ofSetVerticalSync(true);
    ofEnableDepthTest();
    ofEnableSmoothing();
    
    initialize();
}

void SceneHotaru::update() {
    myFbo.begin();
    ofClear(0);
    switch (state) {
        case 0 :
            camera.setPosition(tmpPos);
            camera.lookAt(hotaru.getPosition());
            break;
        case 1 :
            camera.setPosition(hotaru.getPosition());
            camera.lookAt(hotaru.getVelocity());
            break;
        case 2 :
            camera.setPosition(0, ofGetWidth() * 2, ofGetWidth());
            camera.lookAt(ofVec3f(0, 0, 0));
            break;
    }
    camera.begin();
    connectBox(box);
    for (int i = 0; i < box.size(); i++) {
        if (box[i]->getPosition() == tmpPos) {
            continue;
        }
        box[i]->draw();
    }
    hotaru.hitBox(box, hotaru.getPosition());
    hotaru.move(state, box);
    camera.end();
    myFbo.end();
}

void SceneHotaru::draw() {
    myFbo.draw(0, 0);
}

void SceneHotaru::keyPressed(int key) {
    switch (key) {
        case '2' :
            state = 2;
            break;
        case '1' :
            state = 1;
            break;
        case '0' :
            state = 0;
            index = (int)ofRandom(box.size() - 1);
            tmpPos = box[index]->getPosition();
            break;
    }
}

void SceneHotaru::connectBox(vector<Box *> box) {
    ofMesh mesh;
    // Boxが0になった時の処理
    if (box.size() == 1) {
        isFinished = true;
        return;
    }
    for (int i = 0; i < box.size(); i++) {
        mesh.addVertex(box[i]->getPosition());
        mesh.addColor((ofFloatColor)box[i]->getColor());
    }
    glLineWidth(3.0);
    mesh.setMode(OF_PRIMITIVE_LINE_LOOP);
    mesh.draw();
}

void SceneHotaru::initialize() {
    // FBOの割り当て
    myFbo.allocate(ofGetWidth(), ofGetWidth());
    
    // vector<Box> の初期設定とmiddleの算出
    for (int i = 0; i < NUM; i++) {
        box.push_back(new Box());
        middle += box[i]->getPosition();
    }
    middle /= (float)NUM;
    
    // ライティング初期設定
    light.enable();
    light.setPointLight();
    light.setPosition(middle);
    // 鏡面反射光の色
    light.setSpecularColor(ofFloatColor(1.0, 1.0, 1.0));
    // 拡散反射光の色
    light.setDiffuseColor(ofFloatColor(0.7, 0.7, 0.7));
    // 環境反射光の色
    light.setAmbientColor(ofFloatColor(0.7, 0.7, 0.8, 1.0));
    
}

bool SceneHotaru::getFinish() {
    return isFinished;
}

vector<Particle*> SceneHotaru::getParticles() {
    return hotaru.particles;
}
