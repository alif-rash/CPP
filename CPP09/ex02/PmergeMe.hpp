#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <ctime>

class PmergeMe
{
    private:
        std::vector<int> _vec;
        std::deque<int> _deq;

        static size_t getJacobsthal(size_t n);

        static std::vector<int> mergeInsertSortVect(const std::vector<int> &input);
        static void insertBinaryVector(std::vector<int> &sorted, int val); 

        static std::deque<int> mergeInsertSortDeque(const std::deque<int> &input);
        static void insertBinaryDeque(std::deque<int> &sorted, int val);
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        int run(int ac, char **av);
    };

#endif