//
// Created by MJE on 5/27/2018.
//

#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char *filename) {
    SDL_Surface *tmp_surface = IMG_Load(filename);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(Game::renderer, tmp_surface);

    SDL_FreeSurface(tmp_surface);
    return texture;

}
