#include "mutantstack.hpp"
//
//template <typename T>
//MutantStack<T>::MutantStack()
//{}
//
//template <typename T>
//MutantStack<T>::MutantStack(MutantStack<T> const &copy)
//{
//	*this = copy;
//}
//
//template <typename T>
//MutantStack<T>	&MutantStack<T>::operator=(MutantStack<T> const &obj)
//{
//	this->c = obj.c;
//	return (*this);
//}
//
//template <typename T>
//MutantStack<T>::~MutantStack()
//{}
//
//template <typename T>
//typename MutantStack<T>::iterator	MutantStack<T>::begin()
//{
//	return (this->c.begin());
//}
//
//template <typename T>
//typename MutantStack<T>::iterator	MutantStack<T>::end()
//{
//	return (this->c.end());
//}
//
//#include "mutantstack.hpp"

// 생성자
template <typename T>
MutantStack<T>::MutantStack(){}

// 소멸자
template <typename T>
MutantStack<T>::~MutantStack(){}

// 복사생성자
template <typename T>
MutantStack<T>::MutantStack(MutantStack<T> const &other)
{
	*this = other;
}

// 대입연산자 오버로딩
template <typename T>
MutantStack<T>	&MutantStack<T>::operator=(MutantStack<T> const &other)
{
	this->c = other.c;  // 객체의 iterator 설정
	return (*this);
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin()
{
	return (this->c.begin());  // 원소 처음을 가리키는 iterator 반환
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end()
{
	return (this->c.end());  // 원소 마지막의 다음을 가리키는 iterator 반환
}