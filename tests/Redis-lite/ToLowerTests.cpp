#include <gtest/gtest.h>
#include "Redis-lite.h"

TEST(RedisLiteToLowerTest, ConvertUpperCase)
{
    Redis_lite<std::string, std::string> redis;

    EXPECT_EQ(redis.To_lower("SET"), "set");
}

TEST(RedisLiteToLowerTest, MixedCase)
{
    Redis_lite<std::string, std::string> redis;

    EXPECT_EQ(redis.To_lower("GeT"), "get");
}

TEST(RedisLiteToLowerTest, AlreadyLowerCase)
{
    Redis_lite<std::string, std::string> redis;

    EXPECT_EQ(redis.To_lower("exists"), "exists");
}