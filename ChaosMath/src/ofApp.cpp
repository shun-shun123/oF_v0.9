#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofToggleFullscreen();
    
    glPointSize(1.0);
    mesh.setMode(OF_PRIMITIVE_POINTS);
    a = 1.0;
    b = 1.0;
    c = 1.0;
    d = 1.0;
    aa = 0.02;
    bb = 0.01;
    cc = 0.01;
    dd = 0.01;
}

//--------------------------------------------------------------
void ofApp::update(){
    x = 1.0;
    y = 1.0;
    
    a += aa;
    b += bb;
    c += cc;
    d += dd;
    if (a <= 1.0 || a >= 4.0) aa *= -1;
    if (b <= 1.0 || b >= 4.0) bb *= -1;
    if (c <= 1.0 || c >= 3.0) cc *= -1;
    if (d <= 1.0 || d >= 3.0) dd *= -1;
    
    mesh.clear();
    for (int i = 0; i < NUM_PARTICLE; i++) {
        xn = sin(a * y) + c * cos(a * x);
        yn = sin(b * x) + d * cos(b * y);
        
        x = xn;
        y = yn;
        points[i].x = x * 120;
        points[i].y = y * 120;
        
        mesh.addVertex(ofVec3f(points[i].x, points[i].y, 0.0));
        mesh.addColor(ofColor::fromHsb(int(ofGetElapsedTimef()) % 256, 255, 255));
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
    mesh.draw();
    ofPopMatrix();
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
