/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 22:35:37 by raalifa           #+#    #+#             */
/*   Updated: 2026/03/26 22:35:37 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const std::string& type);
		Dog(const Dog& copy);
		Dog& operator=(const Dog& rhs);
		virtual ~Dog();

		virtual void makeSound() const;
};

#endif