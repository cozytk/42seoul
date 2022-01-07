#include <iostream>
#include <list>
#include <vector>
#include <List.hpp>
#include <Vector.hpp>

// erasing from list
#include <iostream>
#include <list>

template <class T>
void print_list(std::list<T> list)
{
	for (typename std::list<T>::iterator it = list.begin(); it != list.end(); it++)
		std::cout << *it << ' ';
	std::cout << "\n";
}
template <class T>
void print_list(ft::list<T> list)
{
	for (typename ft::list<T>::iterator it = list.begin(); it != list.end(); it++)
		std::cout << *it << ' ';
	std::cout << "ft \n";
}
// resizing list
#include <iostream>
#include <list>

// clearing lists
#include <iostream>
#include <list>

int main ()
{
	std::list<int> mylist;
	std::list<int>::iterator it;
	ft::list<int> ftlist;
	ft::list<int>::iterator ft;

	mylist.push_back (100);
	mylist.push_back (200);
	mylist.push_back (300);
	ftlist.push_back (100);
	ftlist.push_back (200);
	ftlist.push_back (300);

	std::cout << "mylist contains:";
	for (it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "ftlist contains:";
	for (ft=ftlist.begin(); ft!=ftlist.end(); ++ft)
		std::cout << ' ' << *ft;
	std::cout << " ft\n";

	mylist.clear();
	mylist.push_back (1101);
	mylist.push_back (2202);
	ftlist.clear();
	ftlist.push_back (1101);
	ftlist.push_back (2202);

	print_list(mylist);
	print_list(ftlist);

	return 0;
}