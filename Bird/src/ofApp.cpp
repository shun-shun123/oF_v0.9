#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    hotaru->setup();
    cam.setPosition(0, 0, ofGetWidth());
    cam.lookAt(ofVec3f(0, 0, -ofGetWidth()));
    img.load("LiT.jpg"); // 1022 * 760
}

//--------------------------------------------------------------
void ofApp::update(){
    hotaru->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (!hotaru->getFinish()) {
        hotaru->draw();
    } else {
        cam.begin();
//        img.draw(-500, -500);
        particles = hotaru->getParticles();
        for (int i = 0; i < particles.size(); i++) {
            particles[i]->align(img, i);
        }
        cam.end();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    hotaru->keyPressed(key);
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
