//#include <Vector.hpp>
//#include <vector>
//#include <iterator.hpp>
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> my_vec(10, 3);
	std::vector<int>::iterator it;

	it = my_vec.begin();

	std::cout << *it << std::endl;
}

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
