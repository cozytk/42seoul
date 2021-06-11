#include <iostream>
#include <map>
#include <Map.hpp>

//template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > >
template<class Key, class T>
//void print_map(std::map<Key, T, Compare, Alloc> map)
void print_map(std::map<Key, T> map)
{
	if (map.empty())
	{
		std::cout << "It's empty map\n";
		return ;
	}
//	for (typename std::map<Key, T, Compare, Alloc>::iterator it = map.begin(); it != map.end(); ++it)
	for (typename std::map<Key, T>::iterator it = map.begin(); it != map.end(); ++it)
		std::cout << "Key : " << it->first << ", Value : " << it->second << std::endl;
}

//template<class Key, class T, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
template<class Key, class T>
//void print_map(ft::map<Key, T, Compare, Alloc> map)
void print_map(ft::map<Key, T> map)
{
	if (map.empty())
	{
		std::cout << "It's empty map\n";
		return ; } /*	for (typename ft::map<Key, T, Compare, Alloc>::iterator it = map.begin(); it != map.end(); ++it)*/ for (typename ft::map<Key, T>::iterator it = map.begin(); it != map.end(); ++it)std::cout << "Key : " << it->first << ", Value : " << it->second << " ft" << std::endl;
}

#include <iostream>
#include <map>

// map::count
#include <iostream>
#include <map>
// map::equal_range
#include <iostream>
#include <map>

int main ()
{
	std::map<char,int> mymap;
	ft::map<char,int> ftmap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;
	ftmap['a']=10;
	ftmap['b']=20;
	ftmap['c']=30;

	std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
	ret = mymap.equal_range('b');
	ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ft_ret;
	ft_ret = ftmap.equal_range('b');

	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';
	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';
	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << " ft\n";
	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << " ft\n";

	return 0;
}