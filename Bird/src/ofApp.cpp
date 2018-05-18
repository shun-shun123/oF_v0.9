#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    hotaru->setup();
    cam.setPosition(0, 0, ofGetWidth());
    cam.lookAt(ofVec3f(0, 0, -ofGetWidth()));
}

//--------------------------------------------------------------
void ofApp::update(){
    if (!isUpdate)
        hotaru->update();
    if (isUpdate && logo->getUpdateFlag())
        logo->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (!hotaru->getFinish()) {
        hotaru->draw();
    } else {
        if (!isUpdate) {
            particles = hotaru->getParticles();
            logo->setup(particles);
            isUpdate = true;
        }
        cam.begin();
        logo->draw();
        cam.end();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    hotaru->keyPressed(key);
    logo->keyPressed(key);
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
