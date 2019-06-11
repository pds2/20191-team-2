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

/*
void GameObjectSDL::update()
{

pos_(pos_.x_ + 1, pos_.y_ + 1);


src_rect_.h = 32;
src_rect_.w = 32;
src_rect_.x = 0;
src_rect_.y = 0;

dest_rect_.x = pos_.x_;
dest_rect_.y = pos_.y_;

//Scale of the PNG
dest_rect_.h = src_rect_.h * 2;
dest_rect_.w = src_rect_.w * 2;

}
*/

/*
void GameObjectSDL::render()
{
    TextureManager::draw(obj_texture_, src_rect_, dest_rect_);
}
*/

bool GameObjectSDL::is_blockable() const {
    return blockable_;
}

void GameObjectSDL::set_blockable(bool blockable) {
    blockable_ = blockable;
}

bool GameObjectSDL::is_visible() const {
    return visible_;
}

void GameObjectSDL::set_visible(bool visible) {
    visible_ = visible;
}
GameObjectSDL::~GameObjectSDL() {
/*Delete texture used by object when deleting*/
    TextureManager::destroy_texture(this->obj_texture_);
}

