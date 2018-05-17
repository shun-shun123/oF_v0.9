//
//  SceneLogo.hpp
//  Bird
//
//  Created by 斉藤俊介 on 2018/05/16.
//

#ifndef SceneLogo_hpp
#define SceneLogo_hpp

#include <stdio.h>
#include "SceneHotaru.hpp"

#endif /* SceneLogo_hpp */

#define BOX_NUM 29
#define PARTICLE_NUM 60

class SceneLogo : public Particle {
    public :
        void setup(vector<Particle *> _particles);
        void update();
        void draw();
    private :
        vector<Particle *> particles;
        ofVec3f aim[BOX_NUM][PARTICLE_NUM];
        ofTrueTypeFont verdana;
};
