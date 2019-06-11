//
// Created by giow on 07/06/19.
//

#include "GameBoard.hpp"
GameBoard::GameBoard(int size) : size_{size} {
  /*Safe tests*/
  if (size < 0) {
    throw std::invalid_argument("O tam do tabuleiro tem que ser positivo!");
  }
  if (size < MIN_BOARD_SIZE) {
    throw std::invalid_argument("O tam do tabuleiro tem que ser no minimo 3x3!");
  }
  if (size > MAX_BOARD_SIZE) {
    throw std::invalid_argument("O tam do tabuleiro tem que ser menor que 8x8!");
  }

  tile_ = TextureManager::load_texture("resources/grass.png");
  block_ = TextureManager::load_texture("resources/brick_sprite.png");

  src_rect_.x = 0;
  src_rect_.y = 0;
  src_rect_.w = SPRITE_32;
  src_rect_.h = SPRITE_32;

  dest_rect_.x = 0;
  dest_rect_.y = 0;
  dest_rect_.w = SPRITE_SIZE;
  dest_rect_.h = SPRITE_SIZE;

  set_players_pos();
  fill_board(size_);

  player = new Bomber("resources/Bomberman.png", Pos(0,0), this->board_);


}

GameBoard::~GameBoard() {
  TextureManager::destroy_texture(tile_);
  TextureManager::destroy_texture(block_);
  delete board_;
}

// Fill and shuffle array
void GameBoard::fill_shuffle_array(int *row_pos, int size, std::default_random_engine &rng) {
  // Fill Array
  for (int i = 0; i < size; i++) {
    row_pos[i] = i;
  }
  // Shuffle Array
  std::shuffle(&row_pos[0], &row_pos[size], rng);
}

// Initialize a uniform_int_distribution to produce values between 0 and max_size
std::uniform_int_distribution<int> GameBoard::get_distribution(int max_size) {
  return std::uniform_int_distribution<int>(0, max_size);
}

// Fill board randomly
void GameBoard::fill_board(int size) {
  board_ = new Matrix(size, size);

  int row_pos[size];
  int col_pos;

  // Create a random device and use it to generate a random seed
  std::random_device random_device;
  // Initialize a default_random_engine with the seed
  auto rng = std::default_random_engine(random_device());
  //rand numbers 0-Board sparseness
  auto board_sparseness = get_distribution(BOARD_SPARSENESS);
  //rand numbers 0-size-1
  auto random_col_pos = get_distribution(size - 1);

  fill_shuffle_array(row_pos, size, rng);

  // Fill Board with random pos*/
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      //Check if is a player position
      col_pos = random_col_pos(rng);
      if (is_player_pos(row_pos[i], col_pos))
        continue;

      //Sparseness
      if (board_sparseness(rng) == 1)
        continue;

      add_block(row_pos[i], col_pos);
      board_->at(row_pos[i], col_pos) = 1;
    }
  }

  /*Print Board*/
  board_->print();

}

bool GameBoard::set_players_pos() {
  int matrix_size = size_ - 1;

  this->player_position_.emplace_back(Pos(0, 0));
  this->player_position_.emplace_back(Pos(0, matrix_size));
  this->player_position_.emplace_back(Pos(matrix_size, 0));
  this->player_position_.emplace_back(Pos(matrix_size, matrix_size));
}

bool GameBoard::is_player_pos(int x, int y) {
  for (int i = 0; i < MAX_NUM_OF_PLAYERS; i++) {
    if (x == player_position_[i].x_) {
      if (y == player_position_[i].y_) {
        return true;
      }
    }
  }
  return false;
}
void GameBoard::update_obj(GameObjectSDL *game_obj) {
  game_obj->update();
}

void GameBoard::add_block(int x, int y) {
  //this->game_blocks_.emplace_back(x, y);
}
void GameBoard::render_obj(GameObjectSDL *game_obj) {
  game_obj->render();
}

void GameBoard::draw() {
  int type;

  for (int row = 0; row < this->size_; row++) {
    for (int col = 0; col < this->size_; col++) {
      type = board_->at(col, row);

      dest_rect_.x = col * SPRITE_SIZE;
      dest_rect_.y = row * SPRITE_SIZE;

      switch (type) {
        case TILE:TextureManager::draw(tile_, src_rect_, dest_rect_);
          break;
        case BLOCK:TextureManager::draw(block_, src_rect_, dest_rect_);
          break;
        default:break;
      }
    }
  }

  render_obj(player);
  player->update();
}