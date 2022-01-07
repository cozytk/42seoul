#include <cmath>
#include <list>

// a binary predicate implemented as a function:
bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

// a binary predicate implemented as a class:
struct is_near {
	bool operator() (double first, double second)
	{ return (fabs(first-second)<5.0); }
};

int main ()
{
	double mydoubles[] = {12.15, 2.72, 73.0, 12.77, 3.14,
	                      12.77, 73.35, 72.25, 15.3, 72.25};
	std::list<double> mylist(mydoubles, mydoubles + 10);
	ft::list<double> ftlist(mydoubles, mydoubles + 10);

	std::cout << "list generates:\n";
	print_list(mylist);
	print_list(ftlist);

	mylist.sort();             //  2.72,  3.14, 12.15, 12.77, 12.77,
	ftlist.sort();             //  2.72,  3.14, 12.15, 12.77, 12.77,
	// 15.3,  72.25, 72.25, 73.0,  73.35
	std::cout << "list sorted:\n";
	print_list(mylist);
	print_list(ftlist);

	mylist.unique();           //  2.72,  3.14, 12.15, 12.77
	ftlist.unique();           //  2.72,  3.14, 12.15, 12.77
	// 15.3,  72.25, 73.0,  73.35
	std::cout << "unique():\n";
	print_list(mylist);
	print_list(ftlist);

	mylist.unique(same_integral_part);  //  2.72,  3.14, 12.15
	ftlist.unique(same_integral_part);  //  2.72,  3.14, 12.15
	// 15.3,  72.25, 73.0

	std::cout << "unique(same_int):\n";
	print_list(mylist);
	print_list(ftlist);
	mylist.unique(is_near());           //  2.72, 12.15, 72.25
	ftlist.unique(is_near());           //  2.72, 12.15, 72.25

	std::cout << "unique(is_near):\n";
	print_list(mylist);
	print_list(ftlist);
	std::cout << "list contains:\n";
	print_list(mylist);
	print_list(ftlist);

	return 0;
}