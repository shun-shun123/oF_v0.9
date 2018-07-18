#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0, 0, 0);
    
    ofEnableDepthTest();
    
    light.enable();
    light.setPosition(-100, 100, 600);
    glPointSize(3);
    
//    mesh = ofPlanePrimitive(1000, 1000, 100, 100).getMesh();
    mesh = ofSpherePrimitive(200, 70).getMesh();
    for (int i = 0; i < mesh.getVertices().size(); i++) {
        mesh.addColor(ofFloatColor(0.5, 1.0, 1.0, 0.5));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
//    for (int i = 0; i < mesh.getVertices().size(); i++) {
//        ofVec3f point = mesh.getVertices()[i] / 400.0;
//        float z = ofNoise(point.x, point.y, ofGetElapsedTimef()) * 200.0;
//        mesh.setVertex(i, ofVec3f(mesh.getVertices()[i].x, mesh.getVertices()[i].y, z));
//    }
    
    for (int i = 0; i < mesh.getVertices().size(); i++) {
        ofVec3f point = mesh.getVertices()[i] / 300.0;
        float size = 80 + 100 * ofNoise(point.x, point.y, point.z, ofGetElapsedTimef());
        ofVec3f newPoint = point.normalize() * size;
        mesh.setVertex(i, newPoint);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    
//    mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    mesh.setMode(OF_PRIMITIVE_POINTS);
    mesh.draw();
    
    cam.end();
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
