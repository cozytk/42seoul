#ifndef FT_COTAINERS_STACK_HPP
#define FT_COTAINERS_STACK_HPP

#include <List.hpp>

namespace ft {
	template <class T, class Container = list<T> >
	class stack
	{
	public:
		typedef T value_type;
		typedef Container container_type;
		typedef size_t size_type;
	private:
		container_type _container;
	public:
		explicit stack (const container_type& ctnr = container_type())
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
		value_type& top()
		{
			return (_container.back());
		}
		const value_type& top() const
		{
			return (_container.back());
		}
		void push (const value_type& val)
		{
			return (_container.push_back(val));
		}
		void pop ()
		{
			return (_container.pop_back());
		}
		container_type getContainer() const
		{
			return (_container);
		}
	};
	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		size_t size = lhs.size();
		stack<T,Container> tmp1 = lhs;
		stack<T,Container> tmp2 = rhs;
		while (size--)
		{
			if (tmp1.top() != tmp2.top())
				return false;
			tmp1.pop();
			tmp2.pop();
		}
		return true;
	}
	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (!(lhs == rhs));
	}
	template <class T, class Container>
	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
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
		stack<T,Container> tmp1 = lhs;
		stack<T,Container> tmp2 = rhs;
		while (size--)
		{
			if (tmp1.top() < tmp2.top())
				return true;
			tmp1.pop();
			tmp2.pop();
		}
		return (longer);
	}
	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (!(rhs < lhs));
	}
	template <class T, class Container>
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (rhs < lhs);
	}
	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (!(lhs < rhs));
	}
}
#endif
