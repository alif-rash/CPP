/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:21:23 by raalifa           #+#    #+#             */
/*   Updated: 2026/07/22 15:21:23 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data data;
    data.name = "Celine ring";
    data.age = 15;

    Data * original = &data;
    std::cout << "Original Data: " << std::endl;
    std::cout << "Name: " << original->name << std::endl;
    std::cout << "Age: " << original->age << std::endl;

    uintptr_t raw = Serializer::serialize(original);
    Data * deserialized = Serializer::deserialize(raw);
    std::cout << "\nDeserialized Data: " << std::endl;
    std::cout << "Name: " << deserialized->name << std::endl;
    std::cout << "Age: " << deserialized->age << std::endl;
}