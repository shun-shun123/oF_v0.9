#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup() {
    ofBackground(0);
    ofSetBackgroundAuto(false);
    ofToggleFullscreen();

}

//--------------------------------------------------------------
void testApp::update(){
    for (int i = 0; i < HOTARU_NUM; i++) {
        hotaru[i].update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofPushStyle();
    ofSetColor(0, 50);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    ofPopStyle();
    for (int i = 0; i < HOTARU_NUM; i++) {
        hotaru[i].move();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}
