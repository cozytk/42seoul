#include <iostream>
#include <list>
#include <List.hpp>

#include <iostream>
#include <list>

int main ()
{
	std::list<int> first;
	std::list<int> second;
	ft::list<int> ft_first;
	ft::list<int> ft_second;

	first.assign (7,100);                      // 7 ints with value 100
	ft_first.assign (7,100);                      // 7 ints with value 100

	second.assign (first.begin(),first.end()); // a copy of first
	ft_second.assign (first.begin(),first.end()); // a copy of first

	int myints[]={1776,7,4};
	first.assign (myints,myints+3);            // assigning from array
	ft_first.assign (myints,myints+3);            // assigning from array

	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "Size of second: " << int (second.size()) << '\n';
	std::cout << "Size of first: " << int (first.size()) << " ft\n";
	std::cout << "Size of second: " << int (second.size()) << " ft\n";
	return 0;
}
