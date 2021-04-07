#include "iter.hpp"

int	main(void)
{
	int		array_int[] = {0, 1, 2, 3, 4, 5, 6};
	std::string array_str[] = {"t1", "t2", "t3"};
	AnyType array_any[5];

	iter(array_int, 7, &print);
	std::cout << "---------" << std::endl;
	iter(array_str, 3, &print);
	std::cout << "---------" << std::endl;
	iter(array_any, 5, &print);

	return (0);
}