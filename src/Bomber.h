//
// Created by giow on 11/06/19.
//

#ifndef BOMBERMANC_SRC_BOMBER_H_
#define BOMBERMANC_SRC_BOMBER_H_
#include "GameObjectSDL.h"
#include "ObjTypes.h"
#include "Matrix.hpp"

class Bomber : public GameObjectSDL
{
  //KeyboardController controller_;
  int bomb_num_;
  Matrix* game_board_ref_;
 public:
  Bomber(const char *texture_sheet, const Pos &pos, Matrix* game_board_ref);
  virtual ~Bomber();
  void render() override;
  void destroy() override;
  void update() override;
  virtual void try_to_move();
  void move_up();
  void move_down();
  void move_left();
  void move_right();
  void reset_move();
  void move();
  bool put_bomb();
  bool can_move();
  Pos to_move_;
  bool moving_ = false;
  void break_block();
};

#endif //BOMBERMANC_SRC_BOMBER_H_
