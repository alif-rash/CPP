#include <iostream>
#include "PhoneBook.hpp"

int	main()
{
	PhoneBook 	pb;
	std::string command;

	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
			break;
		if (command == "ADD")
			pb.addContact();
		else if (command == "SEARCH")
			pb.searchContact();
		else if (command == "EXIT")
			break;
		else 
			std::cout << "Invalid command. Try again. " << std::endl;
	}
	return 0;
}
