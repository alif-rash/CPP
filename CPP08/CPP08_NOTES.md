# CPP08 - STL Containers, Iterators, and Algorithms

## Goal of the module
This module is about the Standard Template Library (STL) in C++.

The main ideas are:
- containers store data
- iterators allow traversal through containers
- algorithms work on ranges of elements
- templates let the same code work with many types
- container adapters like `std::stack` can expose a different interface while reusing a base container

CPP08 focuses on practical use of STL concepts instead of creating a large project.

---

## What you are learning here
By the end of this module, you should understand:
- how to search inside containers with `std::find`
- how to handle fixed-size collections with exceptions
- how to expose iterator access from a container adapter
- how templates and iterators work together in real C++ code

---

## Exercise 00 - `easyfind`

### Core idea
This exercise is about writing a generic function that searches for a value inside a container.

The key STL tool here is:
- `std::find(begin, end, value)`

The function should:
- accept any container that has `begin()` and `end()`
- return an iterator to the found value
- throw an exception if the value is not present

### Typical implementation
```cpp
template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw NotFoundException();
    return (it);
}
```

### Why this matters
This teaches you three important C++ concepts:
1. generic programming with templates
2. using STL algorithms instead of writing manual loops
3. proper exception handling for missing values

### Important details
- `std::find` works for many containers such as `vector`, `list`, and `deque`
- the function must be written with a template so it is reusable
- the return type is an iterator, not a value
- the found element is accessed with `*it`

### Custom exception
A simple custom exception class is often used:
```cpp
class NotFoundException : public std::exception
{
    public:
        virtual const char *what() const throw()
        {
            return ("Number not found");
        }
};
```

### Example behavior
- `easyfind(vec, 4)` returns the iterator to `4`
- `easyfind(vec, 99)` throws `NotFoundException`

### Oral defense idea
> I wrote a generic `easyfind()` function using the STL `std::find` algorithm. It works with different containers because it is templated and only requires `begin()` and `end()`. If the value is missing, it throws a custom exception instead of returning an invalid iterator.

---

## Exercise 01 - `Span`

### Core idea
`Span` is a class that stores a limited number of integers and computes the shortest and longest difference between any two stored values.

It is a good example of:
- custom container-like logic
- fixed-size storage
- range-based insertion
- exception handling for invalid operations

### Class design
The class normally contains:
- `unsigned int max_size`
- `std::vector<int> numbers`

The job of the class is to:
- accept numbers up to a defined maximum
- reject extra numbers when the container is full
- calculate the smallest distance between two elements
- calculate the largest distance between two elements

### Methods
#### `addNumber(int number)`
This adds a single number to the internal vector.

Rules:
- if the vector is already full, throw an exception
- otherwise insert the number

#### `shortestSpan()`
This computes the minimum absolute difference between any two numbers.

The logic is:
1. sort the numbers
2. compute differences between adjacent values
3. return the smallest one

Example:
- numbers: `5, 3, 17, 9, 11`
- sorted: `3, 5, 9, 11, 17`
- differences: `2, 4, 2, 6`
- shortest span: `2`

#### `longestSpan()`
This computes the maximum difference between any two numbers.

Logic:
- after sorting, difference between the first and last values is the largest span

Example:
- sorted: `3, 5, 9, 11, 17`
- longest span: `17 - 3 = 14`

### Range overload
A very important part of the exercise is allowing insertion from a range:
```cpp
template <typename T>
void addNumber(T begin, T end)
{
    if (numbers.size() + std::distance(begin, end) > max_size)
        throw SpanFullException();
    numbers.insert(numbers.end(), begin, end);
}
```

This is useful because it lets you add values from:
- a `std::vector`
- an array range
- other STL containers

### Exceptions used
Typically two custom exceptions are defined:
- `SpanFullException`
- `NotEnoughNumbersException`

These are thrown when:
- the span is full and you try to add another number
- the span has too few elements to compute a valid result

### Why this matters
This exercise is about more than arithmetic. It teaches:
- how to manage a bounded container
- how to work with iterators in generic code
- how to validate state before performing an operation
- how to design a simple C++ data structure with exceptions

