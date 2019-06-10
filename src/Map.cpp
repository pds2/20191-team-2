//
// Created by giow on 10/06/19.
//

#include "Map.h"
#include "TextureManager.hpp"

int lvl1 [20][25] = {
    {0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};

Map::Map() {
    dirt = TextureManager::load_texture("resources/dirt.png");
    grass = TextureManager::load_texture("resources/grass.png");
    water = TextureManager::load_texture("resources/water.png");
    load_map(lvl1);

    src_rect.x = 0;
    src_rect.y = 0;
    src_rect.w = 32;
    src_rect.h = 32;

    dest_rect.x = 0;
    dest_rect.y = 0;
    dest_rect.w = 32;
    dest_rect.h = 32;
}
Map::~Map() {

}
void Map::load_map(int arr[20][25]) {
    for(int row = 0; row < 20; row++)
    {
        for(int col = 0; col < 25; col++)
        {
            game_map_[row][col] = arr[row][col];
        }
    }
}
void Map::draw_map() {
    int type = 0;
    for(int row = 0; row < 20; row++)
    {
        for(int col = 0; col < 25; col++)
        {
            type = game_map_[row][col];

            dest_rect.x = col*32;
            dest_rect.y = row*32;

            switch (type)
            {
                case 0:
                    TextureManager::draw(water, src_rect, dest_rect);
                    break;
                case 1:
                    TextureManager::draw(grass, src_rect, dest_rect);
                    break;
                case 2:
                    TextureManager::draw(dirt, src_rect, dest_rect);
                    break;
                default:
                    break;
            }
        }
    }
}
