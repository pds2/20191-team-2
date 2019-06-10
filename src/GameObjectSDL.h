//
// Created by giow on 09/06/19.
//

#ifndef BOMBERMANC_SRC_GAMEOBJECTSDL_H_
#define BOMBERMANC_SRC_GAMEOBJECTSDL_H_

#include <SDL_render.h>
#include "Position.hpp"
class GameObjectSDL
{
 public:
    GameObjectSDL(const char* texture_sheet, SDL_Renderer* ren);
     GameObjectSDL();

     void update();
     void render();
 private:
    Pos pos_;

    SDL_Texture* obj_texture;
    SDL_Rect src_rect, dest_rect;
    SDL_Renderer* renderer_;
};
#endif //BOMBERMANC_SRC_GAMEOBJECTSDL_H_
