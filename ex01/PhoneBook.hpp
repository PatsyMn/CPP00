#pragma once

#include "Contact.hpp"
#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <csignal>

class PhoneBook
{
private:
	Contact _contacts[8];
	int _nextContactIndex;
	int _totalContacts;
	bool _phonebookFull;

	void replaceOldestContact();
	
public:
	PhoneBook();
	~PhoneBook();

	void addContact();
	void searchContact() const;
	void printOptions() const;
};
