//
// Created by MJE on 5/27/2018.
//

#ifndef INC_2D_GAMEENGINE_MAP_H
#define INC_2D_GAMEENGINE_MAP_H
#include "Game.h"

class Map {
public:
    Map();
    ~Map();

    void LoadMap(int level_map[20][25]);
    void DrawMap();

private:
    SDL_Rect srcRect, dstRect;
    SDL_Texture *dirt, *grass, *water;

    int level_map[20][25];

};


#endif //INC_2D_GAMEENGINE_MAP_H
