#include <iostream>

int main()
{
    std::string val = "HI THIS IS BRAIN";
    std::string *valPTR = &val;
    std::string &valREF = val;

    std::cout << "The memory address of the string:\t " << &val << std::endl;
    std::cout << "The memory address of the stringPTR:\t " << valPTR << std::endl;
    std::cout << "The memory address of the stringREF:\t " << &valREF << std::endl << std::endl;
    std::cout << "The value of the string:\t " << val << std::endl;
    std::cout << "The value pointed to by stringPTR:\t " << *valPTR << std::endl;
    std::cout << "The value referred to by stringREF:\t " << valREF << std::endl;


}