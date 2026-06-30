#include <gtest/gtest.h>
#include "Redis-lite.h"

TEST(RedisLiteSetTest, SetSingleKey)
{
    Redis_lite<std::string, std::string> redis;

    EXPECT_TRUE(redis.set("name", "Nilesh"));

    EXPECT_EQ(redis.size(), 1);
    EXPECT_TRUE(redis.exists("name"));
}

TEST(RedisLiteSetTest, SetMultipleKeys)
{
    Redis_lite<std::string, std::string> redis;

    redis.set("A", "1");
    redis.set("B", "2");
    redis.set("C", "3");

    EXPECT_EQ(redis.size(), 3);
}

TEST(RedisLiteSetTest, UpdateExistingKey)
{
    Redis_lite<std::string, std::string> redis;

    redis.set("name", "ABC");
    redis.set("name", "XYZ");

    EXPECT_EQ(redis.size(), 1);
    EXPECT_TRUE(redis.exists("name"));
}