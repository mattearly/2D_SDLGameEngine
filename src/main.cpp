#include "Game.h"

Game *game = nullptr;

int main(int argc, char *argv[]) {

    const int FPS = 60;
    const int frame_delay = 1000 / FPS;

    Uint32 frame_start;

    int frame_time;

    game = new Game();

    game->init("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

    while (game->running()) {

        frame_start = SDL_GetTicks();

        game->handleEvents();
        game->Update();
        game->render();

        frame_time = SDL_GetTicks() - frame_start;

        if (frame_delay  > frame_time) {
            SDL_Delay(frame_delay - frame_time);
        }

    }

    game->clean();

    return 0;
}