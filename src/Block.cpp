#include "Block.h"

Block::Block(const char *texture_sheet, const Pos &pos, Matrix* game_board_ref) : GameObjectSDL(texture_sheet, pos) {
  game_board_ref_ = game_board_ref;
    set_blockable(true);
    set_visible(true);
}
void Block::render() {
    if(is_visible())
        TextureManager::draw(obj_texture_, src_rect_, dest_rect_);
}
void Block::destroy() {
    if(is_destroyed())
    {
        set_visible(false);
        set_blockable(false);
    }
}
void Block::update() {
  if (game_board_ref_->at(pos_.x_, pos_.y_) != BLOCK)
  {
    set_visible(true);
    set_destroyed(true);
  }
}
bool Block::is_destroyed() const {
    return destroyed_;
}
void Block::set_destroyed(bool destroyed) {
    destroyed_ = destroyed;
}
