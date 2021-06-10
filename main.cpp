#include <iostream>
#include <map>
#include <Map.hpp>

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
	bool operator() (const char& lhs, const char& rhs) const
	{return lhs<rhs;}
};

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
		return ;
	}
//	for (typename ft::map<Key, T, Compare, Alloc>::iterator it = map.begin(); it != map.end(); ++it)
	for (typename ft::map<Key, T>::iterator it = map.begin(); it != map.end(); ++it)
		std::cout << "Key : " << it->first << ", Value : " << it->second << std::endl;
}

// assignment operator with maps
#include <iostream>
#include <map>
int main ()
{
	std::map<char,int> mymap;
	ft::map<char,int> ftmap;
	mymap['a']=101;
	mymap['b']=202;
	mymap['c']=302;
	ftmap['a']=101;
	ftmap['b']=202;
	ftmap['c']=302;

	std::cout << "mymap.size() is " << mymap.size() << '\n';
	std::cout << "ftmap.size() is " << ftmap.size() << '\n';
	std::cout << "mymap.size() is " << mymap.max_size() << '\n';
	std::cout << "ftmap.size() is " << ftmap.max_size() << '\n';
	return 0;
}