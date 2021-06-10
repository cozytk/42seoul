
int main ()
{
	std::list<int> mylist;
	ft::list<int> ftlist;

	// set some initial content:
	for (int i=1; i<10; ++i) mylist.push_back(i);
	for (int i=1; i<10; ++i) ftlist.push_back(i);

	mylist.resize(5);
	mylist.resize(8,100);
	mylist.resize(12);
	ftlist.resize(5);
	ftlist.resize(8,100);
	ftlist.resize(12);

	print_list(mylist);
	print_list(ftlist);

	return 0;
}