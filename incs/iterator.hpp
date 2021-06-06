#ifndef FT_COTAINERS_ITERATOR_HPP
#define FT_COTAINERS_ITERATOR_HPP

#include <ft_containers.hpp>

struct iterator;

namespace ft {
	struct input_iterator_tag {

	};

	/*
	 * value type이 있어야 할거 같은데??
	 * class T 가 아니라 int 픽스하면 안되낭
	 */
	template <typename T> \
	struct bidirectional_iterator_tag {
	public:
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
	protected:
		pointer p;
	public:
		bidirectional_iterator_tag() {}
//		bidirectional_iterator_tag(pointer x) : p(x) {}
		bidirectional_iterator_tag(const bidirectional_iterator_tag& bit) : p(bit.p) {}
		bidirectional_iterator_tag& operator=(const bidirectional_iterator_tag& obj){
			p = obj.p;
		}
		/*
		 * 전위 증감 연산자
		 */
		bidirectional_iterator_tag& operator++() {
			++p;
			return *this;
		}
		/*
		 * 후위 증감 연산자
		 */
		bidirectional_iterator_tag operator++(int) {
			bidirectional_iterator_tag tmp(*this);
			operator++();
			return tmp;
		}
		bool operator==(const bidirectional_iterator_tag& rhs) const { return p == rhs.p; }
		bool operator!=(const bidirectional_iterator_tag& rhs) const { return p != rhs.p; }
		value_type& operator*() {return *p;}
	};

	struct random_access_iterator_tag : bidirectional_iterator_tag<class T> {
	};

	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct iterator {
	public:
		typedef T           value_type;
		typedef Distance    difference_type;
		typedef Pointer     pointer;
		typedef Reference   reference;
		typedef Category    iterator_category;

	};

	template <class Iterator>
	class reverse_iterator
	{
		typedef Iterator iterator_type;
	};
}

#endif //FT_COTAINERS_ITERATOR_HPP
