#ifndef FT_COTAINERS_VECTOR_HPP
#define FT_COTAINERS_VECTOR_HPP

#include <ft_containers.hpp>

namespace ft {
	template < class T, class Alloc = std::allocator<T> >\
	class vector
	{
	public:
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef typename ft::iterator<random_access_iterator_tag, T>::value_type iterator;
		typedef typename const ft::iterator<random_access_iterator_tag, T>::value_type const_iterator;
//		typedef typename ft::iterator<random_access_iterator_tag, T>::const_value_type const_iterator;
		typedef ptrdiff_t difference_type;
		typedef size_t size_type;
	private:
		size_type _size;
		size_type _capacity;
		iterator _it;
	public:
		explicit vector(const allocator_type& alloc = allocator_type())
		{

		}

		explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		{

		}

		template <class InputIterator> \
		vector (InputIterator firsts, InputIterator last, const allocator_type& alloc = allocator_type())
		{

		}

		vector(const vector& x)
		{

		}

		~vector()
		{

		}

		vector&operator= (const vector& x)
		{

		}

		iterator begin()
		{

		}

		const_iterator begin()
		{

		}
	};
}

#endif //FT_COTAINERS_VECTOR_HPP

/*
 * ft::Vector<int> my_vec;
 * int*
 */