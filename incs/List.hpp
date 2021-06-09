#ifndef FT_COTAINERS_LIST_HPP
#define FT_COTAINERS_LIST_HPP

#include <functional>
#include <ft_containers.hpp>
#include <iterator.hpp>

namespace ft
{
	struct ListBaseNode
	{
	public:
		typedef ListBaseNode base_type;
		typedef const ListBaseNode const_base_type;

	public:
		ListBaseNode *next;
		ListBaseNode *prev;

	public:
		ListBaseNode(void) : next(this), prev(this) { }
		void connect(base_type *to)
		{
			next = to;
			prev = to->prev;

			to->prev->next = this;
			to->prev = this;
		}
		base_type* disconnect(void)
		{
			base_type *node = next;

			prev->next = node;
			node->prev = prev;

			return (this);
		}
		void transfer(base_type *first, base_type *last)
		{
			if (this != last)
			{
				last->prev->next = this;
				first->prev->next = last;
				this->prev->next = first;

				base_type *tmp = this->prev;
				this->prev = last->prev;
				last->prev = first->prev;
				first->prev = tmp;
			}
		}
		void reverse()
		{
			ListBaseNode *node = this;

			do
			{
				ft::swap(node->next, node->prev);

				node = node->prev; /* was `next` before the swap */
			}
			while (node != this);
		}
		static void swap(base_type &x, base_type &y)
		{
			if (x.next != &x)
			{
				if (y.next != &y)
				{
					ft::swap(x.next, y.next);
					ft::swap(x.prev, y.prev);
					x.next->prev = x.prev->next = &x;
					y.next->prev = y.prev->next = &y;
				}
				else
				{
					y.next = x.next;
					y.prev = x.prev;
					y.next->prev = y.prev->next = &y;
					x.next = x.prev = &x;
				}
			}
			else if (y.next != &y)
			{
				x.next = y.next;
				x.prev = y.prev;
				x.next->prev = x.prev->next = &x;
				y.next = y.prev = &y;
			}
		}
	};

	template<typename T>
	struct ListNode :
			public ListBaseNode
	{
	public:
		typedef ListNode<T> node_type;
		typedef const ListNode<T> const_node_type;

	public:
		T value;

	public:
		ListNode(const T &value) :
				value(value)
		{
		}
	};

	template<class T>
	class ListIterator;

	template<class T>
	class ListConstIterator;

	template<class T>
	class ListIterator
	{
	public:
		typedef ft::bidirectional_iterator_tag iterator_category;
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef T *pointer;
		typedef T &reference;

	private:
		typedef ListIterator<T> iterator_type;
		typedef ListBaseNode base_node_type;
		typedef ListNode<T> node_type;

	private:
		base_node_type *m_node;

	public:
		ListIterator() :
				m_node(NULL)
		{
		}

		explicit
		ListIterator(base_node_type *node) :
				m_node(node)
		{
		}

		template<typename U>
		ListIterator(const ListIterator<U> &other) :
				m_node(other.base_node())
		{
		}

		iterator_type&
		operator++()
		{
			m_node = m_node->next;

			return (*this);
		}

		iterator_type
		operator++(int)
		{
			iterator_type copy = *this;

			m_node = m_node->next;

			return (copy);
		}

		iterator_type&
		operator--()
		{
			m_node = m_node->prev;

			return (*this);
		}

		iterator_type
		operator--(int)
		{
			iterator_type copy = *this;

			m_node = m_node->prev;

			return (copy);
		}

		reference
		operator*() const
		{
			return (node()->value);
		}

		pointer
		operator->() const
		{
			return (&node()->value);
		}

		base_node_type*
		base_node()
		{
			return (m_node);
		}

		node_type*
		node()
		{
			return (static_cast<node_type*>(m_node));
		}

		base_node_type*
		base_node() const
		{
			return (m_node);
		}

		node_type*
		node() const
		{
			return (static_cast<node_type*>(m_node));
		}

		template<typename U>
		friend bool
		operator==(const ListIterator<U> &x, const ListIterator<U> &y);

		template<typename U>
		friend bool
		operator!=(const ListIterator<U> &x, const ListIterator<U> &y);

		template<typename U>
		friend bool
		operator==(const ListConstIterator<U> &x, const ListIterator<U> &y);

		template<typename U>
		friend bool
		operator!=(const ListConstIterator<U> &x, const ListIterator<U> &y);

