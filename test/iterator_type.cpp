#include <iostream>
#include <vector>

int main()
{
	std::vector<int> my_vec(10, 3);
	std::vector<int>::iterator it;
//	std::vector<int>::iterator<*_tag, type> it; -> impossible

	it = my_vec.begin();
	std::cout << *it << std::endl;
}
