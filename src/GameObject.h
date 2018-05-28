//
// Created by MJE on 5/27/2018.
//

#ifndef INC_2D_GAMEENGINE_GAMEOBJECT_H
#define INC_2D_GAMEENGINE_GAMEOBJECT_H


#include <SDL2/SDL_render.h>

class GameObject {

public:
    GameObject(const char *texturesheet, SDL_Renderer *ren, int x, int y);
    ~GameObject();

    void Update();
    void Render();

private:
    int xpos;
    int ypos;

    SDL_Texture *object_texture;
    SDL_Rect srcRect, dstRect;
    SDL_Renderer *renderer;

};


#endif //INC_2D_GAMEENGINE_GAMEOBJECT_H
