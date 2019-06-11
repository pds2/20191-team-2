#include "Block.h"
//
Block::Block(const char *texture_sheet, const Pos &pos) : GameObjectSDL(texture_sheet, pos) {
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

}
bool Block::is_destroyed() const {
    return destroyed_;
}
void Block::set_destroyed(bool destroyed) {
    destroyed_ = destroyed;
}
