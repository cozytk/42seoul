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

#include <iostream>
#include <map>
{
	std::map<char,int> mymap;
	ft::map<char,int> ftmap;

	mymap['x']=1001;
	mymap['y']=2002;
	mymap['z']=3003;
	ftmap['x']=1001;
	ftmap['y']=2002;
	ftmap['z']=3003;

	ftmap.value_comp();
	return 0;
}