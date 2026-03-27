/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 07:10:19 by raalifa           #+#    #+#             */
/*   Updated: 2026/03/27 07:10:19 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
	protected:
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain& copy);
		Brain &operator=(const Brain& src);
		~Brain();

		std::string const &getIdea(int const &index);
		void			  setIdea(std::string const &idea, int const &index);
};

#endif