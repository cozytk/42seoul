#include <list>
#include <vector>
#include <List.hpp>
#include <Vector.hpp>

int main ()
{
	std::list<int> mylist;
	std::list<int>::iterator it;
	ft::list<int> ftlist;
	ft::list<int>::iterator ft;

	// set some initial values:
	for (int i=1; i<=5; ++i) mylist.push_back(i); // 1 2 3 4 5
	for (int i=1; i<=5; ++i) ftlist.push_back(i); // 1 2 3 4 5
	++it;       // it points now to number 2           ^
	ft = ftlist.begin();
	++ft;       // it points now to number 2           ^

	mylist.insert (it,10);                        // 1 10 2 3 4 5
	ftlist.insert (ft,10);                        // 1 10 2 3 4 5

	// "it" still points to number 2                      ^
	mylist.insert (it,2,20);                      // 1 10 20 20 2 3 4 5
	ftlist.insert (ft,2,20);                      // 1 10 20 20 2 3 4 5

	--it;       // it points now to the second 20            ^
	--ft;       // it points now to the second 20            ^

	std::vector<int> myvector (2,30);
	mylist.insert (it,myvector.begin(),myvector.end());
	ft::vector<int> ftvector (2,30);
	ftlist.insert (ft,ftvector.begin(),ftvector.end());
	// 1 10 20 30 30 20 2 3 4 5
	//               ^
	std::cout << "mylist contains:";
	for (it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "ftlist contains:";
	for (ft=ftlist.begin(); ft!=ftlist.end(); ++ft)
		std::cout << ' ' << *ft;
	std::cout << '\n';

	return 0;
}