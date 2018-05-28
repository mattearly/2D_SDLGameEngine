//
// Created by MJE on 5/27/2018.
//

#include <iostream>
#include "Game.h"
#include "TextureManager.h"

SDL_Texture *player_texture;
SDL_Rect srcRect, dstRect;

Game::Game() = default;

Game::~Game() = default;

void Game::init(const char *title, int xpos, int ypos, int width, int heigh, bool fullscreen) {
    update_count = 0;

    //handle fullscreen flags
    Uint32 flags = 0;
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        window = SDL_CreateWindow(title, xpos, ypos, width, heigh, flags);
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) { SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); }
        isRunning = true;
    } else { isRunning = false; }

    player_texture = TextureManager::LoadTexture("../res/man_64x64.png", renderer);
//    SDL_Surface *tmp_surface = IMG_Load("../res/man_64x64.png");
//    player_texture = SDL_CreateTextureFromSurface(renderer, tmp_surface);
//    SDL_FreeSurface(tmp_surface);


}

void Game::handleEvents() {
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }
}

void Game::update() {
    update_count++;
    dstRect.h = 64;
    dstRect.w = 64;
    dstRect.x = update_count;
    std::cout << update_count << std::endl;

}

void Game::render() {
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, player_texture, nullptr, &dstRect);

    SDL_RenderPresent(renderer);
}

void Game::clean() {

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

}




