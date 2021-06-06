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
//int main()
//{
//	// constructors used in the same order as described above:
//	ft::vector<int> ft_first;                                // empty vector of ints
//	ft::vector<int> ft_second (4,100);                       // four ints with value 100
//	ft::vector<int> ft_third (ft_second.begin(),ft_second.end());  // iterating through second
//	ft::vector<int> ft_fourth (ft_third);                       // a copy of third
//
//	// the iterator constructor can also be used to construct from arrays:
//	int ft_myints[] = {16,2,77,29};
//	ft::vector<int> ft_fifth (ft_myints, ft_myints + sizeof(ft_myints) / sizeof(int) );
//
//	std::cout << "The contents of fifth are:";
//	for (ft::vector<int>::iterator it = ft_fifth.begin(); it != ft_fifth.end(); ++it)
//		std::cout << ' ' << *it;
//	std::cout << '\n';
//
//	std::vector<int> std_first;                                // empty vector of ints
//	std::vector<int> std_second (4,100);                       // four ints with value 100
//	std::vector<int> std_third (std_second.begin(),std_second.end());  // iterating through second
//	std::vector<int> std_fourth (std_third);                       // a copy of third
//
//	// the iterator constructor can also be used to construct from arrays:
//	int std_myints[] = {16,2,77,29};
//	std::vector<int> std_fifth (std_myints, std_myints + sizeof(std_myints) / sizeof(int) );
//
//	std::cout << "The contents of fifth are:";
//	for (std::vector<int>::iterator it = std_fifth.begin(); it != std_fifth.end(); ++it)
//		std::cout << ' ' << *it;
//	std::cout << '\n';
//
//	return 0;
//}
//
