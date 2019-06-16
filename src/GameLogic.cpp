// Going to refactor game logic here

#include "Matrix.hpp"
#include "ObjTypes.h"
#include <random>
#include <algorithm>

/*
 * First we need a matrix, for the game board
 * Second, we need to define what is the representation of the objects
 * on the matrix.
 * Third, make objects and game logic
 */

const int BOARD_SIZE = 3;

const int BLOCK_PROB =  3; // 1/x
const int ITEM_BLOCK_PROB =  4;

class GameBoardLogic
{
    Matrix game_board;

    void generate_random_board()
    {
        int row_pos[game_board.rows_];
        int col_pos[game_board.cols_];

        // Create a random device and use it to generate a random seed
        std::random_device random_device;
        // Initialize a default_random_engine with the seed
        auto rng = std::default_random_engine(random_device());

        //rand numbers 0-Board sparseness
        auto blocks = std::uniform_int_distribution<int>(0, BLOCK_PROB);
        //rand numbers 0->row-1
        auto item_blocks = std::uniform_int_distribution<int>(0, ITEM_BLOCK_PROB);

        // Generate Board
        for (int i = 0; i < game_board.rows_; ++i) {
            for (int j = 0; j < game_board.cols_; ++j) {
                // Set unbreakable blocks if it's odd col position
                if (!col_pos[j]%2 != 0)
                    game_board(row_pos[i], col_pos[j] = UNBREAKEABLE_BLOCK);
                // Set blocks and tiles randomly
                else if(blocks(rng) == 1)
                    game_board(row_pos[i], col_pos[j]) = BLOCK;
                else if (item_blocks(rng) == 1)
                    game_board(row_pos[i], col_pos[j]) = ITEM_BLOCK;
                else
                    continue;
            }
        }

        // Fix Player position area
        game_board(0,0) = PLAYER;
        game_board(1,0) = TILE;
        game_board(0,1) = TILE;

        // Fix P2
        game_board(game_board.rows_-1, 0) = PLAYER;
        game_board(game_board.rows_-2, 0) = TILE;
        game_board(game_board.rows_-1, 1) = TILE;

        // P3
        game_board(0, game_board.cols_-1) = PLAYER;
        game_board(0, game_board.cols_-2) = TILE;
        game_board(1, game_board.cols_-1) = TILE;

        // P4
        game_board(game_board.rows_-1, game_board.cols_-1) = PLAYER;
        game_board(game_board.rows_-2, game_board.cols_-1) = TILE;
        game_board(game_board.rows_-1, game_board.cols_-2) = TILE;


        game_board.print();
    }

    GameBoardLogic(int rows, int cols) : game_board(rows, cols)
    {
        if(rows < 5 || cols < 5 || rows < 0 || cols < 0) {
            throw std::invalid_argument("Entrada invalida");
        }
        generate_random_board();
    }
};