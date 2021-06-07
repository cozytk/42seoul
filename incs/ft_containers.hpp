#ifndef FT_CONTAINERS_HPP
#define FT_CONTAINERS_HPP

/*
 * STD Library
 */

#include <memory>
#include <iostream>

/*
 * ft Library
 */

#include <Vector.hpp>
//#include <iterator.hpp>
namespace ft
{

	struct input_iterator_tag
	{
	};
	struct output_iterator_tag
	{
	};
	struct forward_iterator_tag : public input_iterator_tag
	{
	};
	struct bidirectional_iterator_tag : public forward_iterator_tag
	{
	};
	struct random_access_iterator_tag : public bidirectional_iterator_tag
	{
	};

	template<bool, typename T = void>
	struct enable_if
	{
	};

	template<typename T>
	struct enable_if<true, T>
	{
		typedef T type;
	};

	template<class InputIterator>
	struct is_input_iter
	{
		static const bool value = true;
	};
//template <class T>
//struct is_integral { static const bool value = false; };
//template <>
//struct is_integral<bool> { static const bool value = true; };
//template <>
//struct is_integral<char> { static const bool value = true; };
//template <>
//struct is_integral<wchar_t> { static const bool value = true; };
//template <>
//struct is_integral<short> { static const bool value = true; };
//template <>
//struct is_integral<int> { static const bool value = true; };
//template <>
//struct is_integral<long> { static const bool value = true; };
//template <>
//struct is_integral<long long> { static const bool value = true; };
}
#endif
