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
// swap lists
#include <iostream>
#include <list>

int main ()
{
	std::list<int> first (3,100);   // three ints with a value of 100
	std::list<int> second (5,200);  // five ints with a value of 200
	ft::list<int> ft_first (3,100);   // three ints with a value of 100
	ft::list<int> ft_second (5,200);  // five ints with a value of 200

	print_list(first);
	print_list(second);
	print_list(ft_first);
	print_list(ft_second);

	first.swap(second);
	ft_first.swap(ft_second);

	std::cout << "first contains:";
	for (std::list<int>::iterator it=first.begin(); it!=first.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "first contains:";
	for (ft::list<int>::iterator it=ft_first.begin(); it!=ft_first.end(); it++)
		std::cout << ' ' << *it;
	std::cout << " ft \n";

	std::cout << "second contains:";
	for (std::list<int>::iterator it=second.begin(); it!=second.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "second contains:";
	for (ft::list<int>::iterator it=ft_second.begin(); it!=ft_second.end(); it++)
		std::cout << ' ' << *it;
	std::cout << " ft \n";

	return 0;
}