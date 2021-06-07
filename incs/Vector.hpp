#ifndef FT_COTAINERS_VECTOR_HPP
#define FT_COTAINERS_VECTOR_HPP

#include <ft_containers.hpp>

namespace ft
{
	template<class T>
	class vector_iterator
	{
	public:
		typedef T value_type;
		typedef T *pointer;
		typedef T &reference;
	private:
		T *_p;
	public:
		vector_iterator()
		{}

		vector_iterator(pointer x) : _p(x)
		{}

		vector_iterator(const vector_iterator &bit) : _p(bit._p)
		{}

		vector_iterator &operator=(const vector_iterator &obj)
		{
			_p = obj._p;
			return *this;
		}

		vector_iterator &operator++()
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

		vector_iterator &operator--()
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
			while (n < 0)
			{
				(*this)--;
				n++;
			}
			while (n > 0)
			{
				(*this)++;
				n--;
			}
			return (*this);
		};

		vector_iterator &operator-=(int n)
		{
			while (n < 0)
			{
				(*this)--;
				n++;
			}
			while (n > 0)
			{
				(*this)++;
				n--;
			}
			return (*this);
		};

		reference operator*()
		{ return *_p; }

		pointer operator->()
		{ return _p; }

		bool operator==(const vector_iterator &rhs) const
		{ return _p == rhs._p; }

		bool operator!=(const vector_iterator &rhs) const
		{ return _p != rhs._p; }

		bool operator>(const vector_iterator &rhs) const
		{ return _p > rhs._p; }

		bool operator>=(const vector_iterator &rhs) const
		{ return _p >= rhs._p; }

		bool operator<(const vector_iterator &rhs) const
		{ return _p < rhs._p; }

		bool operator<=(const vector_iterator &rhs) const
		{ return _p <= rhs._p; }

		value_type &operator[](int n) const
		{ return (*(*this + n)); }

