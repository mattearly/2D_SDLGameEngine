//
// Created by MJE on 5/30/2018.
//

#ifndef INC_2D_GAMEENGINE_POSITIONCOMPONENT_H
#define INC_2D_GAMEENGINE_POSITIONCOMPONENT_H

#include "Components.h"
#include "../Vector2D.h"

class TransformComponent : public Component {
private:

public:

    Vector2D position;

    Vector2D velocity;

    int height = 32;
    int width = 32;
    int scale = 1;

    int speed = 3;


    TransformComponent(int sc) {
        scale = sc;
    }

    TransformComponent(float x, float y, int h, int w, int sc) {
        position.x = x;
        position.y = y;
        height = h;
        width = w;
        scale = sc;
    }

    TransformComponent() {
        velocity.Zero();
    }

    void init() override {
        velocity.Zero();
    }

    void Update() override {
        position.x += velocity.x * speed;
        position.y += velocity.y * speed;
    }

};

#endif //INC_2D_GAMEENGINE_POSITIONCOMPONENT_H
