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

    TransformComponent(float x, float y) {
        position.x = x;
        position.y = y;
    }

    TransformComponent() {
        position.x = 0.0f;
        position.y = 0.0f;
    }

    void Update() override {

    }

};

#endif //INC_2D_GAMEENGINE_POSITIONCOMPONENT_H
