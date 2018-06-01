//
// Created by MJE on 5/27/2018.
//

#include <iostream>
#include "Game.h"
#include "Map.h"
#include "ECS/Components.h"
#include "Vector2D.h"

Map *map;
Manager manager;
SDL_Renderer *Game::renderer = nullptr;
SDL_Event Game::event;
auto &player(manager.addEntity());
auto &wall(manager.addEntity());

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

    player.addComponent<TransformComponent>(2);
    player.addComponent<SpriteComponent>("../res/man_32x32.png");
    player.addComponent<KeyboardController>();
    player.addComponent<ColliderComponent>("player");

    wall.addComponent<TransformComponent>(300.0f, 300.0f, 300, 20, 1);
    wall.addComponent<SpriteComponent>("../res/wall.png");
    wall.addComponent<ColliderComponent>("wall");

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

    if (Collision::AABB(player.getComponent<ColliderComponent>().collider,
                        wall.getComponent<ColliderComponent>().collider)) {
        player.getComponent<TransformComponent>().scale = 1;
        std::cout << "wall hit\n";
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




