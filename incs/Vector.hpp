#ifndef FT_COTAINERS_VECTOR_HPP
#define FT_COTAINERS_VECTOR_HPP

#include <ft_containers.hpp>

namespace ft {
	template <class T>
	class vector_iterator {
	public:
		typedef T           value_type;
		typedef T*          pointer;
		typedef T&          reference;
	private:
		T* _p;
	public:
		vector_iterator() {}
		vector_iterator(pointer x) : _p(x) {}
		vector_iterator(const vector_iterator& bit) : _p(bit._p) {}
		vector_iterator& operator=(const vector_iterator& obj){
			_p = obj._p;
			return *this;
		}
		vector_iterator& operator++()
		{
			++_p;
			return *this;
		}
		vector_iterator operator++(int)
		{
			vector_iterator tmp(*this);
			operator++();
			return tmp;
		}
		vector_iterator& operator--()
		{
			--_p;
			return *this;
		}
		vector_iterator operator--(int)
		{
			vector_iterator tmp(*this);
			operator--();
			return tmp;
		}
		vector_iterator operator+(int n) const
		{
			vector_iterator tmp(*this);
			tmp += n;
			return (tmp);
		}
		vector_iterator operator-(int n) const
		{
			vector_iterator tmp(*this);
			tmp -= n;
			return (tmp);
		}
		vector_iterator &operator+=(int n)
		{
			*this += n;
			return (*this);
		};
		vector_iterator &operator-=(int n)
		{
			*this -= n;
			return (*this);
		};
		reference operator*() { return *_p; }
		pointer operator->() { return _p; }
		bool operator==(const vector_iterator& rhs) const { return _p == rhs._p; }
		bool operator!=(const vector_iterator& rhs) const { return _p != rhs._p; }
		bool operator>(const vector_iterator& rhs) const { return _p > rhs._p; }
		bool operator>=(const vector_iterator& rhs) const { return _p >= rhs._p; }
		bool operator<(const vector_iterator& rhs) const { return _p < rhs._p; }
		bool operator<=(const vector_iterator& rhs) const { return _p <= rhs._p; }
		value_type &operator[] (int n) const { return (*(*this + n)); }
		pointer base() const { return _p; }
	};

	template <class T>
	class reverse_vector_iterator {
	public:
		typedef T           value_type;
		typedef T*          pointer;
		typedef T&          reference;
	private:
		T* _p;
	public:
		reverse_vector_iterator() {}
		reverse_vector_iterator(pointer x) : _p(x) {}
		reverse_vector_iterator(const reverse_vector_iterator& bit) : _p(bit._p) {}
		reverse_vector_iterator& operator=(const reverse_vector_iterator& obj){
			_p = obj._p;
			return *this;
		}
		reverse_vector_iterator& operator++()
		{
			--_p;
			return *this;
		}
		reverse_vector_iterator operator++(int)
		{
			reverse_vector_iterator tmp(*this);
			operator--();
			return tmp;
		}
		reverse_vector_iterator& operator--()
		{
			++_p;
			return *this;
		}
		reverse_vector_iterator operator--(int)
		{
			reverse_vector_iterator tmp(*this);
			operator++();
			return tmp;
		}
		reverse_vector_iterator operator+(int n) const
		{
			reverse_vector_iterator tmp(*this);
			tmp -= n;
			return (tmp);
		}
		reverse_vector_iterator operator-(int n) const
		{
			reverse_vector_iterator tmp(*this);
			tmp += n;
			return (tmp);
		}
		reverse_vector_iterator &operator+=(int n)
		{
			*this -= n;
			return (*this);
		};
		reverse_vector_iterator &operator-=(int n)
		{
			*this += n;
			return (*this);
		};
		reference operator*() { return *_p; }
		pointer operator->() { return _p; }
		bool operator==(const reverse_vector_iterator& rhs) const { return _p == rhs._p; }
		bool operator!=(const reverse_vector_iterator& rhs) const { return _p != rhs._p; }
		bool operator>(const reverse_vector_iterator& rhs) const { return _p > rhs._p; }
		bool operator>=(const reverse_vector_iterator& rhs) const { return _p >= rhs._p; }
		bool operator<(const reverse_vector_iterator& rhs) const { return _p < rhs._p; }
		bool operator<=(const reverse_vector_iterator& rhs) const { return _p <= rhs._p; }
		value_type &operator[] (int n) const { return (*(*this -= n)); }
		pointer base() const { return _p; }
	};

	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
	public:
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef typename ft::vector_iterator<T> iterator;
		typedef typename ft::vector_iterator<const T> const_iterator;
		typedef typename ft::reverse_vector_iterator<T> reverse_iterator;
		typedef typename ft::reverse_vector_iterator<const T> const_reverse_iterator;
		typedef ptrdiff_t difference_type;
		typedef size_t size_type;

	private:
		size_type _size;
		size_type _capacity;
		allocator_type _allocator;
		pointer _p;

		pointer createVector(const_reference val) {
			pointer p = _allocator.allocate(_capacity);
			for (size_type i = 0; i < _size; i++)
				_allocator.construct(p + i, val);
			return (p);
		}

	public:
		explicit vector(const allocator_type& alloc = allocator_type())
		: _size(0), _capacity(0), _allocator(alloc), _p(0) { }
		explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		: _size(n), _capacity(_size), _allocator(alloc) { _p = createVector(val); }
//		template <class InputIterator>
//		vector (InputIterator firsts, InputIterator last, const allocator_type& alloc = allocator_type()) \
//		: _size(0), _capacity(0), _allocator(alloc), _p(0)
//		{
//			for (; firsts != last; ++firsts)
//				push_back(*firsts);
//		}
		vector(const vector& x) : _size(x._size), _capacity(x._capacity), _allocator(x._allocator), _p(x._p) { }

//		~vector()
//		{
//
//		}
//
//		vector&operator= (const vector& x)
//		{
//

//		}
//		value_type& operator*()
//		{
//			return (*_p);
//		}
//		bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
//		bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
//		bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
//		bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
//		bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
//		bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

		iterator begin() {
			return (iterator(_p));
		}
//
//		const_iterator begin()
//		{
//			return (const_iterator(_p));
//		}
	};
}

#endif //FT_COTAINERS_VECTOR_HPP

/*
 * ft::Vector<int> my_vec;
 * int*
 */