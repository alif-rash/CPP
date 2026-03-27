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

int main()
{
	const int count = 4;
	Animal* meta[count];

	for (int i = 0; i < count; i++)
	{
		if (i % 2 == 0)
			meta[i] = new Dog();
		else
			meta[i] = new Cat();
	}

	std::cout << "\n--- Testing Sounds ---" << std::endl;
	for (int i = 0; i < count; i++)
	{
		std::cout << meta[i]->getType() << " says: ";
		meta[i]->makeSound();
	}

	std::cout << "\n--- Testing Deep Copy ---" << std::endl;
	Dog original;
	original.getBrain()->setIdea("I am the original", 0);
	
	Dog copy = original;
	std::cout << "Copy idea: " << copy.getBrain()->getIdea(0) << std::endl;
	
	original.getBrain()->setIdea("I have changed", 0);
	std::cout << "Original after change: " << original.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy after original changed: " << copy.getBrain()->getIdea(0) << std::endl;

	std::cout << "\n--- Cleaning Up ---" << std::endl;
	for (int i = 0; i < count; i++)
		delete meta[i];

	return 0;
}