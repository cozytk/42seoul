//
// Created by taekkim on 2021/04/06.
//

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

class AnyType {
	private:
		std::string _name;
	public:
		AnyType() : _name("tests") {};
		getName(){ return (_name) };
};

template <typename T>
void	iter(T *address, size_t lenght, void (*func)(T &))
{
	for (size_t i = 0; i < lenght; i++)
		func(address[i]);
}

template <typename T>
void	print(T &a)
{
	std::cout << a << std::endl;
}

#endif
