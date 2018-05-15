//
//  Particle.cpp
//  Bird
//
//  Created by 斉藤俊介 on 2018/05/11.
//

#include "Particle.hpp"

Particle::Particle() {
    Particle(ofVec3f(500, 500, -1000), ofColor::fromHsb(100, 255, 255));
}

Particle::Particle(ofVec3f _position, ofColor _color) {
    this->position = _position;
    this->startPos = _position;
    this->color = _color;
    for (int i = 0; i < NUM; i++) {
        this->velocity[i] = ofVec3f(ofRandom(-3, 3), ofRandom(5), ofRandom(-3, 3));
    }
    particle.setPosition(_position);
    particle.set(ofRandom(1, 3), 10);
}

void Particle::flow() {
    update();
//    ofPushStyle();
//    ofSetColor(color);
//    particle.draw();
    draw();
//    ofPopStyle();
}

void Particle::stay() {
    update();
//    ofPushStyle();
//    ofSetColor(color);
//    particle.draw();
    draw();
//    ofPopStyle();
}

//void Particle::update() {
//    position += velocity;
//    particle.setPosition(position);
//    if (startPos.distance(position) >= 200) {
//        isThreshold = true;
//    }
//}

bool Particle::check() {
    return isThreshold;
}

void Particle::setup() {
    ofDirectory dir;
    dir.listDir("textures");
    
    // テクスチャを２乗モードに
    ofDisableArbTex();
    
    for (int i = 0; i < dir.size(); i++) {
        ofImage img;
        img.load(dir.getPath(i));
        textures.push_back(img);
    }
    
    // テクスチャを元のモードに
    ofEnableArbTex();
    
    for (int i = 0; i < NUM; i++) {
        verts[i].set(position);
        colors[i].set((ofFloatColor)color);
        // 法線の情報をポイントサイズとテクスチャの選択に利用
        normals[i].set(ofRandom(2, 50), (int)ofRandom(0, textures.size()));
    }
    
    vbo.setVertexData(verts, NUM, GL_DYNAMIC_DRAW);
    vbo.setColorData(colors, NUM, GL_DYNAMIC_DRAW);
    vbo.setNormalData(normals, NUM, GL_DYNAMIC_DRAW);
    
    mPointSprite.load("shaders/pointSprite.vert","shaders/pointSprite.frag");
}

void Particle::update() {
    for (int i = 0; i < NUM; i++) {
        verts[i] += velocity[i];
    }
    vbo.updateVertexData(verts, NUM);
    vbo.updateColorData(colors, NUM);
    vbo.updateNormalData(normals, NUM);
}

void Particle::draw() {
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    ofEnablePointSprites();
    
    mPointSprite.begin();
    
    mPointSprite.setUniformTexture("tex1", textures[0], 0);
    mPointSprite.setUniformTexture("tex2", textures[1], 1);
    
    vbo.draw(GL_POINTS, 0, NUM);
    mPointSprite.end();
    
    ofDisablePointSprites();
}
