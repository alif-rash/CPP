/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 22:29:36 by raalifa           #+#    #+#             */
/*   Updated: 2026/03/26 22:29:36 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
	    Brain* brain;
	public:
		Cat();
		Cat(const Cat& copy);
		Cat& operator=(const Cat& rhs);
		virtual ~Cat();

		virtual void makeSound() const;
		Brain*	getBrain() const;
};

#endif