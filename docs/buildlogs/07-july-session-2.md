# Date - 2026-07-07 (Session 1)

## <div style="display:flex; justify-content:space-between;"> <span style="color:forestgreen;">Duration - 9:30am to 10:30 am</span><span>git commit -m <span style="color:forestgreen;font-size:17px;"> "Methods updated in Linkedlist and Redislite" </span> </span> </div>

## RedisLite - get() return type updated

### Before
 ```cpp
template<typename K,typename V> bool Redis_lite<K,V>::get(const K& key){
    if(database.exists(key)){
        
        cout<<database.get(key)<<endl;
        return true;
    }
    else{
        cout<< "Key not found!"<<endl;
        return false;
    }
}
 ```

Used the return type as `bool` because we are directly printing the value in the CLI.

### After
 ```cpp
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
 ```

This return type reflects the actual implementation to the redis lite and help in better testing environment.

## LinkedList - remove () implementation updatated

### Before

```cpp
template<typename T>void
LinkedList<T>::remove(T val){
    Node*prev=head;
    Node*nxt=head;

    while(nxt){
        if(nxt->data==val)break;
        prev=nxt;
        nxt=nxt->next;
    }

    if(nxt==nullptr){
        std::cout<<"Data not Found!";
        return;
    }
    
    if(nxt==tail){
        pop();
        return;
    }
    
    size--;
    
    if(nxt==prev){
        
        if(head==tail){
            tail=nullptr;
        }
        head=nxt->next;
        delete nxt;
        return;
    }
    
    prev->next=nxt->next;
    delete nxt;
    
}
```
Used value as a parameter in the remove methods. This arrises the conflict for the same data values.

### After 
```cpp
template<typename T>void
LinkedList<T>::remove(int index){
    if(index>=size || index<0) throw std::out_of_range("Out of Range");

    if(index==size-1){
        pop();
        return ;

    }
    
    if(index==0){
        if(head==tail){
            tail=nullptr;
        }
        Node *temp=head;
        head=head->next;
        delete temp;
        size--;
        return;
    }
    Node*prev=head;
    Node*nxt=head;
    int i=0;
    
    while(i<index){
        prev=nxt;
        nxt=nxt->next;
        i++;
    }

    if(nxt==nullptr){
        std::cout<<"Data not Found!";
        return;
    }
    
    size--;
    
    prev->next=nxt->next;
    delete nxt;
    
}

```

Takes index as parameter and remove value bu 0-based index position.
It improves the implementation logics.


**Update all the testcases as per the new implementation**