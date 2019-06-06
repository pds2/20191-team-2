#include <random>

#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include <chrono>

/*Game Object Struct*/
struct GameObject {
 public:
  virtual void show() = 0;
};

/*Great locality 2d int matrix*/
class Matrix {
  int *array;
  int width_;

 protected:
  /*Get right index*/
  int index(int x, int y) const {
    return x + width_ * y;
  }

 public:
  /*Constructor*/
  Matrix(int row, int col): width_(row), array(new int[row * col]) {}

  /*Destructor*/
  ~Matrix() {
    delete[] array;
  }

  /*Get num from position*/
  int at(int row, int col) const {
    return array[index(row, col)];
  }

  void set(int row, int col, int value)
  {
    array[index(row,col)] = value;
  }
  void print_matrix()
  {
    /*Print Board*/
    for (int i = 0; i < width_; i++) {
      for (int j = 0; j < width_; j++) {
        std::cout << this->at(i, j) << " ";
      }
      std::cout << std::endl;
    }
  }
};

struct Pos {
  int x_, y_;
  int get_x() const {
    return x_;
  }
  void set_x(int x) {
    x_ = x;
  }
  int get_y() const {
    return y_;
  }
  void set_y(int y) {
    y_ = y;
  }
};

class Block : public GameObject {
  Pos pos_;

 public:
  Block(int x, int y) {
    pos_.set_x(x);
    pos_.set_y(y);
  }

  void show() override {
    std::cout << "I'm a block at: " << pos_.get_x() << ',' << pos_.get_y() << std::endl;
  }
};

class GameBoard {
  enum players{player1, player2, player3, player4};
  std::vector<std::pair<int, int>> player_pos;
  const int MAX_BOARD_SIZE = 8;
  const int MIN_BOARD_SIZE = 3;
  const int MAX_NUM_OF_PLAYERS = 4;

  std::vector<Block> game_blocks_;
  int row, column;

  const int size_;

 public:

  GameBoard(int size) : size_{size} {
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
    set_players_pos();
    fill_board(size);
  }

  void fill_board(int size) {
    Matrix board(size, size);

    int row_pos[size];
    int col_pos[size];

    for (int i = 0; i < size; i++) {
      row_pos[i] = i;
      col_pos[i] = i;
    }

    std::shuffle(&row_pos[0], &row_pos[size], std::mt19937(std::random_device()()));
    std::shuffle(&col_pos[0], &col_pos[size], std::mt19937(std::random_device()()));

    /*Fill Board with zeros*/
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        board.set(row_pos[i], col_pos[j], 0);
      }
    }
    
    /*Fill Board with random pos*/
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        if(rand()% 3 == 1 || is_player_pos(row_pos[i], col_pos[j]))
          continue;
        add_block(row_pos[i], col_pos[j]);
        board.set(row_pos[i], col_pos[j], 1);
      }
    }

    /*Print Board*/
    board.print_matrix();

  }
  bool set_players_pos()
  {
    player_pos.emplace_back(0, 0);
    player_pos.emplace_back(0, size_-1);
    player_pos.emplace_back(size_-1, 0);
    player_pos.emplace_back(size_-1, size_-1);
  }

  bool is_player_pos(int x, int y)
  {
    for(int i = 0; i < MAX_NUM_OF_PLAYERS; i++)
    {
      if(x == player_pos[i].first)
      {
        if(y == player_pos[i].second)
        {
          return true;
        }
      }
    }

    return false;
  }
  void add_block(int x, int y) {
    this->game_blocks_.emplace_back(x, y);
  }
};

int main(int argc, char *argv[]) {

  auto game_board = GameBoard(8);
  std::cout << "Hellow Worlds" << std::endl;
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}