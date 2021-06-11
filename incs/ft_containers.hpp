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
	template<typename _Arg1, typename _Arg2, typename _Result>
	struct binary_function
	{
		typedef _Arg1 first_argument_type;
		typedef _Arg2 second_argument_type;
		typedef _Result result_type;
	};
	template<class T1, class T2>
	struct pair
	{
	public:
		typedef T1 first_type;
		typedef T2 second_type;

	public:
		first_type first;
		second_type second;

	public:
		pair()
		{
		}
		template<class U, class V>
		pair(const pair<U, V> &pr) :
				first(pr.first),
				second(pr.second)
		{
		}
		pair(const first_type &a, const second_type &b) :
				first(a),
				second(b)
		{
		}
		pair&
		operator=(const pair &pr)
		{
			first = pr.first;
			second = pr.second;

			return (*this);
		}
	};

	template<class T1, class T2>
	bool
	operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}
	template<class T1, class T2>
	pair<T1, T2>
	make_pair(T1 x, T2 y)
	{
		return (pair<T1, T2>(x, y));
	}
	template<class T>
	struct less
	{
	public:
		bool
		operator()(const T &lhs, const T &rhs) const
		{
			return (lhs < rhs);
		}
	};
	template<class T>
	struct equal_to
	{
	public:
		bool
		operator()(const T &lhs, const T &rhs) const
		{
			return (lhs == rhs);
		}
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