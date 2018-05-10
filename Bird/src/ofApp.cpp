#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    hotaru.setup();
//    ofSetCircleResolution(64);
//    ofBackground(0);
//    ofSetBackgroundAuto(false);
//    circles.push_back(ofVec2f(ofRandomWidth(), ofRandomHeight()));
//    velocity.push_back(ofVec2f(ofRandom(-10, 10), ofRandom(-10, 10)));
}

//--------------------------------------------------------------
void ofApp::update(){
    hotaru.update();
//    clock++;
//    clock %= 100;
//    cout << clock << endl;
//    int size = circles.size();
//    for (int i = 0; i < size; i++) {
//        // push_back
//        if (clock == 0 && size <= 20) {
//            circles.push_back(circles[i]);
//            velocity.push_back(ofVec2f(ofRandom(-10, 10), ofRandom(-10, 10)));
//        }
//        // 跳ね返り
//        if (circles[i].x <= 0 || circles[i].x >= ofGetWidth()) {
//            velocity[i].x *= -1;
//        }
//        if (circles[i].y <= 0 || circles[i].y >= ofGetHeight()) {
//            velocity[i].y *= -1;
//        }
//        circles[i] += velocity[i];
//    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    hotaru.draw();
//    ofPushStyle();
//    ofSetColor(0, 50);
//    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
//    ofPopStyle();
//    for (int i = 0; i < circles.size(); i++) {
//        ofDrawCircle(circles[i], 10);
//    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    hotaru.keyPressed(key);
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
