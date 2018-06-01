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
    TransformComponent *transform;
    SDL_Texture *texture;
    SDL_Rect srcRect, dstRect;

public:

    SpriteComponent() = default;

    SpriteComponent(const char *filepath) {
        setTexture(filepath);
    }

    ~SpriteComponent() {
        SDL_DestroyTexture(texture);
    }

    void setTexture(const char *filepath) {
        texture = TextureManager::LoadTexture(filepath);
    }

    void init() override {
        transform = &entity->getComponent<TransformComponent>();
        srcRect.x = srcRect.y = 0;

        srcRect.w = transform->width;
        srcRect.h = transform->height;

//        dstRect.w = dstRect.h = 64;

    }

    void Update() override {
        dstRect.x = static_cast<int>(transform->position.x);
        dstRect.y = static_cast<int>(transform->position.y);
        dstRect.w = transform->width * transform->scale;
        dstRect.h = transform->height * transform->scale;
    }

    void Draw() override {
        TextureManager::Draw(texture, srcRect, dstRect);

    }
};


#endif //INC_2D_GAMEENGINE_SPRITECOMPONENT_H
