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
  int m_width;

 protected:
  /*Get right index*/
  int index(int x, int y) const {
    return x + m_width * y;
  }

 public:
  /*Constructor*/
  Matrix(int row, int col): m_width(row), array(new int[row * col]) {}

  /*Destructor*/
  ~Matrix() {
    delete[] array;
  }

  /*Get num from position*/
  int at(int x, int y) const {
    return array[index(x, y)];
  }

  void set(int x, int y, int value)
  {
    array[index(x,y)] = value;
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
  const int MAX_BOARD_SIZE = 8;
  const int MIN_BOARD_SIZE = 3;

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
        if(rand()%6 == 1)
          continue;
        add_block(row_pos[i], col_pos[j]);
        board.set(row_pos[i], col_pos[j], 1);
      }
    }

    /*Print Board*/
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        std::cout << board.at(i, j) << " ";
      }
      std::cout << std::endl;
    }

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