#include <gtest/gtest.h>
#include "Redis-lite.h"

TEST(RedisLiteGetTest, ExistingKey)
{
    Redis_lite<std::string, std::string> redis;

    redis.set("name", "Nilesh");

    EXPECT_EQ(redis.get("name"),"Nilesh");
}

TEST(RedisLiteGetTest, NonExistingKey)
{
    Redis_lite<std::string, std::string> redis;

    EXPECT_THROW(redis.get("age"),std::out_of_range);
}

