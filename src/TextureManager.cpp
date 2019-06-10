//
// Created by giow on 09/06/19.
//

#include "TextureManager.hpp"

// Texture Manager
SDL_Texture* TextureManager::load_texture(const char *file_name) {
    SDL_Surface* tmp_surface = IMG_Load(file_name);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer_, tmp_surface);
    SDL_FreeSurface(tmp_surface);

    if(texture == NULL)
    {
        std::cerr <<   "Obj " << file_name <<  " Texture not loaded!" << std::endl;
    }
    return texture;
}

void TextureManager::draw(SDL_Texture *texture, SDL_Rect src_rect, SDL_Rect dest_rect) {
    SDL_RenderCopy(Game::renderer_, texture, &src_rect, &dest_rect);
}