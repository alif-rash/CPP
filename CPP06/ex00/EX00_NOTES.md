# CPP06 ex00 - Scalar Converter Notes

## Goal of the exercise
This program takes one input string and tries to convert it into the four scalar types:
- `char`
- `int`
- `float`
- `double`

The input can be:
- a normal number like `42`
- a float like `42.0f`
- a double like `42.0`
- a single character like `a`
- a pseudo-literal like `nan`, `nanf`, `+inf`, `-inf`, `+inff`, `-inff`

The program prints the result for all four types, or prints `impossible` / `Non displayable` when needed.

## Program flow
1. `main.cpp` checks that exactly one argument was passed.
2. `ScalarConverter::convert()` receives the input string.
3. `detectType()` decides what kind of literal the input looks like.
4. The correct conversion path is selected.
5. The result is printed for `char`, `int`, `float`, and `double`.

---

## File overview

### `main.cpp`
This is the entry point.

It only:
- checks argument count
- stores the input string
- calls `ScalarConverter::convert(input)`

### `ScalarConverter.hpp`
This header contains:
- the `ScalarConverter` class declaration
- the `Type` enum
- function declarations used across files
- standard library includes used by the project

### `ScalarConverter.cpp`
This file contains:
- the `ScalarConverter` class methods
- output helper functions
- the main conversion logic

### `detect.cpp`
This file contains:
- the type detection helpers
- the `detectType()` dispatcher

---

## Class and function reference

## `ScalarConverter` class
This class is used as a static utility class.

### Why it exists
The class is not meant to be instantiated. It simply groups the `convert()` function under one name.

### Special members
- `ScalarConverter()`
- `ScalarConverter(const ScalarConverter& other)`
- `ScalarConverter& operator=(const ScalarConverter& other)`
- `~ScalarConverter()`

These are private because the class should not be copied or created. They are only there to respect the orthodox Canonical Form style.

### `static void convert(const std::string& input)`
This is the main function of the exercise.

What it does:
- checks if the input is empty
- calls `detectType(input)`
- chooses the proper conversion path with `switch`
- prints the results

If the input cannot be recognized, it prints impossible for all four types.

---

## Detection functions in `detect.cpp`

### `bool skipSign(const std::string& input, size_t& i)`
This helper checks whether the string starts with `+` or `-`.

What it does:
- sets `i` to `0`
- if the first character is a sign, it moves `i` to `1`
- returns `false` if the string is only a sign

Why it exists:
- `isInt`, `isFloat`, and `isDouble` all need the same sign handling
- this removes repeated code and keeps the logic easy to read

Example:
- input `"42"` -> `i = 0`
- input `"-42"` -> `i = 1`
- input `"+"` -> invalid, returns `false`

### `bool isChar(const std::string& input)`
Checks whether the input is a character literal.

Valid cases:
- a single non-digit character like `a`
- a quoted character like `'a'`

Invalid cases:
- `1` because that is a digit
- `''` because it is empty
- `'''` because it is not a valid single character literal

Purpose:
- detect when the user probably meant a `char`

### `bool isInt(const std::string& input)`
Checks whether the string is a valid integer.

It does two things:
1. checks that the format contains only an optional sign and digits
2. checks that the value fits in an `int`

Important checks:
- `skipSign()` handles `+` / `-`
- `std::isdigit()` ensures every remaining character is a digit
- `std::strtol()` converts the value
- `errno == ERANGE` catches overflow beyond `long`
- `std::numeric_limits<int>` checks whether it fits in `int`

Example:
- `42` -> valid
- `3000000000` -> may fit in `long` on some machines, but not in `int`
- `999999999999999999` -> too large even for `long`

### `bool isFloat(const std::string& input)`
Checks whether the string looks like a float literal.

Valid pattern:
- optional sign
- digits
- one dot
- optional trailing `f`

Examples:
- `42.0f`
- `-3.5f`
- `0.1f`

It tracks:
- `dotFound` to make sure there is only one dot
- `digFound` to make sure there is at least one digit

### `bool isDouble(const std::string& input)`
Checks whether the string looks like a double literal.

Valid pattern:
- optional sign
- digits
- one dot
- no trailing `f`

Examples:
- `42.0`
- `-3.5`
- `0.1`

It uses the same style as `isFloat()` but without the final `f`.

### `bool isPseudoFloat(const std::string& input)`
Checks for float pseudo-literals.

Valid values:
- `nanf`
- `+inff`
- `-inff`

These are special values that are allowed by the subject.

### `bool isPseudoDouble(const std::string& input)`
Checks for double pseudo-literals.

Valid values:
- `nan`
- `+inf`
- `-inf`

### `Type detectType(const std::string& input)`
This function decides which type the input belongs to.

