# Dynamic Array Design Proposal - version 2

## Overview 
A singly linked list consisting of nodes connected through pointers, allowing efficient insertion and deletion operations.

# Section 1 - Public API



```cpp   
template<typename T>class LinkedList{

    private:
    struct Node{
        T data;
        Node*next;
        Node(T val);
    }
    public:
    Node*head=nullptr;
    Node*tail=nullptr;
    int size=0;
    LinkedList(); //Constructor
    LinkedList(const LinkedList& other); // Copy Constructor
    LinkedList(LinkedList&& other); // Move Constructor 
    ~LinkedList(); // Destructor
    void insertFront(T value); //Insert value at front
    void deleteFront(); // Delete first value
    void insert(int pos, T value); //Insert value at given position
    void append(T value); // Insert value at last
    bool exists(T value); //returns true of value exists otherwise returns false 
    int size(); //return size of the linkedlist
    void reverse()// reverse the LinkedList
    void print(); // print the linkedlist
};
```

The current implementation uses a **singly linked list** because it provides a simple structure and satisfies the requirements of the project. However, the design remains *flexible*. If future requirements demand more efficient *bidirectional traversal* or *frequent operations* at both ends of the list, the implementation may be extended to a **doubly linked** list. Such a change can be made without affecting the public interface significantly, allowing the data structure to evolve based on performance considerations and project needs.

# Section 2 - Internal Representation
LinkedList consists of individually allocated nodes connected by *next pointers*. Each node stores a value of type `T` and a pointer to the next node.

The destructor `traverses` the list and deletes every node until the list becomes empty.

Copy operations perform a deep copy by allocating new nodes and duplicating the contents of the source list.
![LinkedList](../images/Linkedlist.jpg)

### Copy Operations

All three data structures use **deep copying** for copy operations. During a copy operation, new memory is allocated and the contents of the source object are duplicated into the newly allocated memory.

Shallow copying is avoided because shared memory may lead to `dangling pointers`, `double deletion`, `undefined behavior`, and `program crashes`.

# Section 3 - Complexity Estimates

### insertFront()

* **Best Case:** O(1)
* **Average Case:** O(1)
* **Worst Case:** O(1)

**Why:** The new node becomes the head node.

### deleteFront()

* **Best Case:** O(1)
* **Average Case:** O(1)
* **Worst Case:** O(1)

**Why:** Only the head pointer is updated.

### insert(pos)

* **Best Case:** O(1)
* **Average Case:** O(n)
* **Worst Case:** O(n)

**Why:** Traversal is required to reach the insertion position.

### contains(value)

* **Best Case:** O(1)
* **Average Case:** O(n)
* **Worst Case:** O(n)

**Why:** The value may be found immediately or after scanning the entire list.

### size()

* **Best Case:** O(1)
* **Average Case:** O(1)
* **Worst Case:** O(1)

**Why:** The number of nodes is stored in a variable.

### print()

* **Best Case:** O(n)
* **Average Case:** O(n)
* **Worst Case:** O(n)

**Why:** Every node must be visited.

---
# Section 4 - Design Decision

`Proposed design reason`    
Singly Linked List - Less memory usage

`Rejected design reason`  
Doubly Linked List - More memory usage
