#include <gtest/gtest.h>
#include "Redis-lite.h"

TEST(RedisLiteSizeTest, EmptyDatabase)
{
    Redis_lite<std::string, std::string> redis;

    EXPECT_EQ(redis.size(), 0);
}

TEST(RedisLiteSizeTest, AfterInsertion)
{
    Redis_lite<std::string, std::string> redis;

    redis.set("A", "1");
    redis.set("B", "2");

    EXPECT_EQ(redis.size(), 2);
}

TEST(RedisLiteSizeTest, AfterDeletion)
{
    Redis_lite<std::string, std::string> redis;

    redis.set("A", "1");
    redis.set("B", "2");

    redis.del("A");

    EXPECT_EQ(redis.size(), 1);
}