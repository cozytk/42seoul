int main ()
{
	std::list<int> mylist;
	ft::list<int> ftlist;

	for (int i=1; i<10; ++i) mylist.push_back(i);
	for (int i=1; i<10; ++i) ftlist.push_back(i);

	std::cout << "Init\n";
	print_list(mylist);
	print_list(ftlist);

	mylist.reverse();
	ftlist.reverse();

	std::cout << "mylist contains:\n";
	print_list(mylist);
	print_list(ftlist);

	return 0;
}