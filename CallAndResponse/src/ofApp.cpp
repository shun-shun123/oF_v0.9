#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetFrameRate(60);
    
    int bufferSize = 256;
    
    left.assign(bufferSize, 0.0);
    right.assign(bufferSize, 0.0);
    volHistory.assign(400, 0.0);
    
    bufferCounter    = 0;
    drawCounter        = 0;
    smoothedVol     = 0.0;
    scaledVol        = 0.0;
    
//    soundStream.setup(this, 0, 2, 44100, bufferSize, 4);
    
    box2d.init();
    box2d.setGravity(0, 10);
    box2d.createBounds();
    box2d.setFPS(30.0);
    box2d.registerGrabbing();
    
    initFluid();
}

//--------------------------------------------------------------
void ofApp::update(){
//    box2d.update();
    updateFluid();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0, 127, 255);
//    if (isLarger) {
//        ofPtr<ofxBox2dCircle> circle = ofPtr<ofxBox2dCircle>(new ofxBox2dCircle);
//        circle.get()->setPhysics(3.0, 0.53, 0.1);
//        circle.get()->setup(box2d.getWorld(), ofRandomWidth(), ofRandom(0, 300), ofRandom(10, 30));
//        circles.push_back(circle);
//        cout << "Larger" << endl;
//    } else {
//        cout << "Lower" << endl;
//    }
//    for (int i = 0; i < circles.size(); i++) {
//        circles[i].get()->draw();
//    }
    drawFluid();
}

//--------------------------------------------------------------
void ofApp::initFluid(){
    fluidWidth = ofGetWidth();
    fluidHeight = ofGetHeight();
    fluid.allocate(fluidWidth, fluidHeight, 0.5);
    fluid.dissipation = 0.99;
    fluid.velocityDissipation = 0.99;
    fluid.setGravity(ofVec2f(0.0, 0.0098));
    fluid.begin();
    ofSetColor(0, 0);
    ofSetColor(255);
    ofDrawCircle(fluidWidth * 0.5, fluidHeight * 0.35, 40);
    fluid.end();
    fluid.setUseObstacles(false);
    
    fluid.addConstantForce(ofPoint(fluidWidth * 0.5, fluidHeight * 0.85), ofPoint(0, -2), ofFloatColor(0.5, 0.1, 0.0), 10.0f);
    
    ofSetWindowShape(fluidWidth, fluidHeight);
}

//-------------------------------------------------------------
void ofApp::updateFluid(){
    ofPoint m = ofPoint(mouseX, mouseY);
    ofPoint d = (m - oldM) * 10.0;
    oldM = m;
    ofPoint c = ofPoint(fluidWidth * 0.5, fluidHeight * 0.5) - m;
    c.normalize();
    fluid.addTemporalForce(m, d, ofFloatColor(c.x, c.y, 0.5) * sin(ofGetElapsedTimef()), 3.0f);
    fluid.update();
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
}

//-------------------------------------------------------------
void ofApp::drawFluid(){
    ofBackgroundGradient(ofFloatColor(0.2), ofFloatColor(0.0), OF_GRADIENT_LINEAR);
    fluid.draw();
}

//-------------------------------------------------------------
void ofApp::audioIn(float * input, int bufferSize, int nChannels){
    
    float curVol = 0.0;
    
    // samples are "interleaved"
    int numCounted = 0;
    
    //lets go through each sample and calculate the root mean square which is a rough way to calculate volume
    for (int i = 0; i < bufferSize; i++){
        left[i]        = input[i*2]*0.5;
        right[i]    = input[i*2+1]*0.5;
        
        curVol += left[i] * left[i];
        curVol += right[i] * right[i];
        numCounted+=2;
    }
    
    //this is how we get the mean of rms :)
    curVol /= (float)numCounted;
    
    // this is how we get the root of rms :)
    curVol = sqrt( curVol );
    
    smoothedVol *= 0.93;
    smoothedVol += 0.07 * curVol;
    
    bufferCounter++;
    
    if (curVol < threshold) {
        isLarger = false;
    } else {
        isLarger = true;
    }
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