		template<typename U>
		friend bool
		operator==(const ListIterator<U> &x, const ListConstIterator<U> &y);

		template<typename U>
		friend bool
		operator!=(const ListIterator<U> &x, const ListConstIterator<U> &y);
	};

	template<typename T>
	bool
	operator==(const ListIterator<T> &x, const ListIterator<T> &y)
	{
		return (x.m_node == y.m_node);
	}

	template<typename T>
	bool
	operator!=(const ListIterator<T> &x, const ListIterator<T> &y)
	{
		return (x.m_node != y.m_node);
	}

	template<class T>
	class ListConstIterator
	{
	public:
		typedef ft::bidirectional_iterator_tag iterator_category;
		typedef const T value_type;
		typedef ptrdiff_t difference_type;
		typedef const T *pointer;
		typedef const T &reference;

	private:
		typedef ListIterator<T> iterator_type;
		typedef ListConstIterator<T> const_iterator_type;
		typedef ListBaseNode base_node_type;
		typedef ListNode<T> node_type;
		typedef const ListBaseNode const_base_node_type;
		typedef const ListNode<T> const_node_type;

	private:
		const_base_node_type *m_node;

	public:
		ListConstIterator() :
				m_node(NULL)
		{
		}

		explicit
		ListConstIterator(const_base_node_type *node) :
				m_node(node)
		{
		}

		ListConstIterator(const iterator_type &it) :
				m_node(it.base_node())
		{
		}

		template<typename U>
		ListConstIterator(const ListIterator<U> &other) :
				m_node(other.base_node())
		{
		}

		template<typename U>
		ListConstIterator(const ListConstIterator<U> &other) :
				m_node(other.base_node())
		{
		}

		const_iterator_type&
		operator++()
		{
			m_node = m_node->next;

			return (*this);
		}

		const_iterator_type
		operator++(int)
		{
			const_iterator_type copy = *this;

			m_node = m_node->next;

			return (copy);
		}

		const_iterator_type&
		operator--()
		{
			m_node = m_node->prev;

			return (*this);
		}

		const_iterator_type
		operator--(int)
		{
			const_iterator_type copy = *this;

			m_node = m_node->prev;

			return (copy);
		}

		reference
		operator*() const
		{
			return (node()->value);
		}

		pointer
		operator->() const
		{
			return (&node()->value);
		}

		const_base_node_type*
		base_node()
		{
			return (m_node);
		}

		const_node_type*
		node()
		{
			return (static_cast<const_node_type*>(m_node));
		}

		const_base_node_type*
		base_node() const
		{
			return (m_node);
		}

		const_node_type*
		node() const
		{
			return (static_cast<const_node_type*>(m_node));
		}

		template<typename U>
		friend bool
		operator==(const ListConstIterator<U> &x, const ListConstIterator<U> &y);

		template<typename U>
		friend bool
		operator!=(const ListConstIterator<U> &x, const ListConstIterator<U> &y);

		template<typename U>
		friend bool
		operator==(const ListConstIterator<U> &x, const ListIterator<U> &y);

		template<typename U>
		friend bool
		operator!=(const ListConstIterator<U> &x, const ListIterator<U> &y);

		template<typename U>
		friend bool
		operator==(const ListIterator<U> &x, const ListConstIterator<U> &y);

		template<typename U>
		friend bool
		operator!=(const ListIterator<U> &x, const ListConstIterator<U> &y);
	};

	template<typename T>
	bool
	operator==(const ListConstIterator<T> &x, const ListConstIterator<T> &y)
	{
		return (x.m_node == y.m_node);
	}

	template<typename T>
	bool
	operator!=(const ListConstIterator<T> &x, const ListConstIterator<T> &y)
	{
		return (x.m_node != y.m_node);
	}

	template<typename T>
	bool
	operator==(const ListIterator<T> &x, const ListConstIterator<T> &y)
	{
		return (x.m_node == y.m_node);
	}

	template<typename T>
	bool
	operator!=(const ListIterator<T> &x, const ListConstIterator<T> &y)
	{
		return (x.m_node != y.m_node);
	}

	template<typename T>
	bool
	operator==(const ListConstIterator<T> &x, const ListIterator<T> &y)
	{
		return (x.m_node == y.m_node);
	}

