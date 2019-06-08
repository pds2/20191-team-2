#include <iostream>
#include <gtest/gtest.h>
#include "GameBoard.h"

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    auto test_ret_val  = RUN_ALL_TESTS();
    std::cout << "Test return value: " << test_ret_val << std::endl;
    auto game_board = GameBoard(8);

    return 0;
}