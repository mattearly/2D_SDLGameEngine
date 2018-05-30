//
// Created by MJE on 5/27/2018.
//

#ifndef INC_2D_GAMEENGINE_TEXTUREMANAGER_H
#define INC_2D_GAMEENGINE_TEXTUREMANAGER_H

#include "../Game.h"

class TextureManager {
public:
    static SDL_Texture *LoadTexture(const char *file_name);
    static void Draw(SDL_Texture* texture, SDL_Rect &srcR, SDL_Rect &dstR);
};

#endif //INC_2D_GAMEENGINE_TEXTUREMANAGER_H
