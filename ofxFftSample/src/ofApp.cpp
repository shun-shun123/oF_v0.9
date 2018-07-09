#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackground(0);
    
    // FFTのサンプル数(2の累乗)を指定して初期化
    fft.setup(pow(2.0, 12.0));
    // GUI
    gui.setup();
    gui.add(saturation.setup("Saturation", 127, 0, 255));
    gui.loadFromFile("settings.xml");
}

//--------------------------------------------------------------
void ofApp::update(){
    fft.update(); // FFT更新
}

//--------------------------------------------------------------
void ofApp::draw(){
    // float型の配列にFFT結果を格納
    vector<float> buffer;
    buffer = fft.getBins();
    
    // グラフに描画
    ofPushMatrix();
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
    ofSetLineWidth(ofGetWidth() / float(buffer.size()));
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < buffer.size(); i++) {
            float hue = ofMap(i, 0, buffer.size(), 0, 255);
            float br = ofMap(buffer[i], 0, 1, 0, 255);
            ofColor color;
            color.setHsb(hue, saturation, br);
            ofSetColor(color);
            if (mode == 1 || mode == 4) {
                float rx = ofMap(i, 0, buffer.size(), 0, ofGetWidth() / 2.0);
                ofDrawLine(rx, -ofGetWidth() / 2, rx, ofGetWidth() / 2);
                float lx = ofMap(i, 0, buffer.size(), 0, -ofGetWidth() / 2.0);
                ofDrawLine(lx, -ofGetWidth() / 2, lx, ofGetWidth() / 2);
            }
            if (mode == 2 || mode == 4) {
                ofNoFill();
//                ofSetCircleResolution(ofNoise(ofGetElapsedTimef()) * 60);
                ofSetCircleResolution(6);
                ofDrawCircle(0, 0, ofMap(i, 0, buffer.size(), 0, ofGetWidth()));
            }
            if (mode == 3 || mode == 4) {
                ofNoFill();
                ofSetRectMode(OF_RECTMODE_CENTER);
                ofDrawRectangle(0, 0, ofMap(i, 0, buffer.size(), 0, ofGetWidth()), ofMap(i, 0, buffer.size(), 0, ofGetWidth()));
            }
        }
        ofRotateZ(90);
    }
    ofPopMatrix();

    gui.draw();
    ofSetColor(255);
    ofDrawBitmapString(ofGetFrameRate(), 10, 60);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case '1':
            mode = 1;
            break;
        case '2':
            mode = 2;
            break;
        case '3':
            mode = 3;
            break;
        case '4':
            mode = 4;
            break;
        default:
            mode = 0;
            break;
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
