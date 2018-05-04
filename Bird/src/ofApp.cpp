#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetVerticalSync(true);
    myFbo.allocate(ofGetWidth(), ofGetHeight());
    myGlitch.setup(&myFbo);
    myGlitch.setFx(OFXPOSTGLITCH_GLOW, true);
    myFbo.begin();
    for (int i = 0; i < NUM; i++) {
        position = ofVec3f(ofRandomWidth() * 1.5, ofRandomHeight() * 1.5, -ofRandomWidth() * 1.5);
        middle += position;
        box[i].setPosition(position);
        box[i].set(ofRandom(50, 100), ofRandom(50, 100), ofRandom(50, 100));
        box[i].draw();
    }
    middle /= NUM;
    myFbo.end();
}

//--------------------------------------------------------------
void ofApp::update(){
    myFbo.begin();
    camera.begin();
    ofClear(0, 0, 0, 255);
    for (int i = 0; i < NUM; i++) {
        box[i].draw();
    }
    camera.end();
    myFbo.end();
}

//--------------------------------------------------------------
void ofApp::draw(){
    myGlitch.generateFx();
    ofSetColor(255);
    myFbo.draw(0, 0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case '1' :
            camera.setPosition(ofRandomWidth(), ofRandomHeight(), -ofRandomWidth());
            camera.lookAt(middle);
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
