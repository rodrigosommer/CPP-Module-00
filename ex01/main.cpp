#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main()
{
	PhoneBook phoneBook;
	std::string command;

	std::cout << "Welcome to Your Awesome PhoneBook!" << std::endl;
	std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;

	while (true)
	{
		std::cout << "Enter a command: ";
		if (!std::getline(std::cin, command))
			break;

		if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
			phoneBook.searchContact();
		else if (command == "EXIT")
			break;
	}

	return 0;
}