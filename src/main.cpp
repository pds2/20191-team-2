#include <iostream>
#include <gtest/gtest.h>
#include "GameBoard.hpp"
#include "SDL.h"
#include "Game.hpp"

Game *game = nullptr;

int main(int argc, char *argv[]) {

    const int FPS = 60;
    const int frame_delay = 1000/FPS;

    Uint32 frame_start;
    int frame_time;

    testing::InitGoogleTest(&argc, argv);
    int value =  RUN_ALL_TESTS();
    std::cout << "Return Value of the Tests: " << value << std::endl;
    auto game_board = GameBoard(8);

    game = new Game();
    game->init("BomberEngine!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
    std::cout << "Game Running: " << game->running() << std::endl;
    while(game->running())
    {
        frame_start = SDL_GetTicks();

        game->handle_events();
        game->update();
        game->render();

        frame_time = SDL_GetTicks() - frame_start;

        if(frame_delay  > frame_time)
        {
            SDL_Delay(frame_delay - frame_time);
        }
    }
    game->clean();
}