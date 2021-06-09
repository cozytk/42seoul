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

namespace ft {
	template<bool, typename T = void>
	struct enable_if
	{
	};
	template<typename T>
	struct enable_if<true, T>
	{
		typedef T type;
	};
	template<class T>
	struct is_integral
	{
		static const bool value = false;
	};
	template<>
	struct is_integral<bool>
	{
		static const bool value = true;
	};
	template<>
	struct is_integral<char>
	{
		static const bool value = true;
	};
	template<>
	struct is_integral<wchar_t>
	{
		static const bool value = true;
	};
	template<>
	struct is_integral<short>
	{
		static const bool value = true;
	};
	template<>
	struct is_integral<int>
	{
		static const bool value = true;
	};
	template<>
	struct is_integral<long>
	{
		static const bool value = true;
	};
	template<>
	struct is_integral<long long>
	{
		static const bool value = true;
	};

	template<class T>
	void swap(T &a, T &b)
	{
		T c = a;
		a = b;
		b = c;
	}
	template<class InputIterator1, class InputIterator2>
	bool
	lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return (false);
			else if (*first1 < *first2)
				return (true);

			++first1;
			++first2;
		}

		return (first2 != last2);
	}

	template<class InputIterator1, class InputIterator2>
	bool
	equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (!(first1 == last1))
		{
			if (!(*first1 == *first2))
				return (false);

			++first1;
			++first2;
		}
		return (true);
	}


}

#endif

//
//namespace ft
//{

//
//	template<class T>
//	void swap(T &a, T &b)
//	{
//		T c = a;
//		a = b;
//		b = c;
//	}
//
//	template<class InputIterator1, class InputIterator2>
//	bool
//	lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
//	{
//		while (first1 != last1)
//		{
//			if (first2 == last2 || *first2 < *first1)
//				return (false);
//			else if (*first1 < *first2)
//				return (true);
//
//			++first1;
//			++first2;
//		}
//
//		return (first2 != last2);
//	}
//
//	template<class InputIterator1, class InputIterator2>
//	bool
//	equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
//	{
//		while (!(first1 == last1))
//		{
//			if (!(*first1 == *first2))
//				return (false);
//
//			++first1;
//			++first2;
//		}
//
//		return (true);
//	}
//
////	struct input_iterator_tag
////	{
////	};
////	struct output_iterator_tag
////	{
////	};
////	struct forward_iterator_tag : public input_iterator_tag
////	{
////	};
////	struct bidirectional_iterator_tag : public forward_iterator_tag
////	{
////	};
////	struct random_access_iterator_tag : public bidirectional_iterator_tag
////	{
////	};
//
//	template<bool, typename T = void>
//	struct enable_if
//	{
//	};
//
//	template<typename T>
//	struct enable_if<true, T>
//	{
//		typedef T type;
//	};
//
//	template<class InputIterator>
//	struct is_input_iter
//	{
//		static const bool value = true;
//	};
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
//}
//
//void print_vec(const std::vector<int> &vec)
//{
//	std::cout << "first element address is " << &vec.front() << std::endl;
//	std::cout << "size is " << vec.size() << std::endl;
//	std::cout << "capacity is " << vec.capacity() << std::endl;
//	std::cout << "--------element----------\n";
//	for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); it++)
//		std::cout << *it << " ";
//	std::cout << "\n--------------------------\n";
//}
//
////void ft_print_vec(ft::vector<int> vec)
//void print_vec(const ft::vector<int> &vec)
//{
//	std::cout << "first element address is " << &vec.front() << std::endl;
//	std::cout << "size is " << vec.size() << std::endl;
//	std::cout << "capacity is " << vec.capacity() << std::endl;
//	std::cout << "--------element----------\n";
//	for (ft::vector<int>::const_iterator it = vec.begin(); it != vec.end(); it++)
////		for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
//		std::cout << *it << " ";
//	std::cout << "\n--------------------------\n";
//}
//