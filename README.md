# c-utils
- This library consists of basic implementations of some useful data structures/containers, algorithms, and utilities.
- The goal of this library is educational in nature, but also intended to be used in my own workflows and anyone else who finds it useful.
- The design structure is intended to keep each header and src file pair as independet as possible to ensure usage of only needed libs per project.

## HashMap
- The current iteration of `hashmap.h/c` is currently under development, but is semi-functional (See ***Upcoming HashMap Features*** below).
- The hashmap is currently fixed in size, but resizing is my next project pertaining to this lib.
- It also currently includes `uint_8` data types as the key, a design choice carried
  over from another project. This will be changed in the near future.

### Upcoming HashMap Features
- get/insert operations
- `int` based keys
- dynamic resizing/allocation

## Vector
- `vector.h` is a header only implementation of a vector.
- Since vectors are relatively simple in nature, I decided to add some "macro magic" to experiment.
- You will find the usual elements of a dynamic array structure:
    - `push`
    - `pop`
    - `get`
- In the future I plan to implement a more robust version with a src and header file.

## String Utils
- `string_utils` contains several useful string parsing functions and a custom `StringArray` (dynamic string array implement).

## File-I/O
- `file_io` currently only contains a `read_file` function that simply prints file contents to `stdout`. I plan to do a lot more with this library in the future.

## Algorithms
- `algorithms` currently only implements a simple bubble sort on an integer array.
- My next goal is to add `merge sort`, `binary_search`, and `insertion sort`.

## Data Types
- `data_types` is a very simple lib I created to aid me in learning C. It contains useful functions that will
  print `c-limits`, a full `ASCII` table, and other helper functions.
- This lib is a useful reference when first starting out in C, or when you just can't remember what the `ASCII` value of a `~` is.