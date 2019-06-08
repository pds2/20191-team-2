//
// Created by giow on 07/06/19.
//

#ifndef BOMBERMANC_SRC_GAMEBOARD_H_
#define BOMBERMANC_SRC_GAMEBOARD_H_
#include <algorithm>
#include "Position.h"
#include "GameObject.h"
#include "Matrix.h"
#include "Block.h"

class GameBoard {
    const int BOARD_SPARSENESS = 4;
    enum players{
        player1, player2, player3, player4
    };
    std::vector<std::pair<int, int>> player_pos;
    const int MAX_BOARD_SIZE = 8;
    const int MIN_BOARD_SIZE = 3;
    const int MAX_NUM_OF_PLAYERS = 4;

    std::vector<Block> game_blocks_;
    const int size_;

 public:

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
};


#endif //BOMBERMANC_SRC_GAMEBOARD_H_
