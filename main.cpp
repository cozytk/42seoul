#include <List.hpp>
#include <ft_containers.hpp>
#include <Vector.hpp>

#include <vector>

int main () {
	std::vector<int> myvector;
	for (int i=0; i<10; i++) myvector.push_back(i);
	ft::vector<int> ftvector;
	for (int i=0; i<10; i++) ftvector.push_back(i);

	typedef std::vector<int>::iterator iter_type;
	typedef ft::vector<int>::iterator fter_type;
	// ? 0 1 2 3 4 5 6 7 8 9 ?
	iter_type from (myvector.begin());                     //   ^
	iter_type until (myvector.end());                      //                       ^
	fter_type ft_from (ftvector.begin());                     //   ^
	fter_type ft_until (ftvector.end());                      //                       ^
	//
	std::reverse_iterator<iter_type> rev_until (from);     // ^
	std::reverse_iterator<iter_type> rev_from (until);     //                     ^
	ft::reverse_iterator<fter_type> ft_rev_until (ft_from);     // ^
	ft::reverse_iterator<fter_type> ft_rev_from (ft_until);     //                     ^

	std::cout << "myvector:";
	while (rev_from != rev_until)
		std::cout << ' ' << *rev_from++;
	std::cout << '\n';

	std::cout << "ftvector:";
	while (ft_rev_from != ft_rev_until)
		std::cout << *ft_rev_from++;
	std::cout << '\n';
	return 0;
}