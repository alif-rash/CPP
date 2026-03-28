/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 07:18:53 by raalifa           #+#    #+#             */
/*   Updated: 2026/03/27 07:18:53 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "[Brain] default constructor" << std::endl;
}

Brain::Brain(const Brain& copy)
{
	std::cout << "[Brain] copy constructor" << std::endl;
	*this = copy;
}

Brain &Brain::operator=(const Brain& rhs)
{
	std::cout << "[Brain] copy assignment operator" << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = rhs.ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "[Brain] destructor" << std::endl;
}

std::string const &Brain::getIdea(int const &index)
{
	if (index >= 0 && index < 100)
		return (ideas[index]);
	return (ideas[0]);
}

void Brain::setIdea(std::string const &idea, int const &index)
{
	if (index >= 0 && index < 100)
		ideas[index] = idea;
}

