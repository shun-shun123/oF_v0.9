#include "testApp.h"
float brightness = 0;
ofColor color;
//--------------------------------------------------------------
void testApp::setup() {
    ofBackground(0);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    sample.load("sample.png");
    akimusi.sound.load("秋の夜の虫の音.mp3");
//    hotaru.cry();
//    akimusi.cry();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    sphere.setPosition(ofGetWidth() / 2, ofGetHeight() / 2, 100);
    sphere.set(1000, 200);
    blur.setup(ofGetWidth(), ofGetHeight());
    fbo.allocate(ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void testApp::update(){
    if (brightness >= 255) brightness = 0;
    brightness++;
    setBrightness(sample, brightness);
    color = ofColor::fromHsb(150, 255, brightness);
//    hotaru.update();
//    hotaru.setPan(ofMap(hotaru.pos.x, 0, ofGetWidth(), -1, 1));
//    hotaru.sound.setVolume(pow(ofNoise(ofGetElapsedTimeMillis()), 4));
//    akimusi.update();
//    akimusi.setPan(ofMap(hotaru.pos.x, 0, ofGetWidth(), -1, 1));
//    akimusi.sound.setVolume(pow(ofNoise(ofGetElapsedTimeMillis()), 6));
    
}

//--------------------------------------------------------------
void testApp::draw(){
//    for (int i = 0; i < HOTARU_NUM; i++) {
//        hotaru[i].move();
//    }
//    sample.draw(ofGetWidth() / 2, ofGetHeight() / 2);
//    hotaru.move();
//    akimusi.move();
//    season.setSeason();
    fbo.begin();
    ofDisableBlendMode();
    sphere.draw();
    fbo.end();
    
    blur.begin();
    ofDisableBlendMode();
    ofBackground(0);
    fbo.draw(0,0);
    blur.end();
}

//--------------------------------------------------------------
void testApp::setBrightness(ofImage image, const int brightness) {
    int numChannels;
    
    switch (image.getImageType()) {
        case OF_IMAGE_GRAYSCALE:
            numChannels = 1;
            break;
        case OF_IMAGE_COLOR:
            numChannels = 2;
            break;
        case OF_IMAGE_COLOR_ALPHA: // これになるはず
            numChannels = 3;
            break;
        default:
            numChannels = -1;
            break;
    }
    ofPixels &pix = image.getPixels();
    
    // pixSize == 5547
    const size_t pixSize = static_cast<size_t>(image.getWidth() * image.getHeight() * numChannels);
    
    for (size_t i = 0; i < pixSize; i += numChannels) {
        const int r = pix[i] + brightness;
        const int g = pix[i+1] + brightness;
        const int b = pix[i+2] + brightness;
        pix[i] = static_cast<unsigned char>(r < 0 ? 0 : r > 255 ? 255 : r);
        pix[i+1] = static_cast<unsigned char>(g < 0 ? 0 : g > 255 ? 255 : g);
        pix[i+2] = static_cast<unsigned char>(b < 0 ? 0 : b > 255 ? 255 : b);
    }
    image.update();
}


//--------------------------------------------------------------
void testApp::keyPressed(int key){
    hotaru.cry();
    akimusi.cry();
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}
