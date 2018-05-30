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

    void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);

    void handleEvents();

    void Update();

    void render();

    void clean();

    bool running() { return isRunning; }

    static SDL_Renderer *renderer;

private:
    bool isRunning;
    SDL_Window *window;
    SDL_Event event;


};


#endif //INC_2D_GAMEENGINE_GAME_H