Order matters:
1. `isChar`
2. `isInt`
3. `isFloat` or `isPseudoFloat`
4. `isDouble` or `isPseudoDouble`
5. otherwise `UNKNOWN`

Why the order matters:
- a single character should be detected before number parsing
- floats are checked before doubles because `42.0f` should not be treated as a double

---

## Output functions in `ScalarConverter.cpp`

### `void printCharResult(double value)`
Prints the `char` conversion.

Rules:
- if the value is out of range, or is `nan`/`inf`, print `char: impossible`
- if the character exists but is not printable, print `char: Non displayable`
- otherwise print the character in quotes

Example:
- `42` -> `'*'`
- `7` -> `Non displayable`
- `nan` -> `impossible`

### `void printIntResult(double value)`
Prints the `int` conversion.

Rules:
- if value is `nan`, `inf`, or outside `int` range, print `int: impossible`
- otherwise print the integer value

### `void printFloatResult(double value)`
Prints the `float` conversion.

Rules:
- `nan` -> `float: nanf`
- `+inf` -> `float: +inff`
- `-inf` -> `float: -inff`
- out of float range -> `float: impossible`
- otherwise print the float with one decimal place and trailing `f`

### `void printDoubleResult(double value)`
Prints the `double` conversion.

Rules:
- `nan` -> `double: nan`
- `+inf` -> `double: +inf`
- `-inf` -> `double: -inf`
- otherwise print the value with one decimal place

### `void printError()`
Prints `impossible` for all four types.

Used when:
- the input is empty
- the input type is unknown

### `void printAllResults(double value)`
This is a helper that calls:
- `printCharResult`
- `printIntResult`
- `printFloatResult`
- `printDoubleResult`

It keeps the conversion code short and avoids repeating the same four print calls.

---

## Conversion flow in `ScalarConverter::convert()`

### `CHAR`
The character is converted to its ASCII value.

Example:
- `'a'` -> `97`

Then the value is passed to `printAllResults()`.

### `INT`
The input is converted with `std::strtol()` and then passed as a double to `printAllResults()`.

### `FLOAT`
The input is converted with `std::strtof()` and then passed as a double to `printAllResults()`.

### `DOUBLE`
The input is converted with `std::strtod()` and then passed to `printAllResults()`.

### `UNKNOWN`
If the type is not recognized, `printError()` is called.

---

## Important edge cases

### Empty input
If the user gives no value, the program prints impossible for all types.

### Non-displayable char
Some ASCII values are valid but not printable.
Example: `7` is technically a char, but it is not displayable.

### Pseudo-literals
These are special and must not be treated like normal numbers.

Float pseudo-literals:
- `nanf`
- `+inff`
- `-inff`

Double pseudo-literals:
- `nan`
- `+inf`
- `-inf`

### Range handling
Some values can be syntactically valid but still impossible to store in a given type.
That is why the output functions still check range.

---

## What you can explain in an oral defense
You can describe the project like this:

> I built a scalar converter that receives a string, detects its type, converts it into the four scalar types, and prints the result for each one. I separated detection from conversion to keep the code organized. I also handled pseudo-literals like nan and inf, and I added range checks so impossible values are reported correctly.

---

## Short summary to remember
- `main.cpp` only starts the program
- `detect.cpp` decides what the input is
- `ScalarConverter.cpp` prints the conversions
- `skipSign()` removes repeated sign handling
- `printAllResults()` removes repeated output calls
- pseudo-literals need special handling
- range checks are needed so invalid conversions print `impossible`

---

## Suggested study note
If you want to memorize the structure, remember this pattern:

**detect -> convert -> print**

That is the whole exercise.

# CPP06 ex01 - Serializer Notes

## Goal of the exercise
This exercise shows how to convert a pointer into an integer representation and then convert it back.

The important idea is:
- `serialize()` turns a `Data*` into a `uintptr_t`
- `deserialize()` turns that `uintptr_t` back into a `Data*`

This does not copy the object. It only preserves the address.

---

## What the program does
1. Creates a `Data` object.
2. Fills it with example values.
3. Stores its address using `Serializer::serialize()`.
4. Rebuilds the pointer using `Serializer::deserialize()`.
5. Prints the data again to prove the pointer still points to the same object.

---

## File overview

### `main.cpp`
This is the test program.

It:
- creates a `Data` object on the stack
- assigns values to `name` and `age`
- stores the address in a `Data*`
- serializes the pointer
- deserializes it again
- prints both the original and reconstructed data

### `Data.hpp`
This file defines the structure that is being serialized.

```cpp
struct Data
{
    std::string name;
    int age;
};
```

So `Data` is just a simple container with two fields:
- `name`
- `age`

### `Serializer.hpp`
This header declares the `Serializer` class.

It includes:
- the `Data` struct
- the `uintptr_t` type
- the function declarations

