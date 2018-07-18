#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"
#include "ofxFluid.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    void audioIn(float * input, int bufferSize, int nChannels);
    void initFluid();
    void updateFluid();
    void drawFluid();

    ofxBox2d box2d; // Box2dの世界
    vector <ofPtr <ofxBox2dCircle> > circles;
    ofxFluid fluid;
    
    
    vector <float> left;
    vector <float> right;
    vector <float> volHistory;
    int     bufferCounter;
    int     drawCounter;
    
    float smoothedVol;
    float scaledVol;
    
    ofSoundStream soundStream;
    bool isLarger = false;
    float threshold = 0.2;
    
    ofVec2f oldM;
    int fluidWidth, fluidHeight;
    bool bPaint, bObstacle, bBounding, bClear;
};
