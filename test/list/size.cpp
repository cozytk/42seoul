#include <iostream>
#include <list>
#include <List.hpp>

int main ()
{
	std::list<int> myints;
	ft::list<int> ftints;
	std::cout << "0. size: " << myints.size() << '\n';
	std::cout << "0. size: " << ftints.size() << "-> ft \n";

	for (int i=0; i<10; i++) myints.push_back(i);
	std::cout << "1. size: " << myints.size() << '\n';
	for (int i=0; i<10; i++) ftints.push_back(i);
	std::cout << "1. size: " << ftints.size() <<  "-> ft \n";

	myints.insert (myints.begin(),10,100);
	std::cout << "2. size: " << myints.size() << '\n';
	ftints.insert (ftints.begin(),10,100);
	std::cout << "2. size: " << ftints.size() <<  "-> ft \n";

	myints.pop_back();
	std::cout << "3. size: " << myints.size() << '\n';
	ftints.pop_back();
	std::cout << "3. size: " << ftints.size() <<  "-> ft \n";

	std::cout << "4. max_size: " << myints.max_size() << std::endl;
	std::cout << "4. max_size: " << ftints.max_size() << "-> ft" << std::endl;

	return 0;
}