# STL-Library

A C++ library that implements fundamental data structures from scratch without using the Standard Template Library (STL) containers. The project is designed to understand low-level memory management, templates, object lifetime, and the internal working of commonly used data structures.

---

## Features

* Template-based implementation
* Manual memory management
* Rule of Three implementation
* Custom Dynamic Array
* Custom Linked List
* Custom Hash Map
* Separate Chaining for collision handling
* Custom hash function support
* Unit testing using Google Test
* CMake build support

---

## Implemented Data Structures

### DynamicArray

* Dynamic resizing
* Random access
* Insert and remove operations
* Copy constructor
* Copy assignment operator
* Destructor
* Bounds checking

### LinkedList

* Singly Linked List
* Head and Tail pointers
* Insert at back
* Remove operations
* Search
* Clear
* Size tracking

### HashMap

* Generic Key-Value storage
* Separate Chaining
* Automatic Rehashing
* Configurable Load Factor
* Custom Hash Function support
* Update existing keys
* Remove and Search operations

---

## Project Structure

```text
.
├── include/
│   ├── DynamicArray.h
│   ├── DynamicArray.tpp
│   ├── LinkedList.h
│   ├── LinkedList.tpp
│   ├── HashMap.h
│   ├── HashMap.tpp
│   └── MyHash.h
│
├── tests/
│   ├── DynamicArrayTests.cpp
│   ├── LinkedListTests.cpp
│   ├── HashMapTests.cpp
│   └── RedisLiteConstructorTests.cpp
│
├── docs/
│   ├── diagrams/
│   ├── build_logs/
│   └── design_proposal.md
│
├── CMakeLists.txt
├── README.md
└── LICENSE
```

---

## Building the Project

### Clone the Repository

```bash
git clone <https://github.com/SuperCodersOrg/ds_library-Nilesh>
cd STL-Library
```

### Configure

```bash
mkdir build
cd build
cmake ..
```

### Build

```bash
cmake --build .
```

---

## Running Tests

After building the project:

```bash
ctest
```

Or execute the individual test binaries.

Example:

```bash
./DynamicArrayTests
./LinkedListTests
./HashMapTests
```

---

## Example

```cpp
#include "DynamicArray.h"

int main()
{
    DynamicArray<int> arr;

    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);

    std::cout << arr[1] << std::endl;

    return 0;
}
```

---

## Time Complexity

### DynamicArray

| Operation | Complexity     |
| --------- | -------------- |
| Access    | O(1)           |
| push_back | O(1) Amortized |
| insert    | O(n)           |
| remove    | O(n)           |
| pop_back  | O(1)           |

### LinkedList

| Operation | Complexity |
| --------- | ---------- |
| Push Back | O(1)       |
| Search    | O(n)       |
| Remove    | O(n)       |
| Clear     | O(n)       |

### HashMap (Average Case)

| Operation | Complexity |
| --------- | ---------- |
| Insert    | O(1)       |
| Search    | O(1)       |
| Remove    | O(1)       |
| Rehash    | O(n)       |

---

## Documentation

The project includes documentation for:

* Memory layout diagrams
* Design proposal
* Build logs
* Unit testing
* Implementation notes

---

## Future Work

* Doubly Linked List
* Stack
* Queue
* Binary Search Tree
* AVL Tree
* Red-Black Tree
* Trie
* Heap
* Graph
* Iterator support
* Move semantics (Rule of Five)
* Redis-like key-value database built using this library

---

## Author

**Nilesh Sahu**

---

## License

This project is licensed under the MIT License.
