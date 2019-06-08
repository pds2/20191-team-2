#include <iostream>
#include <gtest/gtest.h>
#include "GameBoard.hpp"
#include "SDL.h"
#include "Game.hpp"

Game *game = nullptr;

int main(int argc, char *argv[]) {


    testing::InitGoogleTest(&argc, argv);
    int value =  RUN_ALL_TESTS();
    std::cout << "Return Value of the Tests: " << value << std::endl;
    auto game_board = GameBoard(8);

    game = new Game();
    game->init("BomberEngine!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

    while(game->running())
    {
        game->handle_events();
        game->update();
        game->render();
    }
    game->clean();
}