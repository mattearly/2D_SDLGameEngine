//
// Created by MJE on 5/27/2018.
//

#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char *texturesheet, int x, int  y) {
    object_texture = TextureManager::LoadTexture(texturesheet);
    xpos = x;
    ypos = y;
}


void GameObject::Update() {
    srcRect.h = 64;
    srcRect.w = 64;
    srcRect.x = 0;
    srcRect.y = 0;

    dstRect.x = xpos;
    dstRect.y = ypos;
    dstRect.w = srcRect.w * 2;
    dstRect.h = srcRect.h * 2;
}

void GameObject::Render() {

    SDL_RenderCopy(Game::renderer, object_texture, &srcRect, &dstRect);

}