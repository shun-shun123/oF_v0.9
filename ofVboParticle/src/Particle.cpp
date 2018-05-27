//
//  Particle.cpp
//  ofVboParticle
//
//  Created by 斉藤俊介 on 2018/05/26.
//

#include "Particle.hpp"

Particle::Particle() {
    radius = 0.5;
    friction = 0.01;
    mass = 1.0;
    bFixed = false;
}

void Particle::setup(ofVec2f _position, ofVec2f _velocity) {
    // 位置を設定
    position = _position;
    // 初期速度を設定
    velocity = _velocity;
}

// 力をリセット
void Particle::reserForce() {
    force.set(0, 0);
}

// 力を加える
void Particle::addForce(ofVec2f _force) {
    force += _force / mass;
}

// 摩擦力の更新
void Particle::updateForce() {
    force -= velocity * friction;
}

// 位置の更新
void Particle::updatePos() {
    if (!bFixed) {
        velocity += force;
        position += velocity;
    }
}

// 力の更新と座標の更新をupdateとしてまとめる
void Particle::update() {
    updateForce();
    updatePos();
}

// 画面の端でバウンドする(改定版)
void Particle::bounceOffWalls(){
    bool bDampedOnCollision = false;
    bool bDidICollide = false;
    
    float minx = 0;
    float miny = 0;
    float maxx = ofGetWidth();
    float maxy = ofGetHeight();
    
    if (position.x > maxx){
        position.x = maxx;
        velocity.x *= -1;
        bDidICollide = true;
    } else if (position.x < minx){
        position.x = minx;
        velocity.x *= -1;
        bDidICollide = true;
    }
    
    if (position.y > maxy){
        position.y = maxy;
        velocity.y *= -1;
        bDidICollide = true;
    } else if (position.y < miny){
        position.y = miny;
        velocity.y *= -1;
        bDidICollide = true;
    }
    
    if (bDidICollide == true && bDampedOnCollision == true){
        velocity *= 0.3;
    }
}

void Particle::throughOfWalls(){
    float minx = 0;
    float miny = 0;
    float maxx = ofGetWidth();
    float maxy = ofGetHeight();
    if (position.x < minx) {
        position.x = maxx;
    }
    if (position.y < miny) {
        position.y = maxy;
    }
    if (position.x > maxx) {
        position.x = minx;
    }
    if (position.y > maxy) {
        position.y = miny;
    }
}

// 描画
void Particle::draw(){
    ofDrawCircle(position, radius);
}

// 引力
void Particle::addAttractionForce(ofVec2f posOfForce, float radius, float scale) {
    // パーティクルと力の中心点との距離を測定
    ofVec2f diff = position - posOfForce;
    float length = diff.length();
    // 力が働く範囲かどうかを判定する変数
    bool bAmCloseEnough = true;
    // もし設定した半径より外側だったら、計算しない
    if (radius > 0) {
        if (length > radius) {
            bAmCloseEnough = false;
        }
    }
    if (bAmCloseEnough) {
        // 距離から点にかかる力ベクトルを計算
        float pct = 1 - (length / radius);
        diff.normalize();
        force.x = force.x - diff.x * scale * pct;
        force.y = force.y - diff.y * scale * pct;
    }
}

// 反発する力
void Particle::addRepulsionForce(ofVec2f posOfForce, float radius, float scale) {
    // パーティクルと力の中心点との距離を計算
    ofVec2f diff = position - posOfForce;
    float length = diff.length();
    // 力が働く範囲かどうか判定する変数
    bool bAmCloseEnough = true;
    // もし設定した半径より外側だったら計算しない
    if (radius > 0) {
        if (length > radius) {
            bAmCloseEnough = false;
        }
    }
    // 設定した半径の内側だったら
    if (bAmCloseEnough) {
        // 距離から点にかかる力ベクトルを計算
        float pct = 1 - (length / radius);
        diff.normalize();
        force.x = force.x + diff.x * scale * pct;
        force.y = force.y + diff.y * scale * pct;
    }
}
