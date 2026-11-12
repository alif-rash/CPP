#include "RPN.hpp"
#include <cctype>

RPN::RPN() {}

RPN::RPN(const RPN &other) 
{
    *this = other;
}

RPN &RPN::operator=(const RPN &other) 
{
    if (this != &other) 
    {
        _stack = other._stack;
    }
    return *this;
}

RPN::~RPN() {}

void RPN::calculate(const std::string &expression)
{
    if (expression.empty())
        throw std::runtime_error("Error");
    for (size_t i = 0; i < expression.length(); ++i) 
    {
        char c = expression[i];
        if (std::isspace(c))
            continue;

        if (i + 1 < expression.length() && !std::isspace(expression[i + 1]))
            throw std::runtime_error("Error");
            
        if (std::isdigit(c)) 
            _stack.push(c - '0');
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            if (_stack.size() < 2)
                throw std::runtime_error("Error");
            int a  = _stack.top(); _stack.pop();
            int b  = _stack.top(); _stack.pop();
            if (c == '+')
                _stack.push(b + a);
            else if (c == '-')
                _stack.push(b - a);
            else if (c == '*')
                _stack.push(b * a);
            else if (c == '/')
            {
                if (a == 0)
                    throw std::runtime_error("Error");
                _stack.push(b / a);
            }
        }
        else
            throw std::runtime_error("Error");

    }
    if (_stack.size() != 1)
        throw std::runtime_error("Error");
    else
        std::cout << _stack.top() << std::endl;
}