#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include "decimal.h"

#define FLAG 0

TEST(SimpleTest, HowToUseGoogleTest)
{
    EXPECT_EQ(1, 2 - 1);
    EXPECT_TRUE(true);
    EXPECT_FALSE(false);
}

#if FLAG
TEST(RealtSturctureTest, BigIntTest)
{
    real_t a;
    real_t b;
    a = string("9999999999999999999999999999999999999999999999");
    b = 1;
    real_t c("10000000000000000000000000000000000000000000000");

    EXPECT_EQ(a + b, c);
}

TEST(RealtSturctureTest, SmallFloatTest)
{
    real_t a("0.00000000000000000000000000000001");
    real_t b("0.00000000000000000000000000000002");
    real_t c("0.00000000000000000000000000000016");
    EXPECT_EQ(a*8 + 4*b, c);
}

#endif
