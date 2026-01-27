#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>

PhoneBook::PhoneBook() : _contactCount(0), _oldestIndex(0)
{
}

PhoneBook::~PhoneBook()
{
}

std::string PhoneBook::_truncateString(const std::string &str) const
{
	std::string result = str;
	for (size_t i = 0; i < result.length(); i++)
	{
		if (result[i] == '\t')
			result[i] = ' ';
	}
	if (result.length() > 10)
		return result.substr(0, 9) + ".";
	return result;
}

void PhoneBook::_displayContactRow(int index) const
{
	std::cout << "|" << std::setw(10) << index;
	std::cout << "|" << std::setw(10) << _truncateString(_contacts[index].getFirstName());
	std::cout << "|" << std::setw(10) << _truncateString(_contacts[index].getLastName());
	std::cout << "|" << std::setw(10) << _truncateString(_contacts[index].getNickname());
	std::cout << "|" << std::endl;
}

void PhoneBook::addContact()
{
	Contact newContact;
	std::string input;

	std::cout << "Enter first name: ";
	while (std::getline(std::cin, input) && input.empty())
		std::cout << "Enter first name: ";
	if (std::cin.eof())
		return;
	newContact.setFirstName(input);

	std::cout << "Enter last name: ";
	while (std::getline(std::cin, input) && input.empty())
		std::cout << "Enter last name: ";
	if (std::cin.eof())
		return;
	newContact.setLastName(input);

	std::cout << "Enter nickname: ";
	while (std::getline(std::cin, input) && input.empty())
		std::cout << "Enter nickname: ";
	if (std::cin.eof())
		return;
	newContact.setNickname(input);

	std::cout << "Enter phone number: ";
	while (std::getline(std::cin, input) && input.empty())
		std::cout << "Enter phone number: ";
	if (std::cin.eof())
		return;
	newContact.setPhoneNumber(input);

	std::cout << "Enter darkest secret: ";
	while (std::getline(std::cin, input) && input.empty())
		std::cout << "Enter darkest secret: ";
	if (std::cin.eof())
		return;
	newContact.setDarkestSecret(input);

	if (_contactCount < 8)
	{
		_contacts[_contactCount] = newContact;
		_contactCount++;
	}
	else
	{
		_contacts[_oldestIndex] = newContact;
		_oldestIndex = (_oldestIndex + 1) % 8;
	}
	std::cout << "Contact added successfully!" << std::endl;
}

void PhoneBook::displayAllContacts() const
{
	if (_contactCount == 0)
	{
		std::cout << "No contacts to display." << std::endl;
		return;
	}

	std::cout << "|" << std::setw(10) << "Index";
	std::cout << "|" << std::setw(10) << "First Name";
	std::cout << "|" << std::setw(10) << "Last Name";
	std::cout << "|" << std::setw(10) << "Nickname";
	std::cout << "|" << std::endl;

	for (int i = 0; i < _contactCount; i++)
	{
		if (!_contacts[i].isEmpty())
			_displayContactRow(i);
	}
}

void PhoneBook::searchContact() const
{
	if (_contactCount == 0)
	{
		std::cout << "No contacts to display." << std::endl;
		return;
	}

	displayAllContacts();

	std::cout << "Enter the index of the contact to display: ";
	std::string input;
	if (!std::getline(std::cin, input))
		return;

	if (input.length() != 1 || !std::isdigit(input[0]))
	{
		std::cout << "Invalid index." << std::endl;
		return;
	}

	int index = input[0] - '0';
	if (index < 0 || index >= _contactCount)
	{
		std::cout << "Invalid index." << std::endl;
		return;
	}

	std::cout << "First Name: " << _contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << _contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << _contacts[index].getNickname() << std::endl;
	std::cout << "Phone Number: " << _contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << _contacts[index].getDarkestSecret() << std::endl;
}