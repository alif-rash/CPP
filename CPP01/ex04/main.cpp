/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:14:18 by raalifa           #+#    #+#             */
/*   Updated: 2026/02/04 12:14:18 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

void ft_read_and_replace(std::ifstream &inFile, std::ofstream &outfile, std::string toFind, std::string toReplace)
{
    std::string content;
    std::string line;
    while (std::getline(inFile, line)) {
        content += line;
        if (!inFile.eof()) content += "\n";
    }

    std::string result;
    std::size_t pos = 0;
    std::size_t found;

    while ((found = content.find(toFind, pos)) != std::string::npos)
    {
        result += content.substr(pos, found - pos);
        result += toReplace;
        pos = found + toFind.length();
    }
    result += content.substr(pos);
    outfile << result;
}

int main(int ac, char **av)
{
    std::string oldFile;
    std::string newFile;

    std:: ifstream inFile;
    std:: ofstream outFile;
    
    if (ac != 4)
    {
        std::cout << "Usage: ./file <filename> <string to find> <string to replace>\n";
        return 1;
    }
    if (!av[1] || !av[2] || std::string(av[2]).empty() || !av[3])
    {
        std::cerr << "Error: Invalid arguments. \n";
        return 1;
    }
    oldFile = av[1];
    newFile = oldFile + ".replace";
    inFile.open(oldFile.c_str());
    if (inFile.fail())
    {
        std::cerr << "Error: Couldn't open file " << oldFile << std::endl;
        return 1;
    }
    outFile.open(newFile.c_str());
    if (outFile.fail())
    {
        std::cerr<<"Error: couldn't create file " << newFile << std::endl;
        inFile.close();
        return 1;
    }
    ft_read_and_replace(inFile, outFile, av[2], av[3]);
    inFile.close();
    outFile.close();
    return 0;
}