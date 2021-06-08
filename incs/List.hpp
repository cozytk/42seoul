#ifndef FT_COTAINERS_LIST_HPP
#define FT_COTAINERS_LIST_HPP

#include <ft_containers.hpp>
#include <iterator.hpp>

namespace ft {
	template < class T, class Alloc = std::allocator<T> >
	class list
	{
	public:
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef typename ft::normal_iterator<pointer> iterator;
		typedef typename ft::normal_iterator<const_pointer> const_iterator;
		typedef typename ft::reverse_iterator<iterator> reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef ptrdiff_t difference_type;
		typedef size_t size_type;

	private:
		size_type _size;
		size_type _capacity;
		allocator_type _allocator;
		pointer _p;
	};
}





#endif //FT_COTAINERS_LIST_HPP