#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofToggleFullscreen();
    ofSetVerticalSync(true);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    ofSetCircleResolution(60);
    ofBackground(0, 0, 0);
    
    sound.load("Perfume.mp3");
    sound.setLoop(true);
    sound.play();
    
    // FFT解析初期化
    fftSmoothed = new float[8192];
    for (int i = 0; i < 8192; i++) {
        fftSmoothed[i] = 0;
    }
    nBandTpGet = 360;
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSoundUpdate();
    volume = ofSoundGetSpectrum(nBandTpGet);
    
    // FFT解析を行い、音量の平均を出す
    for (int i = 0; i < nBandTpGet; i++) {
        fftSmoothed[i] *= 0.96f;
        if (fftSmoothed[i] < volume[i]) {
            fftSmoothed[i] = volume[i];
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    int start_x = 200;
    int base_y = 500;
    float width = (float)(800) / nBandTpGet;
    
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
    
    for (int i = 0; i < nBandTpGet; i += 5) {
        ofPushMatrix();
        ofSetColor(ofColor::fromHsb((float)255 / nBandTpGet * i, 100, 255));
        float length = 300 * fftSmoothed[i % nBandTpGet];
        ofRotateZ(i);
        ofDrawRectangle(0, 150, 5, length);
        ofPopMatrix();
    }
    
    /* 四角形のヴィジュアライザーの場合 */
//    ofSetColor(55, 190, 260);
//    for (int i = 0; i < nBandTpGet; i++) {
//        ofDrawRectangle(start_x + i * width, base_y, width, -(fftSmoothed[i]) * 400);
//    }
//    
//    ofSetColor(200, 20, 105, 50);
//    for (int i = 0; i < nBandTpGet; i++) {
//        ofDrawRectangle(start_x + i * width, base_y, width, (fftSmoothed[i] * 300));
//    }
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
