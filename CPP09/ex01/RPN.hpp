#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <list>
#include <stack>
#include <cctype>

class RPN 
{
    private:
        std::stack<int, std::list<int> > _stack;
    public:
        RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();

        void calculate(const std::string &expression);

};

#endif