#include <gtest/gtest.h>
#include "factorial.h"


TEST(FactorialTest, HandlesPositiveInputs) {
    EXPECT_EQ(factorial(5), 120);
    EXPECT_EQ(factorial(10), 3628800);
}

TEST(FactorialTest, HanldesZero) {
    EXPECT_EQ(factorial(0), 1);
}

TEST(FactorialTest, HanldesOne) {
    EXPECT_EQ(factorial(1), 1);
}

TEST(FactorialTest, HandlesNegativeInputs) {
    EXPECT_EQ(factorial(-5), -1);
    EXPECT_EQ(factorial(-10), -1);
}
