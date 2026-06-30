#include <gtest/gtest.h>
#include "Redis-lite.h"

TEST(RedisLiteClearTest, ClearDatabase)
{
    Redis_lite<std::string, std::string> redis;

    redis.set("A", "1");
    redis.set("B", "2");

    EXPECT_TRUE(redis.clear());

    EXPECT_EQ(redis.size(), 0);
}

TEST(RedisLiteClearTest, ClearEmptyDatabase)
{
    Redis_lite<std::string, std::string> redis;

    EXPECT_TRUE(redis.clear());

    EXPECT_EQ(redis.size(), 0);
}