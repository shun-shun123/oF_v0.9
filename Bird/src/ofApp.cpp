#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetVerticalSync(true);
    
    myFbo.allocate(ofGetWidth(), ofGetHeight());
    myGlitch.setup(&myFbo);
    myGlitch.setFx(OFXPOSTGLITCH_GLOW, true);
    
    for (int i = 0; i < NUM; i++) {
        middle += box[i].getPosition();
    }
    middle /= NUM;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    myFbo.begin();
    ofClear(0, 0, 0, 255);
    camera.setPosition(box[target].getPosition());
    camera.lookAt(middle);
    camera.begin();
    connectBoxes(box);
    for (int i = 0; i < NUM; i++) {
        if (i == target) {
            continue;
        }
        box[i].set();
    }
    camera.end();
    myFbo.end();
}

//--------------------------------------------------------------
void ofApp::draw(){
    myGlitch.generateFx();
    myFbo.draw(0, 0);
}

//--------------------------------------------------------------
void ofApp::connectBoxes(Box box[NUM]) {
    for (int i = 0; i < NUM; i++) {
        if (i != NUM - 1) {
            ofDrawLine(box[i].getPosition(), box[i + 1].getPosition());
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 'r' :
            target = (int)ofRandom(NUM);
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
