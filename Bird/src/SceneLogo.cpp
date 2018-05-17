//
//  SceneLogo.cpp
//  Bird
//
//  Created by 斉藤俊介 on 2018/05/16.
//

#include "SceneLogo.hpp"

void SceneLogo::setup(vector<Particle *> _particles) {
    particles = _particles;
    verdana.load("verdana.ttf", 400);
}

void SceneLogo::update() {

}

void SceneLogo::draw() {
    ofSetColor(255);
    verdana.drawString("LiT!", -500, -300);
}
