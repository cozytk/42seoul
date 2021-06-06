#include <iostream>

int main()
{
	std::allocator<int> my_alloc;
	int *a = my_alloc.allocate(42); // allocate 42 * sizeof(int)
	my_alloc.construct(a, 13); // a[0] is 13
	my_alloc.construct(a + 1, 42); // a[0] is 13, a[1] is 42
	std::cout << a[0] << std::endl;
	std::cout << a[1] << std::endl;
}