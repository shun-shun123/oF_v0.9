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
        void reverseX(vector<ofPolyline>& lines);
    private :
        ofEasyCam cam;
        vector<Particle *> particles;
        ofTrueTypeFont verdana;
        vector<ofPolyline> firstLetter;
        vector<ofPolyline> secondLetter;
        vector<ofPolyline> thirdLetter;
        vector<ofPolyline> fourthLetter;
    ofVec3f letterL[3];
};
