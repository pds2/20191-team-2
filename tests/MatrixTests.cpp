//
// Created by giow on 11/06/19.
//

#include <gtest/gtest.h>
#include "../src/Matrix.hpp"
//#include "NameOfYourClass.h"

using testing::Eq;

namespace {
class MatrixClassSuite : public testing::Test {
 public:

  MatrixClassSuite() {
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

TEST_F(MatrixClassSuite, CheckInvalidInputs) {
  EXPECT_ANY_THROW(Matrix(-9, -9));
}