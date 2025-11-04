#include "Contact.hpp"
#include "Colors.hpp"

Contact::Contact()
{
	_fields[0] = "First Name";
	_fields[1] = "Last Name";
	_fields[2] = "Nickname";
	_fields[3] = "Phone Number";
	_fields[4] =  "Darkest Secret";
	for (int i = 0; i < NUM_FIELDS; ++i)
		this->_contactInfo[i] = "";
}

Contact::~Contact()
{
}

bool Contact::isNameValid(const std::string &name)
{
	if (name.empty()) return false;
	for (std::size_t i = 0; i < name.length(); ++i)
	{
		if (!std::isalpha(name[i]) && name[i] != '-')
			return false;
	}
	return true;
}

bool Contact::isPhoneNumberValid(const std::string& number)
{
	if (number.empty())
		return false;
	for (std::size_t i = 0; i < number.length(); ++i)
	{
		char c = number[i];
		if (!std::isdigit(c))
			return false;
	}
	return true;
}

void Contact::setInformations(void)
{
	for (int i = 0; i < NUM_FIELDS; ++i)
	{
		while (true)
		{
			if (std::cin.eof())
			{
				std::cout << ORANGE << std::endl << "Phonebook closed, silence is golden.✨" << std::endl;
				std::exit(0);
			}
			std::string input;
			std::cout << PINK << "Enter " << _fields[i] << ": " << RESET;
			std::getline(std::cin, input);
			if (input.empty())
			{
				std::cout << PURPLE << "Come on, no blanks! Enter the contact info." << std::endl;
				continue;
			}
			if ((i == first_name || i == last_name || i == nickname) && !isNameValid(input) && !std::cin.eof())
			{
				std::cout << ORANGE << "Letters only, honey 💕" << RESET << std::endl;
				continue;
			}
			if (i == phone_number && !isPhoneNumberValid(input) && !std::cin.eof())
			{
				std::cout << ORANGE << "Aww… numbers please 💕." << RESET << std::endl;
				continue;
			}
			_contactInfo[i] = input;
			break;
		}
	}
	std::cout << PURPLE << "Contact added, yay! 💕" << std::endl;
}

void Contact::printField(const std::string& str) const
{
	if (str.length() > 10)
	{
		std::cout << "|" <<  str.substr(0, 9) << ".";
	}
	else
	{
		std::cout << "|" << std::setw(10) << std::right << str;
	}
}

void Contact::printRow(int index) const
{
	std::cout << GREEN_BOLD << "|" << RESET << std::setw(10) << std::right << index;
	printField(_contactInfo[first_name]);
	printField(_contactInfo[last_name]);
	printField(_contactInfo[nickname]);
	std::cout << "|" << std::endl;
}

void Contact::printDetails(void) const
{
	for (int i = 0; i < NUM_FIELDS; ++i)
	{
		std::cout << _fields[i] << ": " << _contactInfo[i] << std::endl;
	}
}

