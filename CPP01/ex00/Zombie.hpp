/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 08:31:06 by raalifa           #+#    #+#             */
/*   Updated: 2026/02/07 08:31:06 by raalifa          ###   ########.fr       */
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
		Zombie(std::string name);
		~Zombie();
		void announce() const;
};

void   randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif