//
// Created by root on 05/06/19.
//

#include <gtest/gtest.h>
#include "test_class.h"
//#include "NameOfYourClass.h"

using testing::Eq;

namespace {
    class ClassDeclaration : public testing::Test{
    public:
        test_class obj;
        ClassDeclaration()
        {
            obj;
        }
    };
}

TEST(ExampleTest, DemonstrateGtestMacros)
{
    EXPECT_TRUE(false);
}
TEST_F(ClassDeclaration, nameOfTest1)
{
    ASSERT_EQ(1, 1);
}

TEST_F(ClassDeclaration, getters_and_setters)
{
    obj.setX(22);
    ASSERT_EQ(22, obj.getX());
}