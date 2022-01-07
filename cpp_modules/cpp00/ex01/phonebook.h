#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <iomanip>
#include <string>

#define SAME 0

class Phonebook {
private:
	int index;
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string login;
	std::string postal_address;
	std::string email_address;
	std::string phone_number;
	std::string birthday_date;
	std::string favorite_meal;
	std::string underwear_color;
	std::string darkest_secret;

public:
	void print_str(std::string str)
	{
		std::cout << '|';
		if (str.length() > 9)
		{
			str.resize(9);
			std::cout << str << '.';
		}
		else
			std::cout << std::setw(10) << str;
		std::cout << '|' << std::endl;

	}
	void display()
	{
		std::cout << '|' << std::setw(10) << index + 1 << '|' << std::endl;
		print_str(first_name);
		print_str(last_name);
		print_str(nick_name);
	}
	void get_info(int i)
	{
		this->index = i;
		std::cout << "FIRST NAME : ";
		std::cin >> this->first_name;
		std::cout << "LAST NAME : ";
		std::cin >> this->last_name;
		std::cout << "NICKNAME : ";
		std::cin >> this->nick_name;
		std::cout << "LOGIN : ";
		std::cin >> this->login;
		std::cout << "POSTAL ADRESS : ";
		std::cin >> this->postal_address;
		std::cout << "EMAIL ADDRESS : ";
		std::cin >> this->email_address;
		std::cout << "PHONE NUMBER : ";
		std::cin >> this->phone_number;
		std::cout << "BIRTHDAY DATE : ";
		std::cin >> this->birthday_date;
		std::cout << "FAVORITE MEAL : ";
		std::cin >> this->favorite_meal;
		std::cout << "UNDERWEAR COLOR : ";
		std::cin >> this->underwear_color;
		std::cout << "DARKEST SECRET : ";
		std::cin >> this->darkest_secret;
	}
	void search()
	{
		std::cout << this->first_name << std::endl;
		std::cout << this->last_name << std::endl;
		std::cout << this->nick_name << std::endl;
		std::cout << this->login << std::endl;
		std::cout << this->postal_address << std::endl;
		std::cout << this->email_address << std::endl;
		std::cout << this->phone_number << std::endl;
		std::cout << this->birthday_date << std::endl;
		std::cout << this->favorite_meal << std::endl;
		std::cout << this->underwear_color << std::endl;
		std::cout << this->darkest_secret << std::endl;
	}
};
#endif
