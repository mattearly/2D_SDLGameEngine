//
// Created by MJE on 6/1/2018.
//

#ifndef INC_2D_GAMEENGINE_COLLIDERCOMPONENT_H
#define INC_2D_GAMEENGINE_COLLIDERCOMPONENT_H
#include <string>
#include <SDL2/SDL.h>
#include "Components.h"
#include "Collision.h"

class ColliderComponent : public Component {
public:
    SDL_Rect collider;
    std::string tag;

    TransformComponent *transform;

    ColliderComponent(std::string t) {
        tag = t;
    }

    void init() override {
        if (!entity->hasComponent<TransformComponent>()){
            entity->addComponent<TransformComponent>();
        }
        transform = &entity->getComponent<TransformComponent>();

    }

    void Update() override  {
        collider.x = static_cast<int>(transform->position.x);
        collider.y = static_cast<int>(transform->position.y);

        collider.w = transform->width * transform->scale;
        collider.h = transform->height * transform->scale;
    }
};

#endif //INC_2D_GAMEENGINE_COLLIDERCOMPONENT_H
