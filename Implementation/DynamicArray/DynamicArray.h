#pragma once

template<typename T> class DynamicArray{

    private:
    void copy(T &arr);
    public:
    int len;
    int cap;
    T * arr ;
    

    DynamicArray();// Constructor
    DynamicArray(int cap,T val);// Constructor
    DynamicArray(const DynamicArray& other); //Copy Constructor
    DynamicArray(DynamicArray&& other); // Move Constructor
    ~DynamicArray(); //Destructor
    void push_back(T value); //Add value at last
    void insert(int index, T value); //Add value at given index
    void remove(int index);// Delete value by index
    void pop_back(); // Delete last element
    T get(int index);// return value at given index
    int size(); // return number of elements inserted
    int capacity();// returns total capacity of array
    void clear(); // remove all elements
};

#include "DynamicArray.tpp"