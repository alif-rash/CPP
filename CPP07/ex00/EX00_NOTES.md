# CPP07 ex00 - Whatever Notes

## Goal of the exercise
This exercise introduces function templates in C++.

The goal is to write generic versions of common operations that work with any type that supports the needed operators.

The three functions implemented here are:
- `swap(T &a, T &b)`
- `min(T &a, T &b)`
- `max(T &a, T &b)`

These are written once and can be used with integers, strings, or other compatible types.

---

## What the program demonstrates
The main program shows that the same template functions work with:
- `int`
- `std::string`

This is the core idea of templates:
- the code is written once
- the compiler generates the correct version for each type

---

## File overview

### `Whatever.hpp`
This header contains the template definitions.

It includes:
- `swap()` for exchanging two values
- `min()` for returning the smaller value
- `max()` for returning the larger value

### `main.cpp`
This file is only a small demonstration.

It tests the functions with:
- integer values
- string values

---

## Function reference

### `template <typename T> void swap(T &a, T &b)`
This function swaps two values of the same type.

It works by creating a temporary variable and exchanging the contents.

Important detail:
- both arguments must be of the same type
- the type must be copy-assignable

### `template <typename T> T const& min(T &a, T &b)`
This function returns the smaller of two values.

It compares them using `operator<`.

Behavior:
- if the values are equal, it returns the second one
- otherwise it returns the smaller one

### `template <typename T> T const& max(T &a, T &b)`
This function returns the larger of two values.

It compares them using `operator>`.

Behavior:
- if the values are equal, it returns the second one
- otherwise it returns the larger one

---

## Why this exercise matters
This is the first step toward generic programming in C++.

You learn that templates allow you to:
- avoid rewriting the same logic for multiple types
- keep code short and clear
- reuse functions for many data types

In this exercise, the logic is simple, but the concept is very important for later exercises.

---

## Important note about `min` and `max`
The implementation returns a `const T&` reference.

That means:
- no unnecessary copy is made
- the function works efficiently
- the result refers to one of the original arguments

---

## Short summary to remember
- templates let one function work with many types
- `swap()` exchanges two values
- `min()` and `max()` compare two values using the appropriate operator
- this exercise is about generic programming, not about special-case logic

---

## Oral defense idea
You can explain the exercise like this:

> I implemented a small generic toolbox with function templates. The same code works for different types because the compiler generates the appropriate specialization at compile time. This is the foundation of reusable C++ code.

# CPP07 ex01 - Iter Notes

## Goal of the exercise
This exercise teaches how to apply a function to every element of an array using templates.

The main idea is to write one generic function, `iter()`, that can iterate over:
- an array of any type
- an array of any length
- a function that accepts one element and performs some action

---

## What the program does
The example program creates:
- an `int` array
- a `std::string` array

Then it calls `iter()` on each array and prints every element.

This shows that the same iteration mechanism can be reused for different types.

---

## File overview

### `iter.hpp`
This header contains the template logic.

It defines:
- `print(const T& value)`
- `iter(T_array *array, size_t len, T_func function)`
- an overloaded `iter()` for `const T_array*`

### `main.cpp`
This file demonstrates the usage.

It passes:
- `print<int>` for integers
- `print<std::string>` for strings

---

## Function reference

### `template <typename T> void print(const T& value)`
This is a simple helper function.

It prints the provided value to `std::cout` followed by a newline.

It is used as the operation that will be applied to each element.

### `template <typename T_array, typename T_func> void iter(T_array *array, size_t len, T_func function)`
This is the core template.

It loops through the array and calls `function(array[i])` for each element.

Important behavior:
- it checks whether the array pointer is valid
- it iterates from `0` to `len - 1`
- it calls the provided function on each element

### `template <typename T_array, typename T_func> void iter(const T_array *array, const size_t len, T_func function)`
This version handles arrays that are declared as `const`.

It uses the same idea as the mutable version, but accepts a pointer to a constant array.

---

## Why this exercise matters
This is your first practical example of using templates with function objects or function pointers.

The important concept is that `iter()` is not tied to one specific type.

It can be reused as long as the function passed in is callable for each element.

---

## Important detail about template arguments
In the example, the call is written like this:

- `iter(intArray, 5, print<int>);`
- `iter(strArray, 4, print<std::string>);`

This is important because `print` is itself a template function.

The compiler needs explicit template arguments so it knows which version to use.

---

## What to remember for the oral defense
You can explain the exercise like this:

> I wrote a generic iteration function that applies a callback to every element of an array. The function is independent of the array element type, which makes it reusable and keeps the code compact.

---

## Short summary to remember
- `iter()` is a generic loop
- it works with any array type
- it applies a function to each element
- templates make the code reusable without rewriting it for each type

# CPP07 ex02 - Array Notes

## Goal of the exercise
This exercise introduces a templated container class named `Array`.

The goal is to create a class that behaves like a simple array wrapper while adding safety checks.

The class supports:
- default construction
- construction with a given size
- copy construction
- assignment
- element access with `operator[]`
- size retrieval
- bounds checking

---

## What the program demonstrates
The main program creates an `Array<int>` of a large size, fills it with random values, and checks that:
- values are stored correctly
- copies behave independently
- out-of-bounds access throws an exception

This shows that the class behaves like a safe, templated array.

---

## File overview

### `Array.hpp`
This header declares the `Array` class template.

It contains:
- the private members `arr` and `size`
- public constructors and destructor
- `operator[]` overloads
- `getSize()`
- the nested exception class `OutOfBoundsException`

### `Array.tpp`
This file contains the template definitions.

It implements the behavior of the class.

### `main.cpp`
This file tests the container in a realistic way.

It checks:
- initialization
- copying
- assignment
- bounds handling

---

## Class structure

### Private members
- `T *arr;` - the internal dynamic array
- `unsigned int size;` - the number of elements

### Public interface
The class provides:
- a default constructor
- a constructor that allocates `n` elements
- a copy constructor
- an assignment operator
- a destructor
- `operator[]` for read/write access
- `operator[]` for const access
- `getSize()`

---

## Constructor behavior

### Default constructor
Creates an empty array:
- `arr = NULL`
- `size = 0`

### Size constructor
Allocates an array of `n` elements using `new T[n]()`, which value-initializes the elements.

### Copy constructor
Creates a new array of the same size and copies each value from the source.

---

## Copy and assignment semantics
The class follows the rule of deep copy.

That means:
- the new object gets its own dynamic memory
- modifying one array does not alter the other

The assignment operator also handles self-assignment safely.

---

## Element access and bounds checking
The `operator[]` overloads check whether the index is valid.

If the index is outside the array bounds, they throw `OutOfBoundsException`.

This is an important improvement over a normal raw C array because it helps prevent invalid memory access.

---

## Exception handling
The nested class `OutOfBoundsException` inherits from `std::exception`.

Its `what()` function returns:
- `"Index out of bounds"`

This makes error reporting simple and standard.

---

## Why this exercise matters
This is the first time you work with a template class that manages its own dynamic memory.

It teaches several important ideas:
- templates can create type-safe containers
- constructors and destructors must be implemented carefully
- copy semantics must be handled correctly
- boundaries should be checked to avoid undefined behavior

---

## Short summary to remember
- `Array<T>` is a templated container
- it wraps a dynamic array safely
- it supports indexing and size checks
- it uses deep copy semantics
- out-of-bounds access throws an exception

---

## Oral defense idea
You can explain the exercise like this:

> I implemented a templated array class that stores elements dynamically and enforces bounds checking. The class provides basic container behavior while preventing invalid access through exceptions and proper copy management.
