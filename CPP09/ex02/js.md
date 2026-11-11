# `PmergeMe.cpp` Explanation

This file implements the **Ford–Johnson merge-insertion sort**, also called **PmergeMe**, using both:

- `std::vector<int>`
- `std::deque<int>`

The program:

1. Reads positive integers from the command line.
2. Sorts them using a custom algorithm.
3. Sorts the values once with `std::vector`.
4. Sorts them once with `std::deque`.
5. Measures and displays the processing time for both containers.

## 1. Constructors and Assignment Operator

### Default constructor

```cpp
PmergeMe::PmergeMe()
{
}
```

Creates an empty `PmergeMe` object.

### Copy constructor

```cpp
PmergeMe::PmergeMe(const PmergeMe &src)
{
	*this = src;
}
```

Creates a copy of another `PmergeMe` object by calling the assignment operator.

### Assignment operator

```cpp
PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	if (this != &src)
	{
		_vec = src._vec;
		_deq = src._deq;
	}
	return (*this);
}
```

Copies both internal containers:

- `_vec`
- `_deq`

The condition prevents assigning an object to itself.

### Destructor

```cpp
PmergeMe::~PmergeMe()
{
}
```

No manual memory cleanup is required because `std::vector` and `std::deque` manage their own memory.

---

# 2. Jacobsthal Numbers

```cpp
size_t PmergeMe::getJacobsthal(size_t n)
```

This function calculates Jacobsthal numbers.

The sequence begins as follows:

```text
J(0) = 0
J(1) = 1
J(2) = 1
J(3) = 3
J(4) = 5
J(5) = 11
J(6) = 21
```

The formula is:

```text
J(n) = J(n - 1) + 2 × J(n - 2)
```

The Ford–Johnson algorithm uses Jacobsthal numbers to decide the order in which pending elements should be inserted.

```cpp
if (curr < prev)
	return (SIZE_MAX);
```

This attempts to detect unsigned integer overflow. If the calculated value wraps around, `SIZE_MAX` is returned.

---

# 3. Binary Insertion for `std::vector`

```cpp
void PmergeMe::insertBinaryVector(std::vector<int> &sorted, int val)
{
	std::vector<int>::iterator it = std::lower_bound(
		sorted.begin(), sorted.end(), val);

	sorted.insert(it, val);
}
```

This function inserts `val` into an already sorted vector.

`std::lower_bound` finds the first position where `val` can be inserted without breaking the sorted order.

For example:

```text
Before: [1, 3, 5, 8]
Value:  4
After:  [1, 3, 4, 5, 8]
```

The deque version performs the same operation using `std::deque`.

---

# 4. Vector Merge-Insertion Sort

```cpp
std::vector<int> PmergeMe::mergeInsertionSortVector(
	std::vector<int> &container)
```

This function implements the sorting algorithm for `std::vector`.

## 4.1 Base Case

```cpp
if (container.size() <= 1)
	return (container);
```

A container with zero or one element is already sorted, so it is returned immediately.

---

## 4.2 Create Pairs

The input values are grouped into pairs.

For example:

```text
Input:
[7, 2, 9, 4, 1]

Pairs:
(7, 2)
(9, 4)

Straggler:
1
```

If the input contains an odd number of elements, the last element is stored separately as a **straggler**.

Each pair is reordered so the larger value comes first:

```cpp
if (container[i] > container[i + 1])
	pairs.push_back(std::make_pair(container[i], container[i + 1]));
else
	pairs.push_back(std::make_pair(container[i + 1], container[i]));
```

Every pair has this structure:

```text
(larger value, smaller value)
```

For example:

```text
(7, 2)
(9, 4)
```

---

## 4.3 Build the Main Chain

Only the larger value from every pair is placed into `mainChain`.

```cpp
std::vector<int> mainChain;

for (size_t i = 0; i < pairs.size(); ++i)
	mainChain.push_back(pairs[i].first);
```

For example:

```text
Pairs:
(7, 2)
(9, 4)

Main chain:
[7, 9]
```

---

## 4.4 Recursively Sort the Main Chain

```cpp
std::vector<int> sortedMain =
	mergeInsertionSortVector(mainChain);
```

The larger values are recursively sorted.

For example:

```text
Before: [9, 7]
After:  [7, 9]
```

