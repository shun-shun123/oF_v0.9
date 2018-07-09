#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    w = 1280;
    h = 720;
    ofBackground(0);
    ofSetFrameRate(60);
    ofSetWindowTitle("ofVideoGrabber sample");
    
    video.initGrabber(w, h);
    changedPixels = new unsigned char[w * h * 3];
    
    videoTexture.allocate(w, h, GL_RGB);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    video.update();
    
    if (video.isFrameNew()) {
        unsigned char* pixels = video.getPixels().getData();
        switch (state) {
            case 1:
                reverseColor(pixels);
                break;
            case 2:
                noiseColor(pixels);
                break;
            case 3:
                modifyPixels(pixels);
                break;
            default:
                changedPixels = pixels;
                break;
        }
        videoTexture.loadData(changedPixels, w, h, GL_RGB);
    }
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (state == 0) {
        video.draw(0, 0);
    } else {
        videoTexture.draw(0, 0);
    }
}

//-------------------------------------------------------------
void ofApp::reverseColor(unsigned char* pixels) {
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            // 赤
            changedPixels[y * 3 * w + x * 3] = 255 - pixels[y * 3 * w + x * 3];
            // 緑
            changedPixels[y * 3 * w + x * 3 + 1] = 255 - pixels[y * 3 * w + x * 3 + 1];
            // 青
            changedPixels[y * 3 * w + x * 3 + 2] = 255 - pixels[y * 3 * w + x * 3 + 2];
        }
    }
}

//--------------------------------------------------------------
void ofApp::noiseColor(unsigned char* pixels) {
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            // 赤
            changedPixels[y * 3 * w + x * 3] = pixels[y * 3 * w + x * 3] + ofRandom(-30, -10);
            // 緑
            changedPixels[y * 3 * w + x * 3 + 1] = pixels[y * 3 * w + x * 3 + 1] + ofRandom(-30, -10);
            // 青
            changedPixels[y * 3 * w + x * 3 + 2] = pixels[y * 3 * w + x * 3 + 2] + ofRandom(-30, -10);
        }
    }
}

void ofApp::modifyPixels(unsigned char* pixels) {
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            int random = int(ofRandom(x));
            int noise = 20;
            if (random <= (x + noise) && random >= (x - noise)) {
                changedPixels[y * 3 * w + x * 3] = 0;
                changedPixels[y * 3 * w + x * 3 + 1] = 0;
                changedPixels[y * 3 * w + x * 3 + 2] = 0;
                continue;
            }
            // red
//            changedPixels[y * 3 * w + x * 3] = pixels[(w * h * 3) - (y * 3 * w + x * 3)];
//            // green
//            changedPixels[y * 3 * w + x * 3 + 1] = pixels[(w * h * 3) - (y * 3 * w + x * 3 + 1)];
//            // blue
//            changedPixels[y * 3 * w + x * 3 + 2] = pixels[(w * h * 3) - (y * 3 * w + x * 3 + 2)];
            changedPixels[y * 3 * w + x * 3] = pixels[y * 3 * w + x * 3];
            changedPixels[y * 3 * w + x * 3 + 1] = pixels[y * 3 * w + x * 3 + 1];
            changedPixels[y * 3 * w + x * 3 + 2] = pixels[y * 3 * w + x * 3 + 2];
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case '0':
            state = 0;
            break;
        case '1':
            state = 1;
            break;
        case '2':
            state = 2;
            break;
        case '3':
            state = 3;
            break;
    }
    cout << state << endl;
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
