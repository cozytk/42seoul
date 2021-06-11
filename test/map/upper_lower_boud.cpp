int main ()
{
	std::map<char,int> mymap;
	std::map<char,int>::iterator itlow,itup;
	ft::map<char,int> ftmap;
	ft::map<char,int>::iterator ftlow,ftup;

	mymap['a']=20;
	mymap['b']=40;
	mymap['c']=60;
	mymap['d']=80;
	mymap['e']=100;
	ftmap['a']=20;
	ftmap['b']=40;
	ftmap['c']=60;
	ftmap['d']=80;
	ftmap['e']=100;

	print_map(mymap);
	print_map(ftmap);

	std::cout << "itlow points to b" << std::endl;
	std::cout << "itup points to e" << std::endl;
	itlow=mymap.lower_bound ('b');  // itlow points to b
	itup=mymap.upper_bound ('d');   // itup points to e (not d!)
	ftlow=ftmap.lower_bound ('b');  // itlow points to b
	ftup=ftmap.upper_bound ('d');   // itup points to e (not d!)

	std::cout << "erase b to e" << std::endl;
	mymap.erase(itlow,itup);        // erases [itlow,itup)
	ftmap.erase(ftlow,ftup);        // erases [itlow,itup)

	// print content:
	print_map(mymap);
	print_map(ftmap);

	return 0;
}