//
//  SceneLogo.cpp
//  Bird
//
//  Created by 斉藤俊介 on 2018/05/16.
//

#include "SceneLogo.hpp"

void SceneLogo::setup(vector<Particle *> _particles) {
    particles = _particles;
    verdana.load("verdana.ttf", 800, false, false, true);
    vector<ofTTFCharacter> paths;
    paths = verdana.getStringAsPoints("LiT!");
    
    firstLetter = paths[0].getOutline();
    secondLetter = paths[1].getOutline();
    thirdLetter = paths[2].getOutline();
    fourthLetter = paths[3].getOutline();
    
    // 文字が反転して表示されるのでその対処
    reverseX(firstLetter);
    reverseX(secondLetter);
    reverseX(thirdLetter);
    reverseX(fourthLetter);
    
    cam.setPosition(0, 0, ofGetWidth());
}

void SceneLogo::reverseX(vector<ofPolyline>& lines) {
    for (int i = 0; i < lines.size(); i++) {
        for (int j = 0; j < lines[i].size(); j++) {
            lines[i][j] *= ofVec3f(1, -1, 1);
        }
    }
}

void SceneLogo::update() {
    ofPushMatrix();
    ofTranslate(-1000, 0);
    for (int i = 0; i < particles.size(); i++) {
        for (int j = 0; j < 50; j++) {
            switch (i) {
                case 0:
                    particles[i]->verts[j] += (firstLetter[0][0] - particles[i]->verts[j]) / 30;
                    break;
                case 1:
                    particles[i]->verts[j] += (firstLetter[0][1] - particles[i]->verts[j]) / 30;
                    break;
                case 2:
                    particles[i]->verts[j] += (firstLetter[0][2] - particles[i]->verts[j]) / 30;
                    break;
                case 3:
                    particles[i]->verts[j] += (firstLetter[0][3] - particles[i]->verts[j]) / 30;
                    break;
                case 4:
                    particles[i]->verts[j] += (firstLetter[0][4] - particles[i]->verts[j]) / 30;
                    break;
                case 5:
                    particles[i]->verts[j] += (firstLetter[0][5] - particles[i]->verts[j]) / 30;
                    break;
                case 6:
                    particles[i]->verts[j] += (firstLetter[0][6] - particles[i]->verts[j]) / 30;
                    break;
                default:
                    break;
            }
        }
        particles[i]->vbo.updateVertexData(particles[i]->verts, 50);
    }
    ofPopMatrix();
}

void SceneLogo::draw() {
    update();
    cam.begin();
    ofPushMatrix();
    ofTranslate(-1000, 0);
    // x, y軸描画
    ofPushStyle();
    ofSetColor(255, 0, 0);
    ofDrawLine(0, 0, ofGetWidth(), 0);
    ofSetColor(0, 0, 255);
    ofDrawLine(0, 0, 0, ofGetHeight());
    ofPopStyle();
    for (int i = 0; i < particles.size(); i++) {
        particles[i]->flow();
    }
    for (int i = 0; i < firstLetter.size(); i++) {
        for (int j = 0; j < firstLetter[i].size(); j++) {
            ofDrawCircle(firstLetter[i][j], 10);
        }
    }
    ofDrawLine(letterL[0], letterL[1]);
    ofDrawLine(letterL[1], letterL[2]);
    firstLetter[0].draw();
    ofPopMatrix();
    cam.end();
}
