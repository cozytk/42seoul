bool single_digit (const int& value) { return (value<10); }

// a predicate implemented as a class:
struct is_odd {
	bool operator() (const int& value) { return (value%2)==1; }
};
int main ()
{
	int myints[]= {1,52,17,89,7,20,14,91,44};
	std::list<int> mylist (myints,myints+8);
	ft::list<int> ftlist (myints,myints+8);

	mylist.remove(89);
	ftlist.remove(89);

	std::cout << "mylist contains:\n";
	print_list(mylist);
	print_list(ftlist);
	mylist.remove_if(single_digit);
	ftlist.remove_if(single_digit);
	std::cout << "remove if single_digit\n";
	print_list(mylist);
	print_list(ftlist);
	mylist.remove_if(is_odd());
	ftlist.remove_if(is_odd());
	std::cout << "remove if is_odd\n";
	print_list(mylist);
	print_list(ftlist);

	return 0;
}//
// Created by Taekyun Kim on 6/10/21.
//

