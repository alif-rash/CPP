#include "Contact.hpp"

void	Contact::setFirstName(std::string name)
{
	firstName = name;
}

void	Contact::setLastName(std::string name)
{
	lastName = name;
}

void	Contact::setNickName(std::string name)
{
	nickName = name;
}

void	Contact::setPhoneNumber(std::string number)
{
	phoneNumber = number;
}

void	Contact::setDarkestSecret(std::string secret)
{
	darkestSecret = secret;
}

std::string Contact::getFirstName() const
{
	return firstName;
}

std::string Contact::getLastName() const
{
	return lastName;
}

std::string Contact::getNickName() const
{
	return nickName;
}

std::string Contact::getPhoneNumber() const
{
	return phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
	return darkestSecret;
}