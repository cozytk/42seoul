#include <iostream>
#include <list>
#include <List.hpp>

int main ()
{
	std::list<int> mylist;
	ft::list<int> ftlist;
	int sum(0);

	for (int i = 1; i <= 10; ++i) mylist.push_back(i);
	for (int i = 1; i <= 10; ++i) ftlist.push_back(i);

	while (!mylist.empty())
	{
		sum += mylist.front();
		mylist.pop_front();
	}
	std::cout << "total: " << sum << '\n';
	sum = 0;
	while (!ftlist.empty())
	{
		sum += ftlist.front();
		ftlist.pop_front();
	}
	std::cout << "total: " << sum << "-> ft\n";
	return 0;
}