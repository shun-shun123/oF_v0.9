#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"
#include "GenjiHotaru.hpp"
#include "Environment.hpp"
#include "ofxBlur.h"

#define HOTARU_NUM 10
#define STATE 5

class testApp : public ofBaseApp{

public:
    
	void setup();
	void update();
	void draw();
    
	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
    
    void setBrightness(ofImage image, const int brightness);
    Hotaru hotaru;
    Hotaru akimusi;
    Environment season;
    ofImage sample;
    bool hoge = false;
    ofSpherePrimitive sphere;
    ofFbo fbo;
    ofxBlur blur;
};

#endif
