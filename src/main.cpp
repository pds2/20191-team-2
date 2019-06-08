#include <iostream>
#include <gtest/gtest.h>
#include "GameBoard.h"

int main(int argc, char *argv[]) {

    auto game_board = GameBoard(8);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}