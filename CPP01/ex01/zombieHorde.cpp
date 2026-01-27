#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    if (N < 1)
    {
        std::cout << "N cant be less than 1 " << std::endl;
        return (NULL);
    }
    Zombie* horde = new Zombie[N];
    if (!horde)
    {
        std::cout << "allocation failed!!" << std::endl;
        return (NULL);
    }
    for (int i = 0; i < N; i++)
    {
        horde[i].setName(name);
    }
    return horde;
}