	template<typename T>
	bool
	operator!=(const ListConstIterator<T> &x, const ListIterator<T> &y)
	{
		return (x.m_node != y.m_node);
	}

	template<class T, class Alloc = std::allocator<T> >
	class list
	{
	public:
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef typename ft::ListIterator<T> iterator;
		typedef typename ft::ListConstIterator<T> const_iterator;
		typedef typename ft::reverse_iterator<iterator> reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef ptrdiff_t difference_type;
		typedef size_t size_type;
	private:
		typedef ListBaseNode base_node_type;
		typedef ListNode<value_type> node_type;
		typedef base_node_type::const_base_type const_base_node_type;
		typedef typename node_type::const_node_type const_node_type;

		typedef typename Alloc::template rebind<node_type>::other node_allocator_type;

	private:
		node_allocator_type m_allocator;
		node_allocator_type m_node_allocator;
		ListBaseNode m_base;

	public:
		explicit
		list(const allocator_type &alloc = allocator_type()) :
				m_allocator(alloc)
		{
		}

		explicit list(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type() )
		: m_allocator(alloc)
		{
			for (; n > 0; --n)
				push_back(val);
		}
		template<class InputIterator>
		list(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(), \
		typename enable_if<!is_integral<InputIterator>::value>::type* = NULL)
		: m_allocator(alloc) { assign(first, last); }
		list(const list &x) { assign(x.begin(), x.end()); }
		~list() { clear(); }
		list & operator=(const list &x)
		{
			if (this != &x)
				assign(x.begin(), x.end());

			return (*this);
		}
		iterator begin() { return (iterator(m_base.next)); }
		const_iterator begin() const { return (const_iterator(m_base.next)); }
		iterator end() { return (iterator(&m_base)); }
		const_iterator end() const { return (const_iterator(&m_base)); }
		reverse_iterator rbegin() { return (reverse_iterator(end())); }
		const_reverse_iterator rbegin() const { return (const_reverse_iterator(end())); }
		reverse_iterator rend() { return (reverse_iterator(begin())); }
		const_reverse_iterator rend() const { return (const_reverse_iterator(end())); }
		bool empty() const { return (m_base.next == &m_base); }
		size_type size() const { return (ft::distance(begin(), end())); }
		size_type max_size() const { return (m_allocator.max_size()); }
		reference front() { return (*begin()); }
		const_reference front() const { return (*begin()); }
		reference back() { return (*(--end())); }
		const_reference back() const { return (*(--end())); }
		template<class InputIterator>
		void assign(InputIterator first, InputIterator last)
		{
			list l;

			while (first != last)
				l.push_back(*first++);

			swap(l);
		}
		void assign(size_type n, const value_type &val)
		{
			list l;

			while (n--)
				l.push_back(val);

			swap(l);
		}
		void push_front(const value_type &val) { create_node(val)->connect(m_base.next); }
		void pop_front(void) { erase(begin()); }
		void push_back(const value_type &val) { create_node(val)->connect(&m_base); }
		void pop_back(void) { erase(--end()); }
		iterator insert(iterator position, const value_type &val)
		{
			insert(position, 1, val);

			return (iterator(position.node()->next));
		}
		void insert(iterator position, size_type n, const value_type &val)
		{
			list lst(n, val, m_allocator);

			splice(position, lst);
		}
		template<class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last)
		{
			list lst(first, last, m_allocator);

			splice(position, lst);
		}
		iterator erase(iterator position)
		{
			base_node_type *node = position.base_node();
			base_node_type *next = node->next;

			destroy_node(node);

			return (iterator(next));
		}
		iterator erase(iterator first, iterator last)
		{
			iterator it = iterator(first);

			while (it != last)
			{
				base_node_type *node = it.base_node();
				it++;

				destroy_node(node);
			}

			return (iterator(last));
		}
		void swap(list &x) { ListBaseNode::swap(m_base, x.m_base); }
		void resize(size_type n, value_type val = value_type())
		{
			size_type len = size();

			if (n < len)
				erase(ft::next(begin(), n), end());
			else if (n > size())
				insert(end(), n - len, val);
		}
		void clear() { erase(begin(), end()); }
		void splice(iterator position, list &x)
		{
			if (!x.empty())
				position.node()->transfer(x.begin().node(), x.end().node());
		}
		void splice(iterator position, list &x, iterator i)
		{
			iterator next = i;
			++next;

			if (i != next)
				position.node()->transfer(i.node(), ft::next(i).node());

			(void)x;
		}
		void splice(iterator position, list &x, iterator first, iterator last)
		{
			if (first != last)
				position.node()->transfer(first.node(), last.node());

			(void)x;
		}
		void remove(const value_type &val)
		{
			iterator it = this->begin();
			iterator end = this->end();
			iterator input = end;

			if (it == end)
				return;

			while (it != end)
			{
				if (*it == val)
				{
					if (&val == &*it)
						input = it++;
					else
						it = erase(it);
				} else
					it++;
			}

			if (input != end)
				erase(input);
		}
		template<class Predicate> void remove_if(Predicate pred)
		{
			iterator it = this->begin();
			iterator end = this->end();

			if (it == end)
				return;

			while (it != end)
			{
				if (pred(*it))
					it = erase(it);
				else
					it++;
			}
		}
		void unique() { unique(ft::equal_to<value_type>()); }
		template<class BinaryPredicate>
		void unique(BinaryPredicate binary_pred)
		{
			iterator it = this->begin();
			iterator end = this->end();

			if (it == end || ++it == end)
				return;

			while (it != end)
			{
				iterator prev = it;
				--prev;

				if (binary_pred(*it, *prev))
					it = erase(it);
				else
					it++;
			}
		}
		void sort() { sort(ft::less<value_type>()); }
		template<class Compare>
		void sort(Compare comp)
		{
			bool swapped;
			base_node_type *current;
			base_node_type *last = &m_base;

			do
			{
				swapped = 0;
				current = begin().node();

				while (current->next != last)
				{
					if (comp(cast(current->next)->value, cast(current)->value))
					{
						ListBaseNode &x = *current;
						ListBaseNode &y = *current->next;

						x.next = y.next;
						y.prev = x.prev;
						x.next->prev = &x;
						y.prev->next = &y;
						y.next = &x;
						x.prev = &y;

						swapped = true;
					} else
						current = current->next;
				}

				last = current;
			} while (swapped);
		}
		void merge(list &x) { merge(x, std::less<value_type>()); }
		template<class Compare>
		void
		merge(list &x, Compare comp)
		{
			if (this == &x || x.empty())
				return;

			iterator first1 = begin();
			iterator last1 = end();
			iterator first2 = x.begin();
			iterator last2 = x.end();

			while (first1 != last1 && first2 != last2)
			{
				if (comp(*first2, *first1))
				{
					iterator next = first2;
					first1.node()->transfer(first2.node(), (++next).node());
					first2 = next;
				} else
					++first1;
			}

			if (first2 != last2)
				last1.node()->transfer(first2.node(), last2.node());
		}
		void reverse() { m_base.reverse(); }
	private:
		node_type * cast(base_node_type *base) { return (static_cast<node_type *>(base)); }
		node_type * create_node(const_reference val)
		{
			node_type *node = m_node_allocator.allocate(1);
			new(node) node_type(val);

			return (node);
		}
		void destroy_node(base_node_type *base)
		{
			node_type *node = cast(base);

			node->disconnect();
			node->~node_type();

			m_node_allocator.deallocate(node, 1);
		}
	};
	template<class T, class Alloc>
	bool operator==(const list <T, Alloc> &lhs, const list <T, Alloc> &rhs)
	{
		return (lhs.size() == rhs.size() && equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template<class T, class Alloc>
	bool operator!=(const list <T, Alloc> &lhs, const list <T, Alloc> &rhs)
	{
		return (!(lhs == rhs));
	}

	template<class T, class Alloc>
	bool operator<(const list <T, Alloc> &lhs, const list <T, Alloc> &rhs)
	{
		return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template<class T, class Alloc>
	bool operator<=(const list <T, Alloc> &lhs, const list <T, Alloc> &rhs)
	{
		return (!(rhs < lhs));
	}

	template<class T, class Alloc>
	bool operator>(const list <T, Alloc> &lhs, const list <T, Alloc> &rhs)
	{
		return (rhs < lhs);
	}

	template<class T, class Alloc>
	bool operator>=(const list <T, Alloc> &lhs, const list <T, Alloc> &rhs)
	{
		return (!(lhs < rhs));
	}

	template<class T, class Alloc>
	void swap(list <T, Alloc> &x, list <T, Alloc> &y)
	{
		x.swap(y);
	}
}
#endif