int main ()
{
	std::map<char,int> mymap;
	std::map<char,int>::iterator it;
	ft::map<char,int> ftmap;
	ft::map<char,int>::iterator ft;

	// insert some values:
	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;
	mymap['d']=40;
	mymap['e']=50;
	mymap['f']=60;
	ftmap['a']=10;
	ftmap['b']=20;
	ftmap['c']=30;
	ftmap['d']=40;
	ftmap['e']=50;
	ftmap['f']=60;
	print_map(mymap);
	print_map(ftmap);
	std::cout << "erase by iterator\n";
	it=mymap.find('b');
	ft=ftmap.find('b');
	mymap.erase (it);                   // erasing by iterator
	ftmap.erase (ft);                   // erasing by iterator
	print_map(mymap);
	print_map(ftmap);
	std::cout << "erase by key\n";
	mymap.erase ('c');                  // erasing by key
	ftmap.erase ('c');                  // erasing by key
	print_map(mymap);
	print_map(ftmap);
	it=mymap.find ('e');
	ft=ftmap.find ('e');
	std::cout << "erase by range\n";
	mymap.erase ( it, mymap.end() );    // erasing by range
	ftmap.erase ( ft, ftmap.end() );    // erasing by range
	print_map(mymap);
	print_map(ftmap);
	// show content:
	return 0;
}