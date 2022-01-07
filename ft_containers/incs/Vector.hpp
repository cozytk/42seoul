#ifndef FT_COTAINERS_VECTOR_HPP
#define FT_COTAINERS_VECTOR_HPP

#include <ft_containers.hpp>
#include <iterator.hpp>

namespace ft
{
	template<class T>
	class vector_iterator :
			public ft::iterator<ft::random_access_iterator_tag, T>
	{
	private:
		typedef typename ft::iterator_traits<T> traits;

	public:
		typedef typename traits::iterator_category iterator_category;
		typedef typename traits::value_type value_type;
		typedef typename traits::difference_type difference_type;
		typedef typename traits::reference reference;
		typedef typename traits::pointer pointer;

	private:
		T _ptr;

	public:
		vector_iterator() :
				_ptr(NULL)
		{
		}

		explicit
		vector_iterator(const T &ptr) :
				_ptr(ptr)
		{
		}

		template<typename U>
		vector_iterator(const vector_iterator<U> &other) :
				_ptr(other.base())
		{
		}

		~vector_iterator()
		{
		}

		vector_iterator&
		operator=(const vector_iterator &rhs)
		{
			this->_ptr = rhs._ptr;

			return (*this);
		}

		vector_iterator&
		operator++()
		{
			this->_ptr++;

			return (*this);
		}

		vector_iterator
		operator++(int)
		{
			vector_iterator copy = *this;

			this->_ptr++;

			return (copy);
		}

		vector_iterator&
		operator--()
		{
			this->_ptr--;

			return (*this);
		}

		vector_iterator
		operator--(int)
		{
			vector_iterator copy = *this;

			this->_ptr--;

			return (copy);
		}

		vector_iterator&
		operator+=(difference_type n)
		{
			this->_ptr += n;

			return (*this);
		}

		vector_iterator
		operator+(difference_type n) const
		{
			return (vector_iterator(this->_ptr + n));
		}

		vector_iterator&
		operator-=(difference_type n)
		{
			this->_ptr -= n;

			return (*this);
		}

		vector_iterator
		operator-(difference_type n) const
		{
			return (vector_iterator(this->_ptr - n));
		}

		difference_type
		operator-(const vector_iterator &other)
		{
			return (this->_ptr - other.base());
		}

		reference
		operator*() const
		{
			return (*this->_ptr);
		}

		pointer
		operator->() const
		{
			return (this->_ptr);
		}

		reference
		operator[](difference_type n) const
		{
			return (*(this->_ptr + n));
		}

		const T&
		base() const
		{
			return (_ptr);
		}
	};

