#include "../../include/Redis-lite.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;




// Run
template<typename K,typename V> void Redis_lite<K,V>::run(){
    cout<<"---------- Redis-Lite Database server stated ----------\n";
    cout<<"Methods availabe\nSET _ _\nGET _\nEXISTS _\nDEL _\nCLEAR \nSIZE\nKEYS\nEXIT\n";
    cout<<"-------------------------------------------------------\n";
    while(true){
        string input;
        string method;
        
        cout<<"redis > ";
        getline(cin,input);
        stringstream ss(input);
        ss>>method;
        method=To_lower(method);
        string key,strm,val="";

        if(method=="get"){
            ss>>key;
            get(key);
            
        }
        else if(method=="set"){
            ss>>key;
            ss>>strm;
            do{
            val=val+strm+" ";
            ss>>strm;

            }while(!ss.fail());
            set(key,val);
            
        }
        else if(method=="exists"){
            ss>>key;
            exists(key);
            
        }
        else if(method=="del"){
            ss>>key;
            del(key);

        }
        else if(method=="clear"){
            clear();

        }
        else if(method=="size"){
            size();

        }

        else if (method=="keys"){
            getKeys();
            
        }
        else if (method=="exit"){
            cout<<"Good Bye...";
            break;
        }

        else{
            cout<<"Enter valid operation\n";
        }


    }
}

// Constructor
template<typename K,typename V> Redis_lite<K,V>::Redis_lite(){
    run();
}

// To_lower()
template<typename K,typename V> string Redis_lite<K,V>::To_lower(string s){
    for(char &ch:s)ch=tolower(static_cast<unsigned char>(ch));
    return s;
}



// get()
template<typename K,typename V> V Redis_lite<K,V>::get(const K& key){
    if(database.exists(key)){
        
        cout<<database.get(key)<<endl;
        return database.get(key);
    }
    else{
        cout<< "Key not found!"<<endl;
        throw std::out_of_range("Key not Found");
    }
}

// set
template<typename K,typename V> bool Redis_lite<K,V>::set(const K& key,const V& val){
    database.insert(key,val);
    cout<<"Ok\n";
    return true;
}


// exists
template<typename K,typename V> bool Redis_lite<K,V>::exists(const K& key){
    if(database.exists(key)){
        cout<<"exists\n";
        return true;
    }
    else{
        cout<<"Not exists\n";
        return false;
    }
    
}


// del
template<typename K,typename V> bool Redis_lite<K,V>::del(const K& key){
    if(database.remove(key)){
        cout<<"Removed\n";
        return true;
    }
    else{
        cout<<"Key not found! \n";
        return false;
    }
    
}

// clear
template<typename K,typename V> bool Redis_lite<K,V>::clear(){
    
    database.clear();
    cout<<"Ok";
    return true;
}

// size
template<typename K,typename V> size_t Redis_lite<K,V>::size()const{
    
    cout<<database.size()<<endl;
    return database.size();
}

template<typename K,typename V>
DynamicArray<K> Redis_lite<K,V> :: getKeys(){
    DynamicArray<K>keys;
    keys=database.getkeys();
    for(int i=0;i<keys.size();i++){
        cout<<keys[i]<<endl;
    }
    return keys;
}