![C++](https://img.shields.io/badge/Language-C++-blue)
![Level](https://img.shields.io/badge/Level-Beginner-green)
![Focus](https://img.shields.io/badge/Focus-OOP-orange)
![Memory](https://img.shields.io/badge/Concepts-Pointers%20%7C%20Destructors-red)

# C++ Bag Class

A small console-based implementation of a dynamic integer collection built in C++.

This project was created while learning the Rule of Three, the relationship
between destructors, copy constructors, and assignment operators when a class
manages heap memory.


## What This Project Covers

- Dynamic memory management (`new` / `delete[]`)
- The Rule of Three (destructor, copy constructor, `operator=`)
- Deep vs shallow copying
- Self-assignment protection in `operator=`
- Pointer-based class design
- Encapsulation (private members, public methods)

## Structure

### Bag Class

Represents a collection of unique integers stored on the heap.

Data members:
- `int *items` heap-allocated array
- `int len` current number of items
- `int capacity` maximum items before reallocation

Includes:
- `add(int n)` adds n if not already present and space exists
- `show()` prints the contents
- `contains(int n)` returns true if n is in the bag
- `find(int n)` private helper, returns index or -1

### Key Concepts Practiced

**Destructor** frees the heap array when the object is destroyed,
preventing memory leaks.

**Copy constructor** allocates a fresh independent array so that
modifying a copy does not affect the original.

**operator=** does the same as the copy constructor but frees the existing
array first, and guards against self-assignment.
