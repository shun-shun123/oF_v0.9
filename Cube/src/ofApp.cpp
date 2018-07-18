#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetFrameRate(60);
    ofEnableAlphaBlending();
    ofSetVerticalSync(true);
    
    backgroundImage.load("UK.jpg");
    sound.load("Alone.mp3");
    sound.setVolume(1.0);
    sound.setLoop(true);
    sound.play();

    
    box_size = 15;
    for (int i = 0; i < NUM; i++) {
        mBox[i].setPosition(ofRandom(-500, 500), ofRandom(-500, 500), ofRandom(-500, 500));
        mBox[i].set(box_size);
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    vec.set(mouseX - p.x, mouseY - p.y);
}

//--------------------------------------------------------------
void ofApp::draw(){
    backgroundImage.draw(0, 0, ofGetWidth(), ofGetHeight());
    cam.begin();
    ofPushMatrix();
    ofRotateY(ofGetFrameNum());
    ofRotateZ(ofGetFrameNum() * 1.3);
    ofRotateX(ofGetFrameNum() * 1.6);
    int alpha = abs(vec.x) + abs(vec.y);
    ofSetColor(ofColor::fromHsb(int(ofGetFrameNum() * 0.5) % 255, 255, 255, 255 - alpha));
    for (int i = 0; i < NUM; i++) {
        mBox[i].draw();
    }
    ofPopMatrix();
    ofSetColor(255, 255, 255, ofGetFrameNum() * 6 % 120);
    box.setPosition(0, 0, 0);
    box.set(150);
    box.draw();
    ofSetColor(255, 255, 255, 255);
    box.drawWireframe();
    cam.end();
    p.x = mouseX;
    p.y = mouseY;
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
