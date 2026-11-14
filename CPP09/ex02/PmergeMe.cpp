#include "PmergeMe.hpp"
#include <algorithm>
#include <utility>
#include <cstdlib>
#include <climits>
#include <cerrno>
#include <iomanip>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) 
{
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) 
{
    if (this != &other) 
    {
        _vec = other._vec;
        _deq = other._deq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

size_t PmergeMe::getJacobsthal(size_t n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    return getJacobsthal(n - 1) + 2 * getJacobsthal(n - 2);
}

// ----------------------------------------------------
// Vector Implementation
// ----------------------------------------------------

void PmergeMe::insertBinaryVector(std::vector<int> &sorted, int val)
{
    std::vector<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), val);
    sorted.insert(it, val);
}

std::vector<int> PmergeMe::mergeInsertSortVect(const std::vector<int> &input)
{
    if (input.size() <= 1)
        return input;

    bool hasStraggler = (input.size() % 2 != 0);
    int straggler = 0;
    if (hasStraggler)
        straggler = input.back();

    std::vector<std::pair<int, int> > pairs;
    size_t pairCount = input.size() / 2;
    for (size_t i = 0; i < pairCount; i++)
    {
        int a = input[i * 2];
        int b = input[i * 2 + 1];
        if (a > b)
            pairs.push_back(std::make_pair(a, b));
        else
            pairs.push_back(std::make_pair(b, a));
    }

    std::vector<int> mainChain;
    for (size_t i = 0; i < pairs.size(); i++)
        mainChain.push_back(pairs[i].first);

    std::vector<int> sortMain = mergeInsertSortVect(mainChain);

    std::vector<std::pair<int, int> > sortedPairs;
    std::vector<bool> visited(pairs.size(), false);
    for (size_t i = 0; i < sortMain.size(); i++)
    {
        for (size_t j = 0; j < pairs.size(); j++)
        {
            if (!visited[j] && pairs[j].first == sortMain[i])
            {
                sortedPairs.push_back(pairs[j]);
                visited[j] = true;
                break;
            }
        }
    }

    std::vector<int> result = sortMain;
    result.insert(result.begin(), sortedPairs[0].second);

    size_t pendingCount = sortedPairs.size();
    size_t k = 3;
    size_t insertedCount = 1;

    while (insertedCount < pendingCount)
    {
        size_t jIndex = getJacobsthal(k);
        if (jIndex > pendingCount)
            jIndex = pendingCount;
        size_t prevJ = getJacobsthal(k - 1);

        for (size_t i = jIndex; i > prevJ; i--)
        {
            int valToInsert = sortedPairs[i - 1].second;
            int partnerVal = sortedPairs[i - 1].first;

            std::vector<int>::iterator partnerIt = std::lower_bound(result.begin(), result.end(), partnerVal);
            std::vector<int>::iterator pos = std::lower_bound(result.begin(), partnerIt, valToInsert);
            result.insert(pos, valToInsert);
            insertedCount++;
        }
        k++;
    }

    if (hasStraggler)
        insertBinaryVector(result, straggler);

    return result;
}

// ----------------------------------------------------
// Deque Implementation
// ----------------------------------------------------

void PmergeMe::insertBinaryDeque(std::deque<int> &sorted, int val)
{
    std::deque<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), val);
    sorted.insert(it, val);
}

std::deque<int> PmergeMe::mergeInsertSortDeque(const std::deque<int> &input)
{
    if (input.size() <= 1)
        return input;

    bool hasStraggler = (input.size() % 2 != 0);
    int straggler = 0;
    if (hasStraggler)
        straggler = input.back();

    std::deque<std::pair<int, int> > pairs;
    size_t pairCount = input.size() / 2;
    for (size_t i = 0; i < pairCount; i++)
    {
        int a = input[i * 2];
        int b = input[i * 2 + 1];
        if (a > b)
            pairs.push_back(std::make_pair(a, b));
        else
            pairs.push_back(std::make_pair(b, a));
    }

    std::deque<int> mainChain;
    for (size_t i = 0; i < pairs.size(); i++)
        mainChain.push_back(pairs[i].first);

    std::deque<int> sortMain = mergeInsertSortDeque(mainChain);

    std::deque<std::pair<int, int> > sortedPairs;
    std::deque<bool> visited(pairs.size(), false);
    for (size_t i = 0; i < sortMain.size(); i++)
    {
        for (size_t j = 0; j < pairs.size(); j++)
        {
            if (!visited[j] && pairs[j].first == sortMain[i])
            {
                sortedPairs.push_back(pairs[j]);
                visited[j] = true;
                break;
            }
        }
    }

    std::deque<int> result = sortMain;
    result.insert(result.begin(), sortedPairs[0].second);

    size_t pendingCount = sortedPairs.size();
    size_t k = 3;
    size_t insertedCount = 1;

    while (insertedCount < pendingCount)
    {
        size_t jIndex = getJacobsthal(k);
        if (jIndex > pendingCount)
            jIndex = pendingCount;
        size_t prevJ = getJacobsthal(k - 1);

        for (size_t i = jIndex; i > prevJ; i--)
        {
            int valToInsert = sortedPairs[i - 1].second;
            int partnerVal = sortedPairs[i - 1].first;

            std::deque<int>::iterator partnerIt = std::lower_bound(result.begin(), result.end(), partnerVal);
            std::deque<int>::iterator pos = std::lower_bound(result.begin(), partnerIt, valToInsert);
            result.insert(pos, valToInsert);
            insertedCount++;
        }
        k++;
    }

    if (hasStraggler)
        insertBinaryDeque(result, straggler);

    return result;
}

// ----------------------------------------------------
// Runner & Input Parsing
// ----------------------------------------------------

int PmergeMe::run(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    for (int i = 1; i < ac; i++)
    {
        std::string arg = av[i];
        if (arg.empty())
        {
            std::cerr << "Error" << std::endl;
            return 1;
        }

        char *endptr;
        errno = 0;
        long val = std::strtol(av[i], &endptr, 10);

        if (endptr == av[i] || *endptr != '\0' || errno == ERANGE || val < 0 || val > INT_MAX)
        {
            std::cerr << "Error" << std::endl;
            return 1;
        }

        _vec.push_back(static_cast<int>(val));
        _deq.push_back(static_cast<int>(val));
    }

    // Print Before
    std::cout << "Before: ";
    for (size_t i = 0; i < _vec.size(); i++)
    {
        std::cout << _vec[i];
        if (i + 1 < _vec.size())
            std::cout << " ";
    }
    std::cout << std::endl;

    // Vector sort & timing
    std::clock_t startVec = std::clock();
    _vec = mergeInsertSortVect(_vec);
    std::clock_t endVec = std::clock();
    double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000.0;

    // Deque sort & timing
    std::clock_t startDeq = std::clock();
    _deq = mergeInsertSortDeque(_deq);
    std::clock_t endDeq = std::clock();
    double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000.0;

    // Print After
    std::cout << "After:  ";
    for (size_t i = 0; i < _vec.size(); i++)
    {
        std::cout << _vec[i];
        if (i + 1 < _vec.size())
            std::cout << " ";
    }
    std::cout << std::endl;

    // Print Timings
    std::cout << "Time to process a range of " << _vec.size()
              << " elements with std::vector : " << std::fixed << std::setprecision(5) << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << _deq.size()
              << " elements with std::deque  : " << std::fixed << std::setprecision(5) << timeDeq << " us" << std::endl;

    return 0;
}
