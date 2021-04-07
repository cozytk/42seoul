#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iterator>
#include <algorithm>
#include <exception>

template <typename T>
typename T::iterator	easyfind(T &t, int i)
{
	typename T::iterator it = std::find(t.begin(), t.end(), i);
	if (it == t.end())
		throw std::exception();
	return (it);
}

#endif