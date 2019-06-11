//
// Created by giow on 11/06/19.
//

#include "Bomber.h"
#include "GameBoard.hpp"
Bomber::Bomber(const char *texture_sheet, const Pos &pos, Matrix* game_board_ref) : GameObjectSDL(texture_sheet, pos) {
  set_visible(true);
  game_board_ref_ = game_board_ref;
  if (game_board_ref == NULL) {
    throw std::invalid_argument("Need a valid gameboard to move through the map!");
  }

  src_rect_.x = 0;
  src_rect_.y = 0;
  src_rect_.w = 64;
  src_rect_.h = 64;

  dest_rect_.w = 64;
  dest_rect_.h = 64;
  dest_rect_.x = SPRITE_SIZE * pos_.x_;
  dest_rect_.y = SPRITE_SIZE * pos_.y_;
}
Bomber::~Bomber() {
  set_visible(false);
}
void Bomber::render() {
  if(is_visible()) {
    TextureManager::draw(obj_texture_, src_rect_, dest_rect_);
  }
}
void Bomber::destroy() {

}
void Bomber::try_to_move() {
  if (Game::event.type == SDL_KEYDOWN && Game::event.key.repeat == 0 ) {

    switch (Game::event.key.keysym.sym) {
      case SDLK_UP:
        move_down();
        break;
      case SDLK_DOWN:
        move_up();
        break;
      case SDLK_LEFT:
        move_left();
        break;
      case SDLK_RIGHT:
        move_right();
        break;
      case SDLK_SPACE:
        break_block();
        break;
    }
    if(can_move())
      move();
  }
}
bool Bomber::can_move() {
  /*Is out of the board ?*/
  if((to_move_.x_ >= game_board_ref_->cols_) ||
      (to_move_.x_ < 0) ||
      (to_move_.y_ >= game_board_ref_->cols_) ||
      (to_move_.y_ < 0))
  {
      return false;
      //*Is there a block where I want to move ?*/
  }else
    return game_board_ref_->at(to_move_.x_, to_move_.y_) == TILE;


}
bool Bomber::put_bomb() {
  if(bomb_num_ > 0)
    return true;
}
void Bomber::move()
{
  pos_.x_ = to_move_.x_;
  pos_.y_ = to_move_.y_;
}
void Bomber::update() {
  try_to_move();
  dest_rect_.x = pos_.x_ * SPRITE_SIZE;
  dest_rect_.y = pos_.y_ * SPRITE_SIZE;
}
void Bomber::reset_move() {
  to_move_.x_ = pos_.x_;
  to_move_.y_ = pos_.y_;

}
void Bomber::move_up() {
  to_move_.x_ = pos_.x_;
  to_move_.y_ = pos_.y_ + 1;
}
void Bomber::move_down() {
  to_move_.x_ = pos_.x_;
  to_move_.y_ = pos_.y_ - 1;
}

void Bomber::move_left() {
  to_move_.x_ = pos_.x_ - 1;
  to_move_.y_ = pos_.y_;
}

void Bomber::move_right() {
  to_move_.x_ = pos_.x_ + 1;
  to_move_.y_ = pos_.y_;
}
void Bomber::break_block() {
  game_board_ref_->at(pos_.x_+1, pos_.y_) = TILE;
  game_board_ref_->at(pos_.x_-1, pos_.y_) = TILE;
  game_board_ref_->at(pos_.x_, pos_.y_+1) = TILE;
  game_board_ref_->at(pos_.x_, pos_.y_-1) = TILE;
  game_board_ref_->at(pos_.x_, pos_.y_) = BOMB;
}
