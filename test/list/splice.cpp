int main ()
{
	std::list<int> mylist1, mylist2;
	std::list<int>::iterator it;
	ft::list<int> ftlist1, ftlist2;
	ft::list<int>::iterator ft;

	// set some initial values:
	for (int i=1; i<=4; ++i)
		mylist1.push_back(i);      // mylist1: 1 2 3 4
	for (int i=1; i<=3; ++i)
		mylist2.push_back(i*10);   // mylist2: 10 20 30
	for (int i=1; i<=4; ++i)
		ftlist1.push_back(i);      // mylist1: 1 2 3 4
	for (int i=1; i<=3; ++i)
		ftlist2.push_back(i*10);   // mylist2: 10 20 30
	print_list(mylist1);
	print_list(ftlist1);
	print_list(mylist2);
	print_list(ftlist2);

	it = mylist1.begin();
	++it;                         // points to 2
	ft = ftlist1.begin();
	++ft;                         // points to 2

	mylist1.splice (it, mylist2); // mylist1: 1 10 20 30 2 3 4
	ftlist1.splice (ft, ftlist2); // mylist1: 1 10 20 30 2 3 4

	std::cout<<"list1 splice second it to list2\n";
	print_list(mylist1);
	print_list(ftlist1);
	print_list(mylist2);
	print_list(ftlist2);
	// mylist2 (empty)
	// "it" still points to 2 (the 5th element)

	mylist2.splice (mylist2.begin(),mylist1, it);
	ftlist2.splice (ftlist2.begin(),ftlist1, ft);
	// mylist1: 1 10 20 30 3 4
	// mylist2: 2
	// "it" is now invalid.
	it = mylist1.begin();
	++it;
	++it;
	++it;
	ft = ftlist1.begin();
	++ft;
	++ft;
	++ft;

	mylist1.splice ( mylist1.begin(), mylist1, it, mylist1.end());
	ftlist1.splice ( ftlist1.begin(), ftlist1, ft, ftlist1.end());
	// mylist1: 30 3 4 1 10 20

	std::cout << "mylist1 contains\n";
	print_list(mylist1);
	print_list(ftlist1);
	std::cout << "mylist2 contains\n";
	print_list(mylist2);
	print_list(ftlist2);

	return 0;
}