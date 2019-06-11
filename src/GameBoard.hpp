//
// Created by giow on 07/06/19.
//

#ifndef BOMBERMANC_SRC_GAMEBOARD_HPP_
#define BOMBERMANC_SRC_GAMEBOARD_HPP_
#include <algorithm>
#include "TextureManager.hpp"
#include "Position.hpp"
#include "Matrix.hpp"
#include "ObjTypes.h"
#include "Block.h"
#include "Bomber.h"

const int BOARD_SPARSENESS = 4;
const int MAX_BOARD_SIZE = 8;
const int MIN_BOARD_SIZE = 3;
const int MAX_NUM_OF_PLAYERS = 4;
const int SPRITE_32 = 32;
const int SPRITE_64 = 64;
const int SPRITE_SIZE = 100;
const int GAME_BOARD_SIZE = 8;


class GameBoard {
  SDL_Rect src_rect_, dest_rect_;

  SDL_Texture* tile_;
  SDL_Texture* block_;

 public:
  std::vector<Pos> player_position_;
  std::vector<Bomber* > players;
  Bomber *player;
  Matrix* board_;
  explicit GameBoard(int size);

  // Fill and shuffle array
  void fill_shuffle_array(int *row_pos, int size, std::default_random_engine &rng);

  // Initialize a uniform_int_distribution to produce values between 0 and max_size
  std::uniform_int_distribution<int> get_distribution(int max_size);

  // Fill map with blocks
  void fill_board(int size);

  // Set player pos according to map size
  bool set_players_pos();

  // Check if is a player position
  bool is_player_pos(int x, int y);

  // Add block to map
  void add_block(int x, int y);

  void draw();

  void render_obj(GameObjectSDL* game_obj);

  void update_obj(GameObjectSDL* game_obj);

  virtual ~GameBoard();
//std::vector<Block> game_blocks_;
int size_;
};

#endif //BOMBERMANC_SRC_GAMEBOARD_HPP_