### Common pitfalls
- forgetting to sort before calculating span
- not checking the number of elements before `shortestSpan()` and `longestSpan()`
- using `std::abs` incorrectly with integers
- not handling the `max_size` limit properly

### Oral defense idea
> I created a fixed-size `Span` class that stores integers and calculates the shortest and longest gaps between them. It uses a vector internally, supports both single-value and range insertion, and throws exceptions when the container is full or when there are not enough elements to calculate a span.

---

## Exercise 02 - `MutantStack`

### Core idea
A `MutantStack` is a custom stack that exposes the underlying container’s iterators.

It inherits from `std::stack<T>` and adds:
- `begin()`
- `end()`
- `rbegin()`
- `rend()`

This makes the stack behave more like a container than a strict LIFO-only structure.

### Why this is interesting
`std::stack` is an adapter, not a full container. Internally it uses another container, usually `std::deque`.

The key idea is:
- `std::stack` hides the underlying container API
- `MutantStack` reveals it again through iterators

This demonstrates a strong C++ design pattern: reusing a standard container while changing the public interface.

### Typical structure
```cpp
template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;

        iterator begin();
        iterator end();
        reverse_iterator rbegin();
        reverse_iterator rend();
};
```

### Implementation detail
The iterators are just forwarded to the underlying container:
```cpp
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return (this->c.begin());
}
```

This works because the base class `std::stack` stores its elements in a member named `c`.

### What this allows
You can do things like:
```cpp
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);
mstack.push(3);

for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
    std::cout << *it << " ";
```

So even though it is a stack, it can be iterated just like a standard sequence container.

### Why this is a classic STL exercise
It teaches:
- the difference between container adapters and full containers
- how inheritance can expose container internals
- how to expose `begin/end` and reverse iterator access cleanly
- the concept that a stack can still be treated as a sequence for iteration

### Important note
The iterator order is the underlying container order, not necessarily the stack push/pop order.

For `std::deque` or `std::vector`, the iteration order usually follows the internal storage order, which is a useful detail for understanding the behavior of the adapter.

### Oral defense idea
> I created a `MutantStack` class by inheriting from `std::stack` and exposing the underlying container’s iterators. This means the object still behaves like a stack, but it also allows range-based traversal, which is the key STL idea behind container adapters and iterator access.

---

## Quick comparison of the three exercises

### `easyfind`
- purpose: search for one value
- STL tool: `std::find`
- concept: generic algorithms

### `Span`
- purpose: fixed-size numeric container
- STL tool: vector + sorting + iterators
- concept: custom data structure with validation

### `MutantStack`
- purpose: iterate through a stack-like object
- STL tool: `std::stack` + iterator exposure
- concept: container adapters and iterator compatibility

---

## Common C++ STL concepts used in CPP08

### Templates
Templates let you write code once and use it with many types.

Examples:
- `easyfind<T>()`
- `MutantStack<T>`

### Iterators
Iterators are the bridge between algorithms and containers.

They let code work uniformly on:
- vectors
- lists
- deques
- custom containers

### Algorithms
STL algorithms are generic functions such as:
- `std::find`
- `std::sort`
- `std::distance`

### Exceptions
The exercises strongly rely on exceptions to signal misuse or invalid states.

Examples:
- not found
- full span
- not enough elements

### Container adapters
A container adapter provides a specialized interface on top of a standard container.

Example:
- `std::stack` uses `std::deque` internally

---

## Common mistakes to avoid
- using manual loops when STL algorithms already exist
- returning the wrong type from `easyfind()`
- forgetting to sort before span calculations
- exposing iterators without the correct typedefs
- misunderstanding the difference between a stack and a sequence container

---

## Short summary to remember
CPP08 is about understanding the STL at a practical level:
- `easyfind` teaches generic searching
- `Span` teaches fixed-size storage with validation
- `MutantStack` teaches iterator exposure from a stack adapter

The real lesson is that C++ containers and algorithms are designed to work together through a common iterator model.

---

## One-line oral defense summary
This module taught me how to use the STL as a toolkit: generic algorithms for searching, custom containers for bounded storage, and container adapters that still expose iterator-based traversal.
