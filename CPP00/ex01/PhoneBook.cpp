#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>

PhoneBook::PhoneBook() : contactCount(0), oldestIndex(0) {}

std::string PhoneBook::getInput(std::string prompt)
{
	std::string input;
	std::cout << prompt;
	if (!std::getline(std::cin, input))
		exit(0);
	while (input.empty())
	{
		std::cout << "Field cannot be empty. " << prompt;
		if (!std::getline(std::cin, input))
			exit(0);
	}
	return input;
}

void	PhoneBook::addContact()
{
	Contact newContact;

	newContact.setFirstName(getInput("Enter first name: "));
	newContact.setLastName(getInput("Enter last name: "));
	newContact.setNickName(getInput("Enter nickname: "));
	newContact.setPhoneNumber(getInput("Enter phone number: "));
	newContact.setDarkestSecret(getInput("Enter darkest secret: "));

	if (contactCount >= 8)
		std::cout << "Phonebook full! Replacing oldest contact..." << std::endl;
	
	contacts[oldestIndex] = newContact;
	if (contactCount < 8)
		contactCount++;
	oldestIndex = (oldestIndex + 1) % 8;

	std::cout << "Contact added successfully!" << std::endl;
}

std::string PhoneBook::formatField(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void PhoneBook::searchContact()
{
	if (contactCount == 0)
    {
        std::cout << "Phonebook is empty!" << std::endl;
        return;
	}
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    for (int i = 0; i < contactCount; i++)
    {
        std::cout << "|" << std::setw(10) << i;
        std::cout << "|" << std::setw(10) << formatField(contacts[i].getFirstName());
        std::cout << "|" << std::setw(10) << formatField(contacts[i].getLastName());
        std::cout << "|" << std::setw(10) << formatField(contacts[i].getNickName());
        std::cout << "|" << std::endl;
    }
    std::string indexStr;
    std::cout << "Enter index: ";
    if (!std::getline(std::cin, indexStr))
        exit(0);
    if (indexStr.empty())
    {
        std::cout << "Invalid index!" << std::endl;
        return;
    }
    int index;
    std::stringstream ss(indexStr);
    if (!(ss >> index) || !ss.eof() || index < 0 || index >= contactCount)
    {
        std::cout << "Invalid index!" << std::endl;
        return;
    }
    std::cout << std::endl;
    std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickName() << std::endl;
    std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}
