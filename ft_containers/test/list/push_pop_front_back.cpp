#include "List.hpp"
#include <iostream>
#include <list>

int main ()
{
	std::list<int> mylist (2,100);         // two ints with a value of 100
	ft::list<int> ftlist (2,100);         // two ints with a value of 100
	std::cout << "mylist contains:";
	for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "ftlist contains:";
	for (ft::list<int>::iterator it=ftlist.begin(); it!=ftlist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	mylist.push_front (300);
	ftlist.push_front (300);
	std::cout << "push_front 300\n";
	std::cout << "mylist contains:";
	for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "ftlist contains:";
	for (ft::list<int>::iterator it=ftlist.begin(); it!=ftlist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	mylist.pop_front();
	ftlist.pop_front();
	std::cout << "pop_front\n";
	std::cout << "mylist contains:";
	for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "ftlist contains:";
	for (ft::list<int>::iterator it=ftlist.begin(); it!=ftlist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	mylist.push_back (400);
	ftlist.push_back (400);
	std::cout << "push_back 400\n";
	std::cout << "mylist contains:";
	for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "ftlist contains:";
	for (ft::list<int>::iterator it=ftlist.begin(); it!=ftlist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	mylist.pop_back();
	ftlist.pop_back();
	std::cout << "pop_back\n";
	std::cout << "mylist contains:";
	for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "ftlist contains:";
	for (ft::list<int>::iterator it=ftlist.begin(); it!=ftlist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	return 0;
}