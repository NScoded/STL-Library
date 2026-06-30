#include <gtest/gtest.h>
#include "Redis-lite.h"

TEST(RedisLiteExistsTest, NonExistingKey)
{
    Redis_lite<std::string, std::string> redis;

    EXPECT_FALSE(redis.exists("city"));
}



TEST(RedisLiteExistsTest, ExistingKey)
{
    Redis_lite<std::string, std::string> redis;

    redis.set("city", "Raipur");

    EXPECT_TRUE(redis.exists("city"));
}
