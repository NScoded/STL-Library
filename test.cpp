#include <iostream>
#include "include/HashMap.h"
using namespace std;


class stud{
    public:
     int id;

    bool operator==(const stud& other) const
    {
        return id == other.id;
    }
};

int main() {
    HashMap< stud,char>map;
    stud s1;
    stud s2;
    map.insert(s1,'a');
    map.insert(s2,'b');
    cout<<map.get(s1)<<endl;
    cout<<map.get(s2)<<endl;
    
}