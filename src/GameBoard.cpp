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
    set_players_pos();
    fill_board(size);
}

// Fill and shuffle array
void GameBoard::fill_shuffle_array(int *row_pos, int size, std::default_random_engine &rng)
{
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
    Matrix board(size, size);
    int row_pos[size];
    int col_pos;

    // Create a random device and use it to generate a random seed
    std::random_device random_device;
    // Initialize a default_random_engine with the seed
    auto rng = std::default_random_engine (random_device());
    //rand numbers 0-Board sparseness
    auto board_sparseness = get_distribution(BOARD_SPARSENESS);
    //rand numbers 0-size-1
    auto random_col_pos = get_distribution(size-1);

    fill_shuffle_array(row_pos, size, rng);

    // Fill Board with random pos*/
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
        {
            //Check if is a player position
            col_pos = random_col_pos(rng);
            if (is_player_pos(row_pos[i], col_pos))
                continue;

            //Sparseness
            if (board_sparseness(rng) == 1)
                continue;

            add_block(row_pos[i], col_pos);
            board(row_pos[i], col_pos) = 1;
        }
    }

    /*Print Board*/
    board.print();

}

bool GameBoard::set_players_pos() {
    player_pos.emplace_back(0, 0);
    player_pos.emplace_back(0, size_ - 1);
    player_pos.emplace_back(size_ - 1, 0);
    player_pos.emplace_back(size_ - 1, size_ - 1);
}

bool GameBoard::is_player_pos(int x, int y) {
    for (int i = 0; i < MAX_NUM_OF_PLAYERS; i++) {
        if (x == player_pos[i].first) {
            if (y == player_pos[i].second) {
                return true;
            }
        }
    }

    return false;
}
void GameBoard::add_block(int x, int y) {
    this->game_blocks_.emplace_back(x, y);
}