### `Serializer.cpp`
This file contains the actual conversion logic.

---

## Class reference

## `Serializer` class
This is a utility class.

### Why it exists
The class is only used to group the two static conversion functions together.

### Special members
- `Serializer()`
- `Serializer(const Serializer& other)`
- `Serializer& operator=(const Serializer& other)`
- `~Serializer()`

These are private so the class cannot be instantiated or copied.

The class is meant to be used only through static functions.

---

## Function reference

## `static uintptr_t serialize(Data* ptr)`
This function converts a pointer into an unsigned integer type.

Implementation idea:
- it uses `reinterpret_cast<uintptr_t>(ptr)`

### What it means
A pointer is just an address in memory.
`uintptr_t` is an integer type guaranteed to be able to store a pointer value.

### Example
If `ptr` points to a `Data` object, `serialize(ptr)` returns the numeric version of that address.

### Important note
This does not serialize the object content.
It only stores the address.

---

## `static Data* deserialize(uintptr_t raw)`
This function converts the integer representation back into a pointer.

Implementation idea:
- it uses `reinterpret_cast<Data*>(raw)`

### What it means
If `raw` really came from a valid `Data*`, then this gives you back the same pointer.

---

## `uintptr_t`
This is an unsigned integer type from `<stdint.h>`.

It is used because it can safely store a pointer value as an integer.

That is why it is the correct type for this exercise.

---

## `reinterpret_cast`
This cast is used to convert between pointer and integer representations.

In this exercise:
- pointer -> integer in `serialize()`
- integer -> pointer in `deserialize()`

The cast does not change the memory itself.
It only changes how the value is interpreted.

---

## Program flow in `main.cpp`

### Step 1: create the data
```cpp
Data data;
data.name = "Celine ring";
data.age = 15;
```

A normal `Data` object is created on the stack.

### Step 2: keep its address
```cpp
Data *original = &data;
```

This pointer stores the address of the object.

### Step 3: serialize the pointer
```cpp
uintptr_t raw = Serializer::serialize(original);
```

Now the address is stored as an integer.

### Step 4: deserialize it
```cpp
Data *deserialized = Serializer::deserialize(raw);
```

The integer is turned back into a pointer.

### Step 5: print values again
If everything is correct, `deserialized` points to the same object as `original`, so the values are the same.

---

## What this exercise is really teaching
This exercise is about:
- pointer representation
- casts between pointer and integer types
- static utility classes
- understanding that memory addresses can be preserved

It is not about copying objects or doing deep serialization like JSON or binary file serialization.

---

## Edge cases and important understanding

### This is not real object serialization
The name can be confusing.
The function does not save the object fields anywhere.
It only stores the pointer value.

### The pointer must still be valid
If the original object is destroyed, the deserialized pointer becomes invalid.

Example:
- serializing a stack object is fine as long as the object is still alive
- using the pointer after the object is gone would be undefined behavior

### `serialize()` and `deserialize()` are reversible here
Because the raw value came from the pointer itself, the round-trip works.

---

## What to say in an oral explanation
You can explain it like this:

> I created a utility class called `Serializer` with two static functions. `serialize()` converts a `Data*` into a `uintptr_t` using `reinterpret_cast`, and `deserialize()` converts it back into a `Data*`. This exercise demonstrates pointer-to-integer conversion and back, without copying the object.

---

## Short summary to remember
- `Data` holds the values
- `Serializer` only converts the pointer address
- `serialize()` stores a pointer as `uintptr_t`
- `deserialize()` restores the pointer from `uintptr_t`
- the object itself is never copied

---

## One-line idea
**This exercise is about preserving a memory address through an integer type and getting the same pointer back.**

# CPP06 ex02 - Base / Derived Identification Notes

## Goal of the exercise
This exercise demonstrates runtime type identification using:
- polymorphism
- `dynamic_cast`
- pointers and references
- a base class with derived classes `A`, `B`, and `C`

The program randomly creates one of the derived types and then identifies which one it is in two ways:
- through a pointer
- through a reference

---

## What the program does
1. Seeds the random generator with the current time.
2. Calls `generate()` to create an object of type `A`, `B`, or `C`.
3. Calls `identify(Base *p)` to detect the type using a pointer.
4. Calls `identify(Base &p)` to detect the type using a reference.
5. Deletes the created object.

---

## File overview

### `main.cpp`
This is the test driver.

It:
- calls `std::srand(std::time(NULL))`
- creates a random derived object with `generate()`
- prints the result of pointer identification
- prints the result of reference identification
- deletes the object at the end

### `Base.hpp`
This file declares the polymorphic base class.

It contains:
- a virtual destructor

The virtual destructor is important because it makes the base class polymorphic and allows `dynamic_cast` to work correctly.

