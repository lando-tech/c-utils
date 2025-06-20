# c-utils

**c-utils** is a collection of basic, standalone implementations of common data structures, algorithms, and utility functions in C.
Designed primarily for educational purposes, the library emphasizes modularity — each header/source pair is kept as independent as possible to minimize dependencies and allow selective usage.

## Features

### HashMap

The `hashmap` implementation is a work-in-progress. It currently supports fixed-size storage and uses `uint8_t` keys — a temporary design inherited from a prior project.

#### Planned Features

* Key-value insertion and retrieval
* Support for integer (`int`) keys
* Dynamic resizing and memory allocation

### Vector

`vector.h` is a header-only implementation of a dynamic array (vector) in C. To simulate type-generic behavior, the implementation leverages macros.

Current functionality includes:

* `push`
* `pop`
* `get`

### String Utilities

`string_utils` provides common string parsing functions along with a custom `StringArray` — a dynamically sized array for managing strings.

### File I/O

`file_io` includes a `read_file` function that outputs file contents to `stdout`. Additional file manipulation utilities are planned for future development.

### Algorithms

The `algorithms` module implements a bubble and merge sort for integer arrays.

Planned additions:

* Binary Search
* Insertion Sort

### Data Types

`data_types` provides utility functions for referencing C language limits, printing the full ASCII table, and other helpful features for beginners and quick reference.

## Installation

Clone the repository:

```sh
git clone https://github.com/yourname/c-utils.git
```

## Usage

Include the desired module in your project:

```c
#include "vector.h"
#include "hashmap.h"
```

Compile with your C compiler:

```sh
gcc your_file.c -o your_program
```

## License

MIT License. See `LICENSE` file for details.

## Contributing

Contributions are welcome. Feel free to open issues or submit pull requests to help improve the project.
