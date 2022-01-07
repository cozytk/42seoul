#include <iostream>
#include <string>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *a = &str;
	std::string &b = str;

	std::cout << "Output, pointer a\n";
	std::cout << *a << std::endl;
	std::cout << "Output, reference b\n";
	std::cout << b << std::endl;
}