		pointer base() const
		{ return _p; }
	};

	template<class T>
	class reverse_vector_iterator
	{
	public:
		typedef T value_type;
		typedef T *pointer;
		typedef T &reference;
	private:
		T *_p;
	public:
		reverse_vector_iterator()
		{}

		reverse_vector_iterator(pointer x) : _p(x)
		{}

		reverse_vector_iterator(const reverse_vector_iterator &bit) : _p(bit._p)
		{}

		reverse_vector_iterator &operator=(const reverse_vector_iterator &obj)
		{
			_p = obj._p;
			return *this;
		}

		reverse_vector_iterator &operator++()
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

		reverse_vector_iterator &operator--()
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

		reference operator*()
		{ return *_p; }

		pointer operator->()
		{ return _p; }

		bool operator==(const reverse_vector_iterator &rhs) const
		{ return _p == rhs._p; }

		bool operator!=(const reverse_vector_iterator &rhs) const
		{ return _p != rhs._p; }

		bool operator>(const reverse_vector_iterator &rhs) const
		{ return _p > rhs._p; }

		bool operator>=(const reverse_vector_iterator &rhs) const
		{ return _p >= rhs._p; }

		bool operator<(const reverse_vector_iterator &rhs) const
		{ return _p < rhs._p; }

		bool operator<=(const reverse_vector_iterator &rhs) const
		{ return _p <= rhs._p; }

		value_type &operator[](int n) const
		{ return (*(*this -= n)); }

		pointer base() const
		{ return _p; }
	};

	template<class T, class Alloc = std::allocator<T> >
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

		pointer createVector(const_reference val)
		{
			pointer p = _allocator.allocate(_capacity);
			for (size_type i = 0; i < _size; i++)
				_allocator.construct(p + i, val);
			return (p);
		}

		/*
		 * should be ++i?
		 */
		void reallocVector(size_type range = 0)
		{
			pointer p = _allocator.allocate((_size + range) * 2);
			for (size_type i = 0; i < _size; i++)
				_allocator.construct(p + i, *(_p + i));
			for (size_type i = 0; i != _size; i++)
				_allocator.destroy(_p + i);
			if (_capacity)
				_allocator.dellocate(_p, _capacity);
			_capacity = (_size + range) * 2;
			_p = p;
		}

	public:
		explicit vector(const allocator_type &alloc = allocator_type())
				: _size(0), _capacity(0), _allocator(alloc), _p(0)
		{}

		explicit vector(size_type n, const value_type &val = value_type(),
		                const allocator_type &alloc = allocator_type())
				: _size(n), _capacity(_size), _allocator(alloc)
		{ _p = createVector(val); }

		template <class InputIterator>
		vector (InputIterator firsts, InputIterator last, const allocator_type& alloc = allocator_type(),\
				typename ft::enable_if<ft::is_input_iter<InputIterator>::value>::type tmp = 0)
		: _size(0), _capacity(0), _allocator(alloc), _p(0)
		{
			(void)tmp;
			for (; firsts != last; ++firsts)
				push_back(*firsts);
		}
		vector(const vector &x) : _size(x._size), _capacity(x._capacity), _allocator(x._allocator)
		{
			_p = _allocator.allocate(_size);
			for (size_type i = 0; i < _size; i++)
				_allocator.construct(_p + i, *(_p + i));
		}

		~vector()
		{
			for (size_type i = 0; i != _size; i++)
				_allocator.destroy(_p + i);
			if (_capacity)
				_allocator.deallocate(_p, _capacity);
		}

		vector&operator= (const vector& x)
		{
			if (_capacity)
				_allocator.deallocate(_p, _capacity);
			_allocator = x._allocator;
			_size = x._size;
			_capacity = x._capacity;
		}

		iterator begin()
		{ return (iterator(_p)); }

		const_iterator begin() const
		{ return (const_iterator(_p)); }

		iterator end()
		{ return (iterator(_p + _size)); }

		const_iterator end() const
		{ return (const_iterator(_p + _size)); }

		reverse_iterator rbegin()
		{ return (reverse_iteraotr(_p + _size - 1)); }

		const_reverse_iterator rbegin() const
		{ return (reverse_iteraotr(_p + _size - 1)); }

		reverse_iterator rend()
		{ return (const_reverse_iteraotr(_p - 1)); }

		const_reverse_iterator rend() const
		{ return (const_reverse_iteraotr(_p - 1)); }

		size_type size() const
		{ return (this->_size); }

		size_type max_size() const
		{ return (std::numeric_limits<size_type>::max() / sizeof(_p[0])); }

		void resize (size_type n, value_type val = value_type())
		{
			if (n < this->_size)
				pop_back();
			else if (n > this->_size)
				push_back(val);
		}

		size_type capacity() const { return (this->_capacity); }
		bool empty() const { return !_size; }
		void reserve(size_type n)
		{
			if (n > this->_capacity)
				this->reallocVector(n);
		}
		reference operator[] (size_type n) { return (_p[n]); }
		const_reference operator[] (size_type n) const { return (_p[n]); }
		reference at (size_type n)
		{
			if (n >= _size)
				throw std::out_of_range("Invaild index access");
			return _p[n];
		}
		const_reference at (size_type n) const
		{
			if (n >= _size)
				throw std::out_of_range("Invaild index access");
			return _p[n];
		}
		reference front() { return (_p[0]); }
		const_reference front() const { return (_p[0]); }
		reference back() { return (_p[this->size - 1]); }
		const_reference back() const { return (_p[this->size - 1]); }
		template <class InputIterator>
//		void assign(InputIterator first, InputIterator last, typename ft::enable_if<ft::is_input_iter<InputIterator>::value>::type tmp = 0)
//		{
//			(void)tmp;
//		}
//		void assign(size_type n, const value_type& val)
//		{
//		}
		void push_back(const value_type& val)
		{
			if (_size + 1 > _capacity)
				reserve(_size + 1);
			_size += 1;
			_p[_size] = val;
		}
		void pop_back(void)
		{
			if (!empty())
				_allocator.destroy(_p + --_size);
		}
		iterator insert(iterator position, const value_type& val)
		{
			size_type = 0;
			iterator it = begin();

		}
		void insert(iterator postion, size_type n, const value_type& val){ return;}
		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last,\
		typename ft::enable_if<ft::is_input_iter<InputIterator>::value>::type tmp = 0)
		{
			(void)tmp;
		}
	};
}


//		bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
//		bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
//		bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
//		bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
//		bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
//		bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

#endif //FT_COTAINERS_VECTOR_HPP

/*
 * ft::Vector<int> my_vec;
 * int*
 */