# Build Log – HashMap `getkeys()` Implementation

## Objective

Implement a `getkeys()` method in the custom `HashMap` class to retrieve all keys currently stored in the hash map.

The primary motivation for this implementation was the Redis-lite project. While working on Project 2, there was no way to obtain a complete list of stored keys from the custom hash map, which prevented implementing commands that require iterating over all keys.

---

## Problem

The existing `HashMap` implementation supported operations such as insertion, lookup, update, and deletion, but did not provide any mechanism to enumerate every key stored in the map.

Since the underlying implementation uses **separate chaining** with an array of linked lists, simply accessing the buckets was not sufficient. Every bucket could contain multiple key-value pairs due to hash collisions, making traversal of each linked list necessary.

---

## Implementation

Added the following public API to the `HashMap` class:

```cpp
DynamicArray<K> getkeys();
```

The method performs the following steps:

1. Creates an empty `DynamicArray<K>` to store the keys.
2. Iterates through every bucket in the hash table.
3. Traverses the linked list associated with each bucket.
4. Extracts the key from every stored `Pair`.
5. Appends each key to the resulting dynamic array.
6. Returns the populated array containing all keys present in the hash map.

---

## Challenges

During implementation, an issue occurred while accessing bucket contents.

Initially, the buckets were treated as pointers, resulting in compilation errors because each bucket is actually a `LinkedList<Pair>` object rather than a pointer. The implementation was corrected by accessing the linked list object directly and traversing its nodes.

Another important consideration was handling hash collisions correctly. Reading only the head node of each linked list would return only one key per bucket and miss all remaining keys stored due to collisions. This was resolved by iterating through every node in each linked list.

---

## Result

The `HashMap` now exposes a `getkeys()` method that returns every key stored in the data structure, regardless of bucket distribution or collisions.

This functionality enables higher-level components, particularly the Redis-lite project, to enumerate stored keys whenever required.

---

## Impact on Redis-lite

This implementation removes the limitation encountered in Project 2, where it was not possible to retrieve all stored keys from the custom hash map.

The new method provides the necessary foundation for implementing Redis-style commands and features that require access to the complete key set, improving the usability and extensibility of the Redis-lite application.

---

## Status

* `HashMap::getkeys()` implemented successfully.
* Integrated with the Redis-lite codebase.
* Ready for unit testing and use by higher-level Redis commands.
