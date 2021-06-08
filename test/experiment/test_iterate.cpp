#include <Vector.hpp>
#include <vector>
#include <iterator.hpp>
#include <iostream>

int main()
{
	ft::vector<int> ft_vec(10, 5);
	std::vector<int> std_vec(10, 5);

	/*
	 * >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	 * ft::vector_iterator<int> ft_it
	 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	 * std::__wrap_iter<std::vector<int, std::allocator<int>>::pointer> std_it
	 */
	ft::vector<int>::iterator ft_it;
	ft_it = ft_vec.begin();
	ft::vector<int>::iterator ft_it2(ft_it);
	ft::vector<int>::iterator ft_it3 = ft_it2;
	std::vector<int>::iterator std_it;
	std_it = std_vec.begin();
	std::vector<int>::iterator std_it2(std_it);
	std::vector<int>::iterator std_it3 = std_it2;

	std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
	if (ft_it == ft_it2 && !(ft_it != ft_it3))
	{
		std::cout << *ft_it << std::endl;
		*ft_it = 6;
		std::cout << *ft_it << std::endl;
		std::cout << ft_it.base() << std::endl;
		if (ft_it2++ == ft_it)
			std::cout << "prefix operand" << std::endl;
		if (++ft_it3 != ft_it)
			std::cout << "postfix operand" << std::endl;
		*ft_it++;
		if (ft_it2 == ft_it)
			std::cout << "dereferenceable increment operand" << std::endl;
		if (ft_it2-- == ft_it)
			std::cout << "prefix operand" << std::endl;
		if (--ft_it3 != ft_it)
			std::cout << "postfix operand" << std::endl;
		*ft_it--;
		if (ft_it2 == ft_it)
			std::cout << "dereferenceable decrease operand" << std::endl;
	}
	std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
	if (std_it == std_it2 && !(std_it != std_it3))
	{
		std::cout << *std_it << std::endl;
		*std_it = 6;
		std::cout << *std_it << std::endl;
		std::cout << std_it.base() << std::endl;
		if (std_it2++ == std_it)
			std::cout << "prefix operand" << std::endl;
		if (++std_it3 != std_it)
			std::cout << "postfix operand" << std::endl;
		*std_it++;
		if (std_it2 == std_it)
			std::cout << "dereferenceable increment operand" << std::endl;
		if (std_it2-- == std_it)
			std::cout << "prefix operand" << std::endl;
		if (--std_it3 != std_it)
			std::cout << "postfix operand" << std::endl;
		*std_it--;
		if (std_it2 == std_it)
			std::cout << "dereferenceable decrease operand" << std::endl;
	}
}

//
// Created by Taekyun Kim on 6/7/21.
//

