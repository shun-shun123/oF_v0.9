#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofSetBackgroundAuto(false);
    
    
    for (int i = 0; i < NUM; i++) {
        myVerts[i] = ofVec2f(ofRandomWidth(), ofRandomHeight());
        myColors[i] = ofFloatColor::fromHsb(ofRandom(1.0), 1.0, 1.0, 1.0);
        position[i] = myVerts[i];
        velocity[i] = ofVec2f(0, 0);
    }
    myVbo.setVertexData(position, NUM, GL_DYNAMIC_DRAW);
    myVbo.setColorData(myColors, NUM, GL_DYNAMIC_DRAW);
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < NUM; i++) {
        position[i] += velocity[i];
    }
    myVbo.updateVertexData(position, NUM);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0, 100);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    myVbo.draw(GL_POINTS, 0, NUM);
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
    ofVec2f mouse = ofVec2f(x, y);
    for (int i = 0; i < NUM; i++) {
        velocity[i] = (mouse - myVerts[i]) / 30;
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    for (int i = 0; i < NUM; i++) {
        position[i] = myVerts[i];
    }
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
