#ifndef FT_COTAINERS_QUEUE_HPP
#define FT_COTAINERS_QUEUE_HPP

#include <ft_containers.hpp>
#include <List.hpp>

namespace ft{
	template <class T, class Container = list<T> >
	class queue {
	public:
		typedef T value_type;
		typedef Container container_type;
		typedef size_t size_type;
	protected:
		container_type _container;
	public:
		explicit queue (const container_type& ctnr = container_type())
		:_container(ctnr)
		{ }
		bool empty() const
		{
			return (_container.empty());
		}
		size_type size() const
		{
			return (_container.size());
		}
		value_type& front()
		{
			return (_container.front());
		}
		const value_type& front() const
		{
			return (_container.front());
		}
		value_type& back()
		{
			return (_container.back());
		}
		const value_type& back() const
		{
			return (_container.back());
		}
		void push (const value_type& val)
		{
			_container.push_back(val);
		}
		void pop()
		{
			_container.pop_front();
		}
	};
	template <class T, class Container>
	bool operator== (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		size_t size = lhs.size();
		queue<T,Container> tmp1 = lhs;
		queue<T,Container> tmp2 = rhs;
		while (size--)
		{
			if (tmp1.front() != tmp2.front())
				return false;
			tmp1.pop();
			tmp2.pop();
		}
		return true;
	}
	template <class T, class Container>
	bool operator!= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{
		return (!(lhs == rhs));
	}
	template <class T, class Container>
	bool operator<  (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{
		bool longer;
		size_t size;

		if (lhs.size() < rhs.size())
		{
			longer = true;
			size = lhs.size();
		}
		else
		{
			longer = false;
			size = rhs.size();
		}
		queue<T,Container> tmp1 = lhs;
		queue<T,Container> tmp2 = rhs;
		while (size--)
		{
			if (tmp1.front() < tmp2.front())
				return true;
			tmp1.pop();
			tmp2.pop();
		}
		return (longer);
	}
	template <class T, class Container>
	bool operator<= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{
		return (lhs == rhs || lhs < rhs);
	}
	template <class T, class Container>
	bool operator>  (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{
		return (!(lhs <= rhs));
	}
	template <class T, class Container>
	bool operator>= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{
		return (!(lhs < rhs));
	}
}

#endif //FT_COTAINERS_QUEUE_HPP
