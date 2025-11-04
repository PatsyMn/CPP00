#pragma once

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>

class Contact
{
private:
	static const int NUM_FIELDS = 5;

	enum contact_info
	{
		first_name,
		last_name,
		nickname,
		phone_number,
		darkest_secret,
	};

	std::string _contactInfo[NUM_FIELDS];
	std::string _fields[NUM_FIELDS];
	bool	isNameValid(const std::string &name);
	bool	isPhoneNumberValid(const std::string& number);
	void	printField(const std::string& str) const;

public:
	Contact(void);
	~Contact(void);

	void setInformations(void);
	void printRow(int index) const;
	void printDetails() const;
};
