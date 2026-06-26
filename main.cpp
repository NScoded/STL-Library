#include "include/HashMap.h"
#include "include/Redis-lite.h"
#include <bits/stdc++.h>
using namespace std;


class stud{
    public:
    int id=0;
    bool operator ==(const stud & other)const{
        return id==other.id;
    }
};

int main(){
    Redis_lite<string ,string>mp;
    
    
    
    
}