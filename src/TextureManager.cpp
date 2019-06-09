//
// Created by giow on 09/06/19.
//

#include "TextureManager.hpp"

// Texture Manager
SDL_Texture* TextureManager::load_texture(const char *file_name, SDL_Renderer *renderer) {
    SDL_Surface* tmp_surface = IMG_Load(file_name);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tmp_surface);
    SDL_FreeSurface(tmp_surface);

    return texture;
}