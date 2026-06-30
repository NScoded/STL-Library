#include <gtest/gtest.h>
#include "Redis-lite.h"

TEST(RedisLiteDeleteTest, DeleteExistingKey)
{
    Redis_lite<std::string, std::string> redis;

    redis.set("A", "10");

    EXPECT_TRUE(redis.del("A"));
    EXPECT_FALSE(redis.exists("A"));
    EXPECT_EQ(redis.size(), 0);
}

TEST(RedisLiteDeleteTest, DeleteNonExistingKey)
{
    Redis_lite<std::string, std::string> redis;

    EXPECT_FALSE(redis.del("ABC"));
}