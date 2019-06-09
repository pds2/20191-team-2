//
// Created by giow on 09/06/19.
//

#ifndef BOMBERMANC_SRC_TEXTUREMANAGER_HPP_
#define BOMBERMANC_SRC_TEXTUREMANAGER_HPP_

#include "Game.hpp"

class TextureManager
{
 public:
    static SDL_Texture* load_texture(const char* file_name, SDL_Renderer* renderer);
};

#endif //BOMBERMANC_SRC_TEXTUREMANAGER_HPP_
