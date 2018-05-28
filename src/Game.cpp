//
// Created by MJE on 5/27/2018.
//

#include <iostream>
#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"

GameObject *main_player, *enemy_player;
Map *map;

SDL_Renderer *Game::renderer = nullptr;

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

    main_player = new GameObject("../res/man_64x64.png", 0, 0);
    enemy_player = new GameObject("../res/enemy_64x64.png", 768, 0);
    map = new Map();

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
    main_player->Update();
    enemy_player->Update();
    std::cout << update_count << std::endl;

}

void Game::render() {
    SDL_RenderClear(renderer);
    map->DrawMap();
    main_player->Render();
    enemy_player->Render();
    SDL_RenderPresent(renderer);
}

void Game::clean() {

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

}




