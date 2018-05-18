//
//  SceneLogo.cpp
//  Bird
//
//  Created by 斉藤俊介 on 2018/05/16.
//

#include "SceneLogo.hpp"

void SceneLogo::setup(vector<Particle *> _particles) {
    particles = _particles;
    for (int i = 0; i < BOX_NUM; i++) {
        for (int j = 0; j < PARTICLE_NUM; j++) {
            circles[i][j] = ofVec3f(cos(((2 * PI) / BOX_NUM) * i) * 300, sin(((2 * PI) / BOX_NUM) * i) * 300, 0);
        }
    }
}

void SceneLogo::update() {
    for (int i = 0; i < particles.size(); i++) {
        for (int j = 0; j < PARTICLE_NUM; j++) {
            particles[i]->verts[j] += (circles[i][j] - particles[i]->verts[j]) / 30;
        }
        particles[i]->vbo.updateVertexData(particles[i]->verts, PARTICLE_NUM);
    }
}

void SceneLogo::draw() {
    for (int i = 0; i < particles.size(); i++) {
        particles[i]->draw();
    }
}

void SceneLogo::keyPressed(int key) {
    switch (key) {
        case ' ':
            updateFlag = true;
            break;
    }
}

bool SceneLogo::getUpdateFlag() {
    return updateFlag;
}
