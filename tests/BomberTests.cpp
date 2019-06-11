//
// Created by giow on 11/06/19.
//

//
// Created by giow on 11/06/19.
//

#include <gtest/gtest.h>
#include "../src/Matrix.hpp"
#include "../src/Bomber.h"
//#include "NameOfYourClass.h"

using testing::Eq;

namespace {
class BomberClassSuite : public testing::Test {
 public:
  Matrix* fake_board = NULL;
  BomberClassSuite() {
    fake_board;
  }
};
}
/*
 *
TEST(ExampleTest, DemonstrateGtestMacros)
{
    EXPECT_TRUE(false);
}
 * */

TEST_F(BomberClassSuite, CheckInvalidInputs) {
  EXPECT_ANY_THROW(Bomber(NULL, Pos(0,0), fake_board));
}