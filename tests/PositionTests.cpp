//
// Created by giow on 11/06/19.
//

#include <gtest/gtest.h>
#include "../src/Position.hpp"
//#include "NameOfYourClass.h"

using testing::Eq;

namespace {
class PositionClassSuite : public testing::Test {
 public:

  PositionClassSuite() {
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


TEST_F(PositionClassSuite, CheckOperatorOverload)
{
  Pos pos(3,4);
  ASSERT_EQ(3, pos.x_);
  ASSERT_EQ(4, pos.y_);
}