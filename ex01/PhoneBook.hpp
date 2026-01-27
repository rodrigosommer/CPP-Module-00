#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact _contacts[8];
	int _contactCount;
	int _oldestIndex;

	std::string _truncateString(const std::string &str) const;
	void _displayContactRow(int index) const;

public:
	PhoneBook();
	~PhoneBook();

	void addContact();
	void searchContact() const;
	void displayAllContacts() const;
};

#endif