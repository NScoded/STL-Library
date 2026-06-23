#include "DynamicArray.h"
#include <type_traits>
#include <stdlib.h>
#include <new>

// Default Constructor
template<typename T >DynamicArray<T> :: DynamicArray(){
    len=0;
    cap=4;
    arr= (T*)malloc(cap * sizeof(T));

}

// Parametrised Constructor
template<typename T >DynamicArray<T> :: DynamicArray(int cap,T val){
    arr = (T*)malloc(cap * sizeof(T));
    len=cap;
    this->cap=cap;
    for(int i=0;i<cap;i++){
        new (&arr[i]) T(val);
    }
}

// Destructor 
template<typename T>
DynamicArray<T>::~DynamicArray() {

    // Check karta hai ki T ka destructor exists karta hai ya nahi, true means T is non primitive
    if constexpr (!std::is_trivially_destructible_v<T>) { 
        for (int i = 0; i < len; i++) {
            arr[i].~T();
        }
    }

    free(arr);
}


template<typename T> void DynamicArray<T>:: copy(T &array){
    int newsize=len*2;
    T *newarr=(T*)malloc(newsize*sizeof(T));
    // I will continue After lunch


}