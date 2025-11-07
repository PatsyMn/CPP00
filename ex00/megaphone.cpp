#include <iostream>

std::string toUpper(const std::string& user_input)
{
	std::string upperStr = user_input;
	for (std::size_t i = 0; i < upperStr.size(); ++i)
		upperStr[i] = std::toupper(upperStr[i]);
	return upperStr;
}

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		for (int i = 1; i < ac; i++)
		{
			std::string str = av[i];
			std::cout << toUpper(str);
		}
		std::cout << std::endl;
	}
	return 0;
}
