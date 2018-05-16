//
//  Hotaru.cpp
//  Bird
//
//  Created by 斉藤俊介 on 2018/05/04.
//

#include "Hotaru.hpp"

Hotaru::Hotaru() {
    position = ofVec3f(ofRandom(-halfWidth, halfWidth), ofRandom(-halfWidth, halfWidth), ofRandom(-halfWidth * 2, 0));
    velocity = ofVec3f(ofRandom(-4.0, 4.0), ofRandom(-4.0, 4.0), ofRandom(-4.0, 4.0));
    radius = 50;
    targetAtractionForce = ofVec3f(1, 1, 1);
    targetAtractionForce.normalize();
}

void Hotaru::update(vector<Box> box) {
    // velocityの大きさ自体は変えずに方向のみ徐々に転換
    targetAtractionForce = box[targetBox].getPosition() - position;
    targetAtractionForce.normalize();
    double numerator = pow(velocity.x, 2.0) + pow(velocity.y, 2.0) + pow(velocity.z, 2.0);
    double denominator = pow(velocity.x + targetAtractionForce.x, 2.0) + pow(velocity.y + targetAtractionForce.y, 2.0) + pow(velocity.z + targetAtractionForce.z, 2.0);
    double parameter = sqrt(numerator / denominator);
    velocity = parameter * (velocity + targetAtractionForce);
    position += velocity;
    bound(position);
    hotaru.setPosition(position);
}

void Hotaru::move(int state, vector<Box> box) {
    update(box);
    if (state != 1) {
        hotaru.set(radius, 30);
        hotaru.draw();
    }
    for (int i = 0; i < particles.size(); i++) {
        particles[i].flow();
    }
}

void Hotaru::hitBox(vector<Box>& box, ofVec3f hotaruPos) {
    for (int i = 0; i < box.size(); i++) {
        if (position.distance(box[i].getPosition()) <= box[i].getSize() / 2 + radius) {
            // 次にホタルがターゲットにするBoxをランダムに設定
            targetBox = (int)ofRandom(box.size() - 1);
            // パーティクル発生とBox削除の処理
            particles.push_back(Particle(box[i].getPosition(), box[i].getColor()));
            particles[particles.size() - 1].setup();
            box.erase(box.begin() + i);
            break;
        }
    }
}

void Hotaru::bound(ofVec3f position) {
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

int Hotaru::getRadius() {
    return radius;
}
