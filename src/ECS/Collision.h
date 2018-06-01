//
// Created by MJE on 6/1/2018.
//

#ifndef INC_2D_GAMEENGINE_COLLISION_H
#define INC_2D_GAMEENGINE_COLLISION_H

#include <SDL2/SDL_rect.h>

class Collision {
public:
    static bool AABB(const SDL_Rect& rectA, const SDL_Rect& rectB); //access align bounding box

};
#endif //INC_2D_GAMEENGINE_COLLISION_H
