//
//  Particle.hpp
//  ofVboParticle
//
//  Created by 斉藤俊介 on 2018/05/26.
//

#ifndef Particle_hpp
#define Particle_hpp

#include <stdio.h>
#include "ofMain.h"

#endif /* Particle_hpp */

class Particle {
    public :
        Particle();
        // 初期設定
        void setup(ofVec2f _position, ofVec2f _velocity);
        // 力をリセット
        void reserForce();
        // 力を加える
        void addForce(ofVec2f _force);
        // 力を更新
        void updateForce();
        // 位置の更新
        void updatePos();
        // 更新（位置と力）
        void update();
        // 画面からはみ出たらバウンドさせる
        void bounceOffWalls();
        // 画面からはみ出たら反対側に出現
        void throughOfWalls();
        // 描画
        void draw();
        // 引力
        void addAttractionForce(ofVec2f posOfForce, float radius, float scale);
        // 反発力
        void addRepulsionForce(ofVec2f posOfForce, float radius, float scale);
        // 位置ベクトルの配列
        ofVec2f position;
        // 速度ベクトルの配列
        ofVec2f velocity;
        // 力ベクトルの配列
        ofVec2f force;
        // 摩擦係数
        float friction;
        // パーティクルの半径
        float radius;
        // 固定するかどうか
        bool bFixed;
        // パーティクルの質量
        float mass;
};
