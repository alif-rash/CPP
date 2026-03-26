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
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "--- ANIMAL TEST ---" << std::endl;
	{
		Animal* animal = new Animal();
		animal->makeSound();
		delete animal;
	}
	std::cout << std::endl;

	{
		std::cout << "--- DOG TEST ---" << std::endl;
		Animal* dog = new Dog();
		dog->makeSound();
		delete dog;
	}
	std::cout << std::endl;

	{
		std::cout << "--- CAT TEST ---" << std::endl;
		Animal* cat = new Cat();
		cat->makeSound();
		delete cat;
	}
	std::cout << std::endl;

	{
		std::cout << "--- WRONG ANIMAL TEST ---" << std::endl;
		WrongAnimal* wrongCat = new WrongCat();
		wrongCat->makeSound();
		delete wrongCat;
	}
	return 0;
}