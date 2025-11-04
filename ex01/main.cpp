#include "PhoneBook.hpp"
#include "Colors.hpp"

void handle_sigint(int signal)
{
	(void)signal;
	std::cout << ORANGE << "\nPhonebook closed, silence is golden.✨" << RESET << std::endl;
	std::exit(0);
}

std::string trim(const std::string& user_input)
{
	std::size_t first = user_input.find_first_not_of(" \t\n\r");
	if (first == std::string::npos)
		return "";
	std::size_t last = user_input.find_last_not_of(" \t\n\r");
	return user_input.substr(first, (last - first + 1));
}

int	main(void)
{
	PhoneBook	phonebook;
	std::string	user_input;
	std::signal(SIGINT, handle_sigint);

	phonebook.printOptions();
	while (std::getline(std::cin, user_input))
	{
		user_input = trim(user_input);
		if (user_input == "ADD")
			phonebook.addContact();
		else if (user_input == "SEARCH")
			phonebook.searchContact();
		else if (user_input == "EXIT")
		{
			break;
		}
		else
			std::cout << PURPLE << "Bouncer says no 🚫 Use ADD, SEARCH, or EXIT instead." << RESET << std::endl;
		phonebook.printOptions();
	}
	std::cout << ORANGE << "Phonebook closed, silence is golden.✨" << RESET << std::endl;
	return 0;
}