The sorted larger values form the initial main chain.

---

## 4.5 Reorder the Pairs

The pairs must be reordered so they match the sorted order of their larger values.

```cpp
std::vector<std::pair<int, int> > sortedPairs;
std::vector<bool> visited(pairs.size(), false);
```

The nested loops search for the pair associated with each sorted larger value:

```cpp
for (size_t i = 0; i < sortedMain.size(); ++i)
{
	for (size_t j = 0; j < pairs.size(); ++j)
	{
		if (!visited[j] && pairs[j].first == sortedMain[i])
		{
			sortedPairs.push_back(pairs[j]);
			visited[j] = true;
			break ;
		}
	}
}
```

The `visited` container prevents the same pair from being selected more than once.

---

## 4.6 Insert the First Smaller Element

```cpp
std::vector<int> result = sortedMain;
result.insert(result.begin(), pairs[0].second);
```

The smaller value from the first pair is inserted at the beginning.

For example:

```text
Sorted main chain:
[7, 9]

First pair:
(7, 2)

Result:
[2, 7, 9]
```

This is valid because the smaller value is guaranteed to be less than or equal to its partner.

---

## 4.7 Insert Remaining Values Using Jacobsthal Order

```cpp
size_t pendingCount = pairs.size();
size_t k = 2;
size_t insertedCount = 1;
```

One smaller value has already been inserted, so `insertedCount` begins at `1`.

The remaining smaller values are inserted in an order based on Jacobsthal numbers:

```cpp
while (insertedCount < pendingCount)
```

The code calculates the boundaries of each insertion group:

```cpp
size_t nextJacobsthal = getJacobsthal(k);

if (nextJacobsthal >= pendingCount)
	nextJacobsthal = pendingCount;

size_t limit = nextJacobsthal;
size_t start = getJacobsthal(k - 1);
```

The values in each group are processed in reverse order:

```cpp
for (size_t i = limit; i > start; --i)
```

This ordering is a key part of the Ford–Johnson algorithm.

---

## 4.8 Binary Search Before the Partner

For each pair, the smaller value is inserted before its larger partner:

```cpp
int valToInsert = pairs[i - 1].second;
int partnerValue = pairs[i - 1].first;
```

First, the code locates the partner:

```cpp
std::vector<int>::iterator partnerIt =
	std::lower_bound(result.begin(), result.end(), partnerValue);
```

Then it searches for the smaller value only in the range before the partner:

```cpp
std::vector<int>::iterator pos =
	std::lower_bound(result.begin(), partnerIt, valToInsert);
```

Finally, it inserts the value:

```cpp
result.insert(pos, valToInsert);
```

For example, for the pair:

```text
(10, 4)
```

the value `4` only needs to be searched for before `10`.

This reduces the number of comparisons.

---

## 4.9 Insert the Straggler

If the original input had an odd number of elements, the unmatched value is inserted at the end:

```cpp
if (hasStraggler)
	insertBinaryVector(result, straggler);
```

The straggler is inserted using binary search over the complete sorted result.

---

## 4.10 Store the Sorted Vector

```cpp
void PmergeMe::sortVector(std::vector<int> &container)
{
	container = mergeInsertionSortVector(container);
}
```

The sorted result is assigned back to the original vector.

---

# 5. Deque Implementation

The deque implementation follows the same algorithm as the vector implementation.

The main differences are the container types:

```cpp
std::deque<std::pair<int, int> > pairs;
std::deque<int> mainChain;
std::deque<int> result;
```

The binary insertion function also uses a deque:

```cpp
void PmergeMe::insertBinaryDeque(std::deque<int> &sorted, int val)
```

The algorithm is unchanged:

1. Pair the values.
2. Put the larger value of every pair into the main chain.
3. Recursively sort the main chain.
4. Reorder the pairs.
5. Insert smaller values using Jacobsthal ordering.
6. Insert the straggler, if one exists.

```cpp
void PmergeMe::sortDeque(std::deque<int> &container)
{
	container = mergeInsertionSortDeque(container);
}
```

---

# 6. The `run` Function

```cpp
int PmergeMe::run(int argc, char **argv)
```

This function controls the entire program.

## 6.1 Check for Arguments

