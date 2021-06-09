//#ifndef FT_COTAINERS_LIST_HPP
//#define FT_COTAINERS_LIST_HPP
//
//#include <ft_containers.hpp>
//
//namespace ft {
//	template <typename T>
//	class list_iterator
//	{
//	public:
//		typedef ptrdiff_t difference_type;
//		typedef T value_type;
//		typedef T *pointer;
//		typedef T &reference;
//	private:
//		T *_p;
//	public:
//		list_iterator()
//		{}
//
//		list_iterator(pointer x) : _p(x)
//		{}
//
//		list_iterator(const list_iterator &bit) : _p(bit._p)
//		{}
//
//		list_iterator &operator=(const list_iterator &obj)
//		{
//			_p = obj._p;
//			return *this;
//		}
//
//		list_iterator &operator++()
//		{
//			++_p;
//			return *this;
//		}
//
//		list_iterator operator++(int)
//		{
//			list_iterator tmp(*this);
//			operator++();
//			return tmp;
//		}
//
//		list_iterator &operator--()
//		{
//			--_p;
//			return *this;
//		}
//
//		list_iterator operator--(int)
//		{
//			list_iterator tmp(*this);
//			operator--();
//			return tmp;
//		}
//
//		reference operator*()
//		{ return *_p; }
//
//		pointer operator->()
//		{ return _p; }
//
//		bool operator==(const list_iterator &rhs) const
//		{ return _p == rhs._p; }
//
//		bool operator!=(const list_iterator &rhs) const
//		{ return _p != rhs._p; }
//
//		pointer base() const
//		{ return _p; }
//	};
//
//	template<class T>
//	class reverse_list_iterator
//	{
//	public:
//		typedef T value_type;
//		typedef T *pointer;
//		typedef T &reference;
//	private:
//		T *_p;
//	public:
//		reverse_list_iterator()
//		{}
//
//		reverse_list_iterator(pointer x) : _p(x)
//		{}
//
//		reverse_list_iterator(const reverse_list_iterator &bit) : _p(bit._p)
//		{}
//
//		reverse_list_iterator &operator=(const reverse_list_iterator &obj)
//		{
//			_p = obj._p;
//			return *this;
//		}
//
//		reverse_list_iterator &operator++()
//		{
//			--_p;
//			return *this;
//		}
//
//		reverse_list_iterator operator++(int)
//		{
//			reverse_list_iterator tmp(*this);
//			operator--();
//			return tmp;
//		}
//
//		reverse_list_iterator &operator--()
//		{
//			++_p;
//			return *this;
//		}
//
//		reverse_list_iterator operator--(int)
//		{
//			reverse_list_iterator tmp(*this);
//			operator++();
//			return tmp;
//		}
//
//		reverse_list_iterator operator+(int n) const
//		{
//			reverse_list_iterator tmp(*this);
//			tmp -= n;
//			return (tmp);
//		}
//
//		reverse_list_iterator operator-(int n) const
//		{
//			reverse_list_iterator tmp(*this);
//			tmp += n;
//			return (tmp);
//		}
//
//		reverse_list_iterator &operator+=(int n)
//		{
//			*this -= n;
//			return (*this);
//		};
//
//		reverse_list_iterator &operator-=(int n)
//		{
//			*this += n;
//			return (*this);
//		};
//
//		reference operator*()
//		{ return *_p; }
//
//		pointer operator->()
//		{ return _p; }
//
//		bool operator==(const reverse_list_iterator &rhs) const
//		{ return _p == rhs._p; }
//
//		bool operator!=(const reverse_list_iterator &rhs) const
//		{ return _p != rhs._p; }
//
//		bool operator>(const reverse_list_iterator &rhs) const
//		{ return _p > rhs._p; }
//
//		bool operator>=(const reverse_list_iterator &rhs) const
//		{ return _p >= rhs._p; }
//
//		bool operator<(const reverse_list_iterator &rhs) const
//		{ return _p < rhs._p; }
//
//		bool operator<=(const reverse_list_iterator &rhs) const
//		{ return _p <= rhs._p; }
//
//		value_type &operator[](int n) const
//		{ return (*(*this -= n)); }
//
//		pointer base() const
//		{ return _p; }
//	};
//	template < class T, class Alloc = std::allocator<T> >
//	class list
//	{
//	public:
//		typedef Alloc allocator_type;
//		typedef typename allocator_type::reference reference;
//		typedef typename allocator_type::const_reference const_reference;
//		typedef typename allocator_type::pointer pointer;
//		typedef typename allocator_type::const_pointer const_pointer;
//		typedef typename ft::normal_iterator<pointer> iterator;
//		typedef typename ft::normal_iterator<const_pointer> const_iterator;
//		typedef typename ft::reverse_iterator<iterator> reverse_iterator;
//		typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
//		typedef ptrdiff_t difference_type;
//		typedef size_t size_type;
//
//	private:
//		size_type _size;
//		size_type _capacity;
//		allocator_type _allocator;
//		pointer _p;
//	};
//}
//
//
//
//
//
//#endif //FT_COTAINERS_LIST_HPP