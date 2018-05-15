//
//  Hotaru.cpp
//  Bird
//
//  Created by 斉藤俊介 on 2018/05/04.
//

#include "Hotaru.hpp"

Hotaru::Hotaru() {
    
    this->position = ofVec3f(ofRandom(-halfWidth, halfWidth), ofRandom(-halfWidth, halfWidth), ofRandom(-halfWidth * 2, 0));
    this->velocity = ofVec3f(ofRandom(-5.0, 5.0), ofRandom(-5.0, 5.0), ofRandom(-5.0, 5.0));
    this->size = 50;
    targetAtractionForce = ofVec3f(1, 1, 1);
    targetAtractionForce.normalize();
}

void Hotaru::update(vector<Box> box) {
    // velocityの大きさ自体は変えずに方向のみ徐々に転換
    double numerator = pow(velocity.x, 2.0) + pow(velocity.y, 2.0) + pow(velocity.z, 2.0);
    double denominator = pow(velocity.x + targetAtractionForce.x, 2.0) + pow(velocity.y + targetAtractionForce.y, 2.0) + pow(velocity.z + targetAtractionForce.z, 2.0);
    double parameter = sqrt(numerator / denominator);
    targetAtractionForce = box[targetBox].getPosition() - position;
    targetAtractionForce.normalize();
    velocity = parameter * (velocity + targetAtractionForce);
}

void Hotaru::move(int state, vector<Box> box) {
    update(box);
    bound(position);
    position += velocity;
    hotaru.setPosition(position);
    if (state != 1) {
        hotaru.set(size, 30);
        hotaru.draw();
    }
    for (int i = 0; i < particles.size(); i++) {
        if (particles[i].check())
            particles[i].stay();
        else
            particles[i].flow();
    }
}

void Hotaru::hitBox(vector<Box>& box, ofVec3f hotaruPos) {
    for (int j = 0; j < box.size(); j++) {
        if (position.distance(box[j].getPosition()) <= box[j].getSize() + 50) {
            // 次にホタルがターゲットにするBoxをランダムに設定
            targetBox = (int)ofRandom(box.size());
            // ターゲットにしたBoxまでのベクトルを計算
            targetAtractionForce = box[targetBox].getPosition();
            // ターゲットまでのベクトルを正規化
            targetAtractionForce.normalize();
            // パーティクル発生とBox削除の処理
            particles.push_back(Particle(box[j].getPosition(), box[j].getColor()));
            particles[particles.size() - 1].setup();
            box.erase(box.begin() + j);
            break;
        }
    }
}

void Hotaru::bound(ofVec3f position) {
    int halfWidth = ofGetWidth() / 2;
    if (position.x <= -halfWidth || position.x >= halfWidth) {
        velocity.x *= -1.0;
    }
    if (position.y <= -halfWidth || position.y >= halfWidth) {
        velocity.y *= -1.0;
    }
    if (position.z >= 0 || position.z <= -halfWidth * 2) {
        velocity.z *= -1.0;
    }
}

ofVec3f Hotaru::getPosition() {
    return this->position;
}

ofVec3f Hotaru::getVelocity() {
    return this->velocity;
}

int Hotaru::getSize() {
    return this->size;
}
