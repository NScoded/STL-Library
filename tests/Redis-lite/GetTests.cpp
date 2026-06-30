#include <gtest/gtest.h>
#include "Redis-lite.h"

TEST(RedisLiteGetTest, ExistingKey)
{
    Redis_lite<std::string, std::string> redis;

    redis.set("name", "Nilesh");

    EXPECT_TRUE(redis.get("name"));
}

TEST(RedisLiteGetTest, NonExistingKey)
{
    Redis_lite<std::string, std::string> redis;

    EXPECT_FALSE(redis.get("age"));
}