//
// Created by MJE on 5/27/2018.
//

#ifndef INC_2D_GAMEENGINE_TEXTUREMANAGER_H
#define INC_2D_GAMEENGINE_TEXTUREMANAGER_H

#include "Game.h"

class TextureManager {
public:
    static SDL_Texture *LoadTexture(const char *file_name, SDL_Renderer *ren);
};

#endif //INC_2D_GAMEENGINE_TEXTUREMANAGER_H
