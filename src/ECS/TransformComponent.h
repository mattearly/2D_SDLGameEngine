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

    int speed = 3;

    TransformComponent(float x, float y) {
        position.x = x;
        position.y = y;
    }

    TransformComponent() {
        position.x = 0.0f;
        position.y = 0.0f;
    }

    void init() override {
        velocity.x = 0;
        velocity.y = 0;
    }

    void Update() override {
        position.x += velocity.x * speed;
        position.y += velocity.y * speed;
    }

};

#endif //INC_2D_GAMEENGINE_POSITIONCOMPONENT_H