### `A.hpp`, `B.hpp`, `C.hpp`
These files declare the three derived classes.

Each one:
- inherits from `Base`
- does not add extra members or behavior

They only exist so the program can identify which derived type was created.

### `Base.cpp`
This file defines the base destructor again.

In the current code, this is redundant because `Base.hpp` already defines the destructor inline.
So the file is not needed for the current build.

### `Makefile`
This file builds the exercise into the `base` executable.

---

## Class reference

## `Base`
The base class is used only as a parent type.

### Why it exists
It gives the derived objects a shared type so the program can work with them through `Base*` and `Base&`.

### Important detail
The destructor is virtual:
```cpp
virtual ~Base() {}
```

That makes the class polymorphic, which is required for `dynamic_cast`.

---

## Derived classes

## `A`, `B`, `C`
These are the concrete types that inherit from `Base`.

They are intentionally empty because the exercise is about identification, not extra behavior.

Their purpose is simply to be distinguishable at runtime.

---

## Function reference

## `Base *generate()`
This function creates one of the derived classes at random.

How it works:
- `rand() % 3` chooses a number from 0 to 2
- `0` returns `new A()`
- `1` returns `new B()`
- `2` returns `new C()`

### What it means
`generate()` returns a `Base*`, but the actual object behind that pointer is one of the derived classes.

### Important note
The caller must delete the returned pointer to avoid a memory leak.

---

## `void identify(Base *p)`
This function identifies the actual derived type using a pointer.

How it works:
- it tries `dynamic_cast<A*>(p)`
- if that fails, it tries `dynamic_cast<B*>(p)`
- if that fails, it tries `dynamic_cast<C*>(p)`
- if all fail, it prints `Unknown type`

### Why this works
With pointers, `dynamic_cast` returns `NULL` when the cast is invalid.
So the code can simply test each cast.

### Output
- if `p` points to an `A`, it prints `A`
- if it points to a `B`, it prints `B`
- if it points to a `C`, it prints `C`

---

## `void identify(Base &p)`
This function identifies the actual derived type using a reference.

How it works:
- it tries `dynamic_cast<A&>(p)`
- if that fails, a `std::bad_cast` exception is thrown
- it catches that exception and tries `B`
- if `B` fails, it tries `C`
- if all fail, it prints `Unknown type`

### Why this is different from the pointer version
With references, `dynamic_cast` does not return `NULL`.
Instead, it throws an exception when the cast is invalid.

So the reference version needs `try` / `catch` blocks.

---

## `main()`
This is the entry point of the program.

### Flow
```cpp
std::srand(std::time(NULL));
```
Seeds the random generator using the current time.

```cpp
Base* obj = generate();
```
Creates a random object.

```cpp
identify(obj);
```
Identifies it through a pointer.

```cpp
identify(*obj);
```
Identifies it through a reference.

```cpp
delete obj;
```
Frees the allocated object.

---

## Important concepts

### Polymorphism
`Base` must be polymorphic so that `dynamic_cast` can work.
That is why the destructor is virtual.

### `dynamic_cast`
This cast checks the real runtime type of a polymorphic object.

It is used here to answer the question:
> Is this object really an `A`, `B`, or `C`?

### Pointer vs reference behavior
- pointer cast failure -> returns `NULL`
- reference cast failure -> throws `std::bad_cast`

That is why the two `identify()` functions are written differently.

### Random generation
`rand()` chooses which derived class is created.
`std::srand(std::time(NULL))` makes the choice different each run.

---

## Edge cases and notes

### `Unknown type`
This is only printed if the object cannot be identified as `A`, `B`, or `C`.
In normal use, `generate()` always creates one of those three, so this should not happen.

### Memory management
Because `generate()` uses `new`, the returned pointer must be deleted.
That is why `delete obj;` is necessary in `main()`.

### Current code note
`Base.cpp` exists, but `Base.hpp` already defines the destructor inline.
So for this current version, `Base.cpp` is redundant and is not needed by the build.

---

## What to say in an oral explanation
You can explain the exercise like this:

> I created a polymorphic base class and three derived classes. A random derived object is created through a `Base*`. Then I identify its actual type using `dynamic_cast`, once with a pointer and once with a reference. The pointer version checks for `NULL`, while the reference version catches `std::bad_cast`.

---

## Short summary to remember
- `Base` is polymorphic because it has a virtual destructor
- `A`, `B`, and `C` are empty derived classes
- `generate()` creates one derived object at random
- `identify(Base*)` uses pointer `dynamic_cast`
- `identify(Base&)` uses reference `dynamic_cast` and exception handling
- `delete obj` is required because `generate()` uses `new`

---

## One-line idea
**This exercise is about discovering the real runtime type of a polymorphic object using `dynamic_cast`.**
