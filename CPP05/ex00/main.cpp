/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 23:08:36 by marvin            #+#    #+#             */
/*   Updated: 2026/06/10 23:08:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(){
    try
    {
        Bureaucrat b1("John", 1);
        std::cout << b1 << std::endl;
        b1.incrementGrade();
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b2("Jane", 150);
        std::cout << b2 << std::endl;
        b2.decrementGrade();
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}