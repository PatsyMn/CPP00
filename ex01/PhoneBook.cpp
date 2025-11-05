#include "PhoneBook.hpp"
#include "Colors.hpp"

PhoneBook::PhoneBook()
{
	_nextContactIndex = 0;
	_totalContacts = 0;
	_phonebookFull = false;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::replaceOldestContact()
{
	for (int i = 0; i < 7; ++i)
		_contacts[i] = _contacts[i + 1];
	std::cout << PURPLE << "New contact just dropped — details time ✨" <<  RESET << std::endl;
	_contacts[7].setInformations();
}

void PhoneBook::addContact()
{
	if (_phonebookFull == true)
	{
		std::cout << ORANGE << "Phonebook's full. Kick out oldest and make drama?💋 (y/n)" << std::endl;
		std::string input;
		while (true)
		{
			std::getline(std::cin, input);
			if (std::cin.eof())
			{
				std::cout << ORANGE << "Phonebook closed, silence is golden.✨" << std::endl;
				std::exit(0);
			}
			if (input == "y")
			{
				replaceOldestContact();
				return;
			}
			if (input == "n")
			{
				std::cout << PINK << "Contacts unchanged, no drama today.🌸" << RESET << std::endl;
				return;
			}
			std::cout << PURPLE << "Focus! 'y' or 'n'." << RESET << std::endl;
		}
	}
	_contacts[_nextContactIndex].setInformations();
	_nextContactIndex++;
	_totalContacts = _nextContactIndex;
	if (_nextContactIndex == 8)
	{
		_phonebookFull = true;
	}
}

void printSeparator(int len)
{
	for (int i = 0; i < len; i++)
		std::cout << "━";
	std::cout << std::endl;
}

void printHeaders()
{
	printSeparator(46);
	std::cout 	<< "|" << GREEN_BOLD << std::setw(10) << std::right << "Index" << RESET
				<< "|" << GREEN_BOLD << std::setw(10) << std::right << "First Name" << RESET
				<< "|" << GREEN_BOLD << std::setw(10) << std::right << "Last Name" << RESET
				<< "|" << GREEN_BOLD << std::setw(10) << std::right << "Nickname" << RESET
				<< "|" << GREEN_BOLD << std::endl;
	printSeparator(46);
}

void PhoneBook::searchContact() const
{
	if (_totalContacts == 0)
	{
		std::cout << PINK << "No contacts found. Let's get social and add someone!🎉" << std::endl;
		return;
	}
	const int len = 46;
	printHeaders();
	for (int i = 0; i < _totalContacts; ++i)
	{
		_contacts[i].printRow(i + 1);
	}
	printSeparator(len);
	std::string user_input;
	int index = 0;
	std::cout	<< PURPLE << "Select your BFF to reveal the gossip.🤫" << RESET << std::endl;
	while (true)
	{
		if (!std::getline(std::cin, user_input))
		{
			std::cout << PURPLE << "Phonebook closed, silence is golden.✨" << RESET << std::endl;
			std::exit(0);
		}
		bool isNumber = true;
		for (std::size_t i = 0; i < user_input.size(); i++)
		{
			if (!std::isdigit(user_input[i]))
			{
				isNumber = false;
				break;
			}
		}
		if (!isNumber|| user_input == "0")
		{
			std::cout << ORANGE << "Try a real number! (for me 0 is sooo not it 😚)" << RESET << std::endl;
			continue;
		}
		std::istringstream user_stream(user_input);
		user_stream >> index;
		if (!user_stream.fail() && index >= 1 && index <= _totalContacts)
		{
			break;
		}
		std::cout << ORANGE << "Nope! That choice doesn't exist, sweetie." << RESET << std::endl;
	}
	_contacts[index - 1].printDetails();
}

void PhoneBook::printOptions() const
{
	std::cout
	<< ORANGE << "What's your vibe?🌈" << RESET << std::endl
	<< PINK << "> ADD" << std::endl << "> SEARCH" << std::endl << "> EXIT" << RESET << std::endl;
}
