#include <List.hpp>
#include <ft_containers.hpp>
#include <Vector.hpp>

#include <list>

#include <iostream>
#include <list>

#include <iostream>
#include <list>

int main ()
{
	int myints[] = {75,23,65,42,13};
	std::list<int> mylist (myints,myints+5);
	ft::list<int> ftlist (myints,myints+5);

	std::cout << "mylist contains:";
	for (std::list<int>::iterator it=mylist.begin(); it != mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "ftlist contains:";
	for (ft::list<int>::iterator it=ftlist.begin(); it != ftlist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << "-> ft";
	std::cout << '\n';

	for (int i=1; i<=5; ++i) mylist.push_back(i);
	for (int i=1; i<=5; ++i) ftlist.push_back(i);

	std::cout << "mylist backwards:";
	for (std::list<int>::reverse_iterator rit=mylist.rbegin(); rit!=mylist.rend(); ++rit)
		std::cout << ' ' << *rit;
	std::cout << '\n';
	std::cout << "ftlist backwards:";
	for (ft::list<int>::reverse_iterator rit=ftlist.rbegin(); rit!=ftlist.rend(); ++rit)
		std::cout << ' ' << *rit;
	std::cout << "-> ft";
	std::cout << '\n';

	return 0;
}