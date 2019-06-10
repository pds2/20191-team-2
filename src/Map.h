//
// Created by giow on 10/06/19.
//

#ifndef BOMBERMANC_SRC_MAP_H_
#define BOMBERMANC_SRC_MAP_H_
#include "Game.hpp"

class Map {
    SDL_Rect src_rect, dest_rect;
    SDL_Texture* tile;
    SDL_Texture* block;
    SDL_Texture* dirt;
    SDL_Texture* grass;
    SDL_Texture* water;
    int game_map_[20][25];
 public:
    Map();
     ~Map();
     void load_map(int arr[20][25]);
     void draw_map();
};

#endif //BOMBERMANC_SRC_MAP_H_
