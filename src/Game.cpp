//
// Created by MJE on 5/27/2018.
//

#include <iostream>
#include "Game.h"
#include "Map.h"
#include "ECS/Components.h"

Map *map;

SDL_Renderer *Game::renderer = nullptr;

Manager manager;

auto &player(manager.addEntity());

Game::Game() = default;

Game::~Game() = default;

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) {

    //handle fullscreen flags
    Uint32 flags = 0;
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) { SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); }
        isRunning = true;
    } else { isRunning = false; }

    map = new Map();

    player.addComponent<PositionComponent>(500, 500);
    player.addComponent<SpriteComponent>("../res/man_64x64.png");

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

void Game::Update() {

    manager.refresh();
    manager.Update();

    if (player.getComponent<PositionComponent>().x() > 100) {
        player.addComponent<SpriteComponent>().setTexture("../res/enemy_64x64.png");
    }

}

void Game::render() {
    SDL_RenderClear(renderer);
    map->DrawMap();
    manager.Draw();

    SDL_RenderPresent(renderer);
}

void Game::clean() {

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

}