```cpp
if (argc < 2)
{
	std::cerr << "Error" << std::endl;
	return (1);
}
```

The program requires at least one command-line argument.

---

## 6.2 Parse the Input

Each command-line argument is converted from a string to a number:

```cpp
long val = std::strtol(argv[i], &endptr, 10);
```

The code rejects invalid values when:

```cpp
argv[i] == endptr
```

No characters were converted.

```cpp
*endptr != '\0'
```

The input contained invalid trailing characters, such as:

```text
123abc
```

```cpp
val < 0
```

Negative numbers are not allowed.

```cpp
val > INT_MAX
```

The value cannot fit inside an `int`.

```cpp
errno == ERANGE
```

The value was outside the range supported by `strtol`.

Valid values are stored in both containers:

```cpp
_vec.push_back(static_cast<int>(val));
_deq.push_back(static_cast<int>(val));
```

---

## 6.3 Reject Insufficient Input

```cpp
if ((_vec.empty() && _deq.empty()) ||
	(_vec.size() == 1 && _deq.size() == 1))
{
	std::cerr << "Error: No valid / enough numbers provided" << std::endl;
	return (1);
}
```

The program rejects:

- Empty input
- Input containing only one number

---

## 6.4 Print the Original Input

```cpp
printContainer("Before: ", _vec);
```

This displays the values before sorting.

---

## 6.5 Measure Vector Sorting Time

```cpp
clock_t start = clock();
sortVector(_vec);
clock_t end = clock();
```

The elapsed CPU time is converted to microseconds:

```cpp
double timeVec =
	static_cast<double>(end - start)
	/ CLOCKS_PER_SEC * 1000000;
```

---

## 6.6 Measure Deque Sorting Time

The same process is repeated for the deque:

```cpp
start = clock();
sortDeque(_deq);
end = clock();
```

The result is stored in `timeDeq`.

---

## 6.7 Print the Final Results

```cpp
printContainer("After:  ", _vec);
```

The sorted values are displayed.

Then the execution times are printed:

```text
Time to process a range of N elements with std::vector : ... us
Time to process a range of N elements with std::deque  : ... us
```

---

# 7. Example of the Algorithm

Given this input:

```text
[7, 2, 9, 4, 1]
```

## Step 1: Pair the values

```text
(7, 2)
(9, 4)
```

The remaining value is the straggler:

```text
1
```

## Step 2: Build the main chain

Take the larger value from each pair:

```text
[7, 9]
```

## Step 3: Sort the main chain

```text
[7, 9]
```

## Step 4: Insert the first smaller value

```text
[2, 7, 9]
```

## Step 5: Insert the remaining smaller value

Insert `4` before its partner `9`:

```text
[2, 4, 7, 9]
```

## Step 6: Insert the straggler

Insert `1` using binary search:

```text
[1, 2, 4, 7, 9]
```

---

# 8. Important Observations

## Duplicate values

The code can sort duplicate values, but pair reconstruction is based on comparing only the larger values:

```cpp
pairs[j].first == sortedMain[i]
```

If several pairs have the same larger value, their original relationships may become ambiguous. The `visited` container prevents reusing the same pair.

## Vector and deque code duplication

The vector and deque implementations are almost identical. The main difference is the container type.

In a newer C++ version, this logic could potentially be generalized with templates. However, separate implementations are common in C++98 projects.

## Timing method

The code uses:

```cpp
clock()
```

This measures CPU time rather than necessarily measuring real wall-clock time. It is generally acceptable for this exercise, but the result can differ from the actual elapsed time experienced by the user.

## Insertion cost

Although `std::lower_bound` reduces the number of comparisons, inserting into the middle of a vector or deque can still require moving elements.

The Ford–Johnson algorithm mainly optimizes the number of comparisons, not necessarily the physical movement of elements.

---

# 9. Overall Summary

The program uses the Ford–Johnson merge-insertion algorithm:

```text
1. Pair the input values.
2. Put the larger value of each pair into a main chain.
3. Recursively sort the main chain.
4. Reorder the original pairs.
5. Insert the smaller values in Jacobsthal order.
6. Insert any unmatched straggler.
7. Repeat the process for vector and deque.
8. Compare their execution times.
```

The important optimization is that each smaller value is inserted only within the portion of the sorted result before its known larger partner.