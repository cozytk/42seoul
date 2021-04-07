#ifndef IDENTIFYREALTYPE_WHATEVER_H
#define IDENTIFYREALTYPE_WHATEVER_H

#include <iostream>

template <typename T>
void	swap(T &a, T &b)
{
	T	tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T const &	min(T const &a, T const &b)
{
	return (a <= b ? a : b);
}

template <typename T>
T const &	max(T const &a, T const &b)
{
	return (a >= b ? a : b);
}

class AnyType
{
	private:
		int _n;
	public:
		AnyType(int n ) : _n(n ) {}
		int getN() const { return (_n); }
		bool operator==(AnyType const & rhs ) const { return (this->_n == rhs._n); }
		bool operator!=(AnyType const & rhs ) const { return (this->_n != rhs._n); }
		bool operator>(AnyType const & rhs ) const { return (this->_n > rhs._n); }
		bool operator<(AnyType const & rhs ) const { return (this->_n < rhs._n); }
		bool operator>=(AnyType const & rhs ) const { return (this->_n >= rhs._n); }
		bool operator<=(AnyType const & rhs ) const { return (this->_n <= rhs._n); }
};
std::ostream & operator<<(std::ostream & os, const AnyType & src) { os << src.getN(); return (os); }


#endif //IDENTIFYREALTYPE_WHATEVER_H
