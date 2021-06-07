#include <Vector.hpp>
#include <ft_containers.hpp>

#include <vector>

int main()
{
	ft::vector<int> ft_vec(24, 42);
	ft::vector<int>::iterator it;

	it += 100;
	std::cout << ft_vec.test(it) << std::endl;
//	ft::vector<int> ft_vec1(10, 5);
//	std::vector<int> std_vec1(10, 5);
//
//	for (ft::vector<int>::iterator it = ft_vec1.begin(); it != ft_vec1.end(); it++)
//		std::cout << *it << std::endl;
//	std::cout << ft_vec1.size() << std::endl;
//	std::cout << ft_vec1.capacity() << std::endl;
////	ft_vec1.resize(6);
//	std::cout << "-" << std::endl;
//	for (ft::vector<int>::iterator it = ft_vec1.begin(); it != ft_vec1.end(); it++)
//		std::cout << *it << std::endl;
//	std::cout << ft_vec1.size() << std::endl;
//	std::cout << ft_vec1.capacity() << std::endl;
//
//	for (std::vector<int>::iterator it = std_vec1.begin(); it != std_vec1.end(); it++)
//		std::cout << *it << std::endl;
//	std::cout << std_vec1.size() << std::endl;
//	std::cout << std_vec1.capacity() << std::endl;
//	std_vec1.resize(16, 100);
//	std::cout << "-" << std::endl;
//	for (std::vector<int>::iterator it = std_vec1.begin(); it != std_vec1.end(); it++)
//		std::cout << *it << std::endl;
//	std::cout << std_vec1.size() << std::endl;
//	std::cout << std_vec1.capacity() << std::endl;
//

//	ft::vector<int> ft_vec1(10, 5);
//	ft::vector<int> ft_vec2(ft_vec1);



};