#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofEnableAlphaBlending();
    ofSetCircleResolution(64);
    for (int i = 0; i < 3; i++) {
        diameter[i] = 0;
        spraed[i] = i * 1.5 + 1.5;
        alpha[i] = 255;
    }
    
    music.load("MiracleWorker.mp3");
    music.setLoop(true);
    music.setVolume(0.0);
    music.play();
}

//--------------------------------------------------------------
void ofApp::update(){
    if (isMousePressed) {
        for (int i = 0; i < 3; i++) {
            diameter[i] += spraed[i];
            alpha[i] -= (i + 1) * 0.5;
        }
        music.setVolume(alpha[2] / 255);
    }
    if (alpha[2] <= 0) {
        for (int i = 0; i < 3; i++) {
            diameter[i] = 0;
            alpha[i] = 255;
        }
        isMousePressed = false;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < 3; i++) {
        ofSetColor(255, alpha[i]);
        ofNoFill();
        ofDrawCircle(circle_x[i], circle_y[i], diameter[i]);
    }
    ofSetColor(ofColor::fromHsb(music.getVolume() * 255, 200, 255));
    sphere.setPosition(ofGetWidth() / 2, ofGetHeight() / 2, 0);
    sphere.set(music.getVolume() * 200, 64);
    sphere.drawWireframe();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
    for (int i = 0; i < 3; i++) {
        circle_x[i] = x;
        circle_y[i] = y;
        diameter[i] = 0;
        alpha[i] = 255;
    }
    double pan = ((x - (ofGetWidth() / 2.0)) / (ofGetWidth() / 2.0));
    music.setPan(pan);
    isMousePressed = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
