//
// Created by MJE on 5/30/2018.
//

#ifndef INC_2D_GAMEENGINE_SPRITECOMPONENT_H
#define INC_2D_GAMEENGINE_SPRITECOMPONENT_H

#include "EntityComponentSystem.h"
#include "../TextureManager.h"
#include <SDL2/SDL.h>

class SpriteComponent : public Component {

private:
    TransformComponent *transformComponent;
    SDL_Texture *texture;
    SDL_Rect srcRect, dstRect;

public:

    SpriteComponent() = default;

    SpriteComponent(const char *filepath) {
        setTexture(filepath);
    }

    void setTexture(const char *filepath) {
        texture = TextureManager::LoadTexture(filepath);
    }

    void init() override {
        transformComponent = &entity->getComponent<TransformComponent>();
        srcRect.x = srcRect.y = 0;
        srcRect.w = srcRect.h = 64;

        dstRect.w = dstRect.h = 64;


    }

    void Update() override {
        dstRect.x = (int) transformComponent->position.x;
        dstRect.y = (int) transformComponent->position.y;
    }

    void Draw() override {
        TextureManager::Draw(texture, srcRect, dstRect);

    }
};


#endif //INC_2D_GAMEENGINE_SPRITECOMPONENT_H
