/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 08:34:20 by raalifa           #+#    #+#             */
/*   Updated: 2026/02/07 08:34:20 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>
#include <new>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie();
		~Zombie();
		void announce() const;
		void setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif
