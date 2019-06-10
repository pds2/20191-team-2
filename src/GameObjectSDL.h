//
// Created by giow on 09/06/19.
//

#ifndef BOMBERMANC_SRC_GAMEOBJECTSDL_H_
#define BOMBERMANC_SRC_GAMEOBJECTSDL_H_

#include "Game.hpp"
#include "Position.hpp"
#include "TextureManager.hpp"

class GameObjectSDL
{
 private:
    Pos pos_;

    SDL_Texture* obj_texture_;
    SDL_Rect src_rect_;
    SDL_Rect dest_rect_;
    SDL_Renderer* renderer_;

 public:
    GameObjectSDL(const char* texture_sheet, SDL_Renderer* ren, const Pos& pos);
     ~GameObjectSDL();
    void update();
    void render();

};
#endif //BOMBERMANC_SRC_GAMEOBJECTSDL_H_
