#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetCircleResolution(64);
    
    string path = "/Users/saitoushunsuke/Development/C/Prog2/lesson08";
    dir = ofDirectory(path);
    
    // dir.listDir() -> Int(その階層のファイルの数)
    for (int i = 0; i < dir.listDir(); i++) {
        if (!dir.getFile(i).isDirectory()) {
            files.push_back(dir.getFile(i));
            // 最大サイズを格納しておく
            maxSize = maxSize > files[i].getSize()? maxSize : files[i].getSize();
            position.push_back(ofVec2f(ofRandomWidth(), ofRandomHeight()));
            velocity.push_back(ofVec2f(ofRandom(-3, 3), ofRandom(-3, 3)));
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){
//    for (int i = 0; i < files.size(); i++) {
//        position[i] += velocity[i];
//        if (position[i].x < 0 || position[i].x > ofGetWidth())
//            velocity[i].x *= -1;
//        if (position[i].y < 0 || position[i].y > ofGetHeight())
//            velocity[i].y *= -1;
//    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < files.size(); i++) {
        ofDrawCircle(position[i], files[i].getSize() / 100);
    }
    if (isClicked) {
        ofDrawBitmapString(files[index].getFileName(), 100, 100);
        cout << "printing" << endl;
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
    ofVec2f current = ofVec2f(x, y);
    for (int i = 0; i < files.size(); i++) {
        if (current.distance(position[i]) < files[i].getSize() / 100) {
            isClicked = true;
            index = i;
            cout << "clicked" << endl;
        }
    }
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
