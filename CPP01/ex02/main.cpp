#include <iostream>

int main()
{
    std::string name = "HI THIS IS BRAIN";
    std::string *namePTR = &name;
    std::string &nameREF = name;

    std::cout << "The address of the string:\t " << &name << std::endl;
    std::cout << "The address of the stringPTR:\t " << &namePTR << std::endl;
    std::cout << "The address of the stringREF:\t " << &nameREF << std::endl << std::endl;

    std::cout << "The string:\t " << name << std::endl;
    std::cout << "The stringPTR:\t " << namePTR << std::endl;
    std::cout << "The stringREF:\t " << nameREF << std::endl;


}