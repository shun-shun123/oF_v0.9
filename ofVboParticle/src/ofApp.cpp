#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // 画面基本設定
    ofSetFrameRate(60);
    ofBackground(0);
    
    // メッシュを点で描画
    mesh.setMode(OF_PRIMITIVE_POINTS);
    glPointSize(1.0);
    
    for (int i = 0; i < NUM; i++) {
        Particle p;
        p.friction = 0.002;
        p.setup(ofVec2f(ofRandomWidth(), ofRandomHeight()), ofVec2f(0, 0));
        particles.push_back(p);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    // パーティクルの数だけ計算
    for (int i = 0; i < particles.size(); i++) {
        // 力をリセット
        particles[i].reserForce();
        // もし引力が働いていたら
        if (attraction) {
            // マウスの位置に引力を加える
            particles[i].addAttractionForce(ofVec2f(mouseX, mouseY), ofGetWidth(), 0.1);
        }
        // パーティクル更新
        particles[i].update();
        // 画面の端に来たら反対側へ
        particles[i].throughOfWalls();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    // メッシュを点で描く
    mesh.clear();
    ofSetColor(255);
    for (int i = 0; i < NUM; i++) {
        mesh.addVertex(ofVec3f(particles[i].position.x, particles[i].position.y, 0));
    }
    mesh.draw();
    
    // 重力の点を描く
    if (attraction) {
        ofSetColor(255, 0, 0);
    } else {
        ofSetColor(0, 255, 255);
    }
    ofDrawCircle(mouseX, mouseY, 4);
    
    // 文字の背景
    ofSetColor(0, 127);
    ofDrawRectangle(0, 0, 200, 60);
    
    // ログを表示
    ofSetColor(255);
    ofDrawBitmapString("fps = " + ofToString(ofGetFrameRate()), 10, 20);
    ofDrawBitmapString("Particle num = " + ofToString(particles.size()), 10, 40);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'c') {
        particles.clear();
        for (int i = 0; i < NUM; i++) {
            Particle p;
            p.friction = 0.002;
            p.setup(ofVec2f(ofRandomWidth(), ofRandomHeight()), ofVec2f(0, 0));
            particles.push_back(p);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    attraction = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    attraction = false;
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
