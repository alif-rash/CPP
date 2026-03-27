/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 22:41:14 by raalifa           #+#    #+#             */
/*   Updated: 2026/03/26 22:41:14 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	{
		const int count = 10;
		const Animal *meta[count];

		for (int i = 0; i < count; i++)
		{
			if (i < count / 2)
				meta[i] = new Dog();
			else
				meta[i] = new Cat();
		}
		std::cout << "-------------------------------------\n";
		for (int i = 0; i < count; i++)
			meta[i]->makeSound();
		std::cout << "-------------------------------------\n";
		for (int i = 0; i < count; i++)
			delete meta[i];
	}
	std::cout << "-------------------------------------\n";
	{
		std::cout << "Check deep copy of Dog class using copy constructor:\n" << std::endl;
		Dog *dog1 = new Dog;
		Dog *dog2 = new Dog(*dog1);

		delete dog1;
		delete dog2;
	}
	std::cout << "-------------------------------------\n";
	{
		std::cout << "Check deep copy of Dog class using assignment operator overload:\n" << std::endl;
		Dog *dog1 = new Dog;
		Dog *dog2 = new Dog;

		*dog1 = *dog2;
		delete dog1;
		delete dog2;
	}
	std::cout << "-------------------------------------\n";
	{
		std::cout << "Check deep copy of Cat class using copy constructor:\n" << std::endl;
		Cat *cat1 = new Cat;
		Cat *cat2 = new Cat(*cat1);

		delete cat1;
		delete cat2;
	}
	std::cout << "-------------------------------------\n";
	{
		std::cout << "Check deep copy of Cat class using assignment operator overload:\n" << std::endl;
		Cat *cat1 = new Cat;
		Cat *cat2 = new Cat;

		*cat1 = *cat2;
		delete cat1;
		delete cat2;
	}
	return (0);
}