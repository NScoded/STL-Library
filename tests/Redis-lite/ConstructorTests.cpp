#include <gtest/gtest.h>
#include "Redis-lite.h"

TEST(RedisLiteConstructorTest, DefaultConstructor)
{
    Redis_lite<std::string, std::string> redis;

    EXPECT_EQ(redis.size(), 0);
}