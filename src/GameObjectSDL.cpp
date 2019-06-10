//
// Created by giow on 09/06/19.
//
#include "GameObjectSDL.h"

GameObjectSDL::GameObjectSDL(const char* texture_sheet, const Pos& pos)
{
    obj_texture_ = TextureManager::load_texture(texture_sheet);

    pos_.x_ = pos.x_;
    pos_.y_ = pos.y_;
}

void GameObjectSDL::update()
{
    pos_(pos_.x_ + 1, pos_.y_ + 1);

    //Scale of the PNG
    src_rect_.h = 32;
    src_rect_.w = 32;
    src_rect_.x = 0;
    src_rect_.y = 0;

    dest_rect_.x = pos_.x_;
    dest_rect_.y = pos_.y_;
    dest_rect_.h = src_rect_.h * 2;
    dest_rect_.w = src_rect_.w * 2;
}

void GameObjectSDL::render()
{
    TextureManager::draw(obj_texture_, src_rect_, dest_rect_);
    //SDL_RenderCopy(Game::renderer_, obj_texture_, &src_rect_, &dest_rect_);
    //SDL_RenderCopy(Game::renderer_, obj_texture_, NULL, &dest_rect_);
}

