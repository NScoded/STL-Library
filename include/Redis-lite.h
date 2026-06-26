#pragma once
#include "HashMap.h"
#include <iostream>

template<typename K,typename V>
class Redis_lite{
    private:
    void run();
    HashMap<K,V>database;
    bool set(const K& key, const V& value);
    bool get(const K& key);
    bool del(const K& key);
    bool exists(const K& key);
    bool clear();
    size_t size() const;
    std::string To_lower(std::string s);
    public:
    Redis_lite();


};

#include "../src/Redis-lite/Redis-lite.tpp"