//
// Created by MJE on 5/27/2018.
//

#ifndef INC_2D_GAMEENGINE_GAME_H
#define INC_2D_GAMEENGINE_GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Game {

public:
    Game();

    ~Game();

    void init(const char *title, int xpos, int ypos, int width, int heigh, bool fullscreen);

    void handleEvents();

    void update();

    void render();

    void clean();

    bool running() { return isRunning; }

private:
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;
    int update_count;


};


#endif //INC_2D_GAMEENGINE_GAME_H
