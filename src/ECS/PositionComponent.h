//
// Created by MJE on 5/30/2018.
//

#ifndef INC_2D_GAMEENGINE_POSITIONCOMPONENT_H
#define INC_2D_GAMEENGINE_POSITIONCOMPONENT_H

#include "EntityComponentSystem.h"

class PositionComponent : public Component {
private:
    int xpos;
    int ypos;

public:

    PositionComponent(int x, int y) {
        xpos = x;
        ypos = y;
    }

    PositionComponent() {
        xpos = 0;
        ypos = 0;
    }

    int x() { return xpos; }

    int y() { return ypos; }

    void init() override {
        xpos = 0;
        ypos = 0;
    }

    void Update() override {
        xpos++;
        ypos++;
    }

//    void setx(int x) { xpos = x; }
//
//    void sety(int y) { xpos = y; }
//
//    void setPos(int x, int y) {
//        xpos = x;
//        ypos = y;
//    }
};

#endif //INC_2D_GAMEENGINE_POSITIONCOMPONENT_H
