int main ()
{
	std::list<int> mylist;
	ft::list<int> ftlist;

	// set some values:
	for (int i = 1; i < 10; ++i) mylist.push_back(i * 10);
	for (int i = 1; i < 10; ++i) ftlist.push_back(i * 10);

	std::list<int>::iterator it = mylist.begin();
	std::list<int>::iterator it2 = mylist.end();
	ft::list<int>::iterator ft = ftlist.begin();
	ft::list<int>::iterator ft2 = ftlist.end();
	print_list(mylist);
	print_list(ftlist);
	it = mylist.erase(it);
	ft = ftlist.erase(ft);
	print_list(mylist);
	print_list(ftlist);
	++it;
	--it2;
	++ft;
	--ft2;
	mylist.erase(it, it2);
	ftlist.erase(ft, ft2);
	if (mylist.empty())
		std::cout << "empty\n";
	else
		print_list(mylist);
	if (ftlist.empty())
		std::cout << "empty ft\n";
	else
		print_list(ftlist);

}//
// Created by Taekyun Kim on 6/10/21.
//

