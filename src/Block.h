
#ifndef BOMBERMANC_SRC_BLOCK_H_
#define BOMBERMANC_SRC_BLOCK_H_

#include "GameObjectSDL.h"
#include "Matrix.hpp"
#include "ObjTypes.h"

class Block : public GameObjectSDL
{
 private:
    bool destroyed_;
  Matrix* game_board_ref_;

 public:
    bool is_destroyed() const;
    void set_destroyed(bool destroyed);
 public:
    Block(const char *texture_sheet, const Pos &pos, Matrix* game_board_ref);
    void render() override;
    void destroy() override;
    void update() override;
};
#endif //BOMBERMANC_SRC_BLOCK_H_