	template<typename T>
	inline bool
	operator==(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template<typename T, typename U>
	inline bool
	operator==(const vector_iterator<T> &lhs, const vector_iterator<U> &rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template<typename T>
	inline bool
	operator!=(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template<typename T, typename U>
	inline bool
	operator!=(const vector_iterator<T> &lhs, const vector_iterator<U> &rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template<typename T>
	inline bool
	operator<(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template<typename T, typename U>
	inline bool
	operator<(const vector_iterator<T> &lhs, const vector_iterator<U> &rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template<typename T>
	inline bool
	operator>(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template<typename T, typename U>
	inline bool
	operator>(const vector_iterator<T> &lhs, const vector_iterator<U> &rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template<typename T>
	inline bool
	operator<=(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template<typename T, typename U>
	inline bool
	operator<=(const vector_iterator<T> &lhs, const vector_iterator<U> &rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template<typename T>
	inline bool
	operator>=(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template<typename T, typename U>
	inline bool
	operator>=(const vector_iterator<T> &lhs, const vector_iterator<U> &rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template<typename T>
	inline vector_iterator<T>
	operator+(typename vector_iterator<T>::difference_type n, const vector_iterator<T> &it)
	{
		return (vector_iterator<T>(it.base() + n));
	}

	template<typename T, typename U>
	inline typename vector_iterator<T>::difference_type
	operator-(const vector_iterator<T> &lhs, const vector_iterator<U> &rhs)
	{
		return (lhs.base() - rhs.base());
	}

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
		typedef ft::vector_iterator<pointer> iterator;
		typedef ft::vector_iterator<const_pointer> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
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

		void reallocVector(size_type range)
		{
			pointer p = _allocator.allocate(range);
			for (size_type i = 0; i < _size; ++i)
				_allocator.construct(p + i, *(_p + i));
			for (size_type i = 0; i != _size; ++i)
				_allocator.destroy(_p + i);
			if (_capacity)
				_allocator.deallocate(_p, _capacity);
			_capacity = range;
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
		vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),\
				typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = NULL)
		: _size(0), _capacity(0), _allocator(alloc), _p(0)
		{
			this->assign(first, last);
		}

		vector(const vector &x) : _size(0), _capacity(0), _allocator(x._allocator)
		{
			if (this != &x)
				assign(x.begin(), x.end());
			_capacity = _size;
		}
		~vector()
		{
			for (size_type i = 0; i != _size; i++)
				_allocator.destroy(_p + i);
			_size = 0;
			if (_capacity)
				_allocator.deallocate(_p, _capacity);
		}
		vector&operator= (const vector& x)
		{
			if (this != &x)
				assign(x.begin(), x.end());
			return (*this);
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
		{
			return (reverse_iterator(end()));
		}
		const_reverse_iterator rbegin() const
		{
			return (const_reverse_iterator(end()));
		}
		reverse_iterator rend()
		{
			return (reverse_iterator(begin()));
		}
		const_reverse_iterator rend() const
		{
			return (const_reverse_iterator(begin()));
		}

		size_type size() const
		{ return (this->_size); }

		size_type max_size() const
		{ return (std::numeric_limits<size_type>::max() / sizeof(_p[0])); }

		void resize (size_type n, value_type val = value_type())
		{
			if (n < size())
				erase(begin() + n, end());
			else if (n > size())
				insert(end(), n - size(), val);
		}

		size_type capacity() const { return (this->_capacity); }
		bool empty() const { return !_size; }
		void reserve(size_type n)
		{
			if (n > this->_capacity)
			{
				if (n > this->_size * 2)
					this->reallocVector(n);
				else
					this->reallocVector(this->_size * 2);
			}
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
		reference front() { return (*_p); }
		const_reference front() const { return (*_p); }
		reference back() { return (*(_p + this->_size - 1)); }
		const_reference back() const { return (*(_p + this->_size - 1)); }
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = NULL)
		{
			clear();
			insert(begin(), first, last);
		}
		void assign(size_type n, const value_type& val)
		{
			clear();
			insert(begin(), n, val);
		}
		void push_back(const value_type& val)
		{
			if (_size + 1 > _capacity)
				reserve(_size + 1);
			_p[_size] = val;
			_size += 1;
		}
		void pop_back(void)
		{
			if (!empty())
				_allocator.destroy(_p + --_size);
		}
		iterator insert(iterator position, const value_type& val)
		{
			difference_type diff = position - begin();

			insert(position, 1, val);
			return (iterator(begin() + diff));
		}

		void insert(iterator position, size_type n, const value_type& val)
		{
			iterator it = begin();
			size_type i = 0;
			size_type j;

			while (it + i != position && i < _size)
				++i;
			reserve(_size + n);
			j = _size;
			_size += n;
			while (i < j--)
				_p[j + n] = _p[j];
			while (n--)
				_p[i + n] = val;
		}
		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last,\
		typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = NULL)
		{
			while (first != last)
			{
				position = insert(position, *first) + 1;
				++first;
			}
		}
		iterator erase (iterator position)
		{
			return (this->erase(position, position + 1));
		}
		iterator erase (iterator first, iterator last)
		{
			if (first != last)
			{
				iterator it = this->begin();
				size_type idx = 0;
				difference_type n = last - first;

				while (it + idx != first)
					idx++;
				while (it + idx != end() - n)
				{
					_p[idx] = _p[idx + n];
					idx++;
				}
				while (it + idx != end())
					this->_allocator.destroy(_p + idx++);
				this->_size -= n;
			}
			return (iterator(first));
		}
		void swap(vector& x)
		{
			if (this != &x)
			{
				ft::swap(this->_p, x._p);
				ft::swap(this->_size, x._size);
				ft::swap(this->_capacity, x._capacity);
				ft::swap(this->_allocator, x._allocator);
			}
		}
		void clear()
		{
			erase(this->begin(), this->end());
			this->_size = 0;
		}

	};

	template<class T, class Alloc>
	bool
	operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (lhs.size() == rhs.size() && equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template<class T, class Alloc>
	bool
	operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (!(lhs == rhs));
	}

	template<class T, class Alloc>
	bool
	operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template<class T, class Alloc>
	bool
	operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (!(rhs < lhs));
	}

	template<class T, class Alloc>
	bool
	operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (rhs < lhs);
	}

	template<class T, class Alloc>
	bool
	operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (!(lhs < rhs));
	}

	template<class T, class Alloc>
	void
	swap(vector<T, Alloc> &x, vector<T, Alloc> &y)
	{
		x.swap(y);
	}
}
#endif
