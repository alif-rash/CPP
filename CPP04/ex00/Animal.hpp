/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 22:10:39 by raalifa           #+#    #+#             */
/*   Updated: 2026/03/26 22:10:39 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(const std::string& type);
		Animal(const Animal& copy);
		Animal& operator=(const Animal& src);
		virtual ~Animal();

		virtual void makeSound() const;

		void setType(const std::string& type);
		const std::string &getType() const;
};

#endif