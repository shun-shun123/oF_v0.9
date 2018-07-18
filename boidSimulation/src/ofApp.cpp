#include "ofApp.h"

#define NUM 30

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofSetBackgroundAuto(false);
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    radius = 10;
    for (int i = 0; i < NUM; i++) {
        position[i] = ofVec2f(ofRandom(300, ofGetWidth() - 300), ofRandom(300, ofGetHeight() - 300));
        force[i] = ofVec2f(ofRandom(-2, 2), ofRandom(-2, 2));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < NUM; i++) {
        // 条件１全体の中心 -> ave_pos に向かう力 -> velocity1
        ofVec2f ave_pos = ofVec2f(0, 0);
        for (int j = 0; j < NUM; j++) {
            ave_pos += position[j];
        }
        // 平均位置へのベクトルを算出
        ave_pos /= NUM;
        // 平均位置への速度を算出
        velocity1[i] = (ave_pos - position[i]) / 400;
        
//        // 条件２近すぎる場合 -> 30未満 離れる方向に力 -> velocity2
//        for (int j = 0; j < NUM; j++) {
//            if (i != j) {
//                float dist = position[i].distance(position[j]);
//                if (dist <= 30) {
//                    velocity2[i] += (position[i] - position[j]) / 30;
//                }
//            }
//        }
//        cout << velocity2[i] << endl;
//        // 条件３全体と強調して、同じ方向 -> direction に動こうとする力 -> velocity2
//        ofVec2f direction = ofVec2f(0, 0);
//        for (int j = 0; j < NUM; j++) {
//            direction += force[i];
//        }
//        // 全体が動く方向ベクトルを算出する
//        direction /= NUM;
//        cout << direction << endl;
//
//        // 全体が動く方向への速度ベクトルを算出する
//        velocity3[i] = (direction - position[i]) / 250;
        
        force[i] += velocity1[i] * 1.1 + velocity2[i] * 0.1;
        
        position[i] += force[i];
        if (position[i].x <= radius / 2 || position[i].x >= ofGetWidth() - radius / 2) {
            force[i].x *= -1;
        }
        if (position[i].y <= radius / 2 || position[i].y >= ofGetHeight() - radius / 2) {
            force[i].y *= -1;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0, 20);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    ofSetColor(0, 255, 255, 150);
    ofVec2f average = ofVec2f(0, 0);
    for (int i = 0; i < NUM; i++) {
        average += position[i];
        ofDrawCircle(position[i], 10);
    }
    average /= NUM;
    ofSetColor(255, 0, 255);
    ofDrawCircle(average, 10);
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
