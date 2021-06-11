int main ()
{
	std::map<char,int> mymap;
	ft::map<char,int> ftmap;

	mymap['x']=1001;
	mymap['y']=2002;
	mymap['z']=3003;
	ftmap['x']=1001;
	ftmap['y']=2002;
	ftmap['z']=3003;

	print_map(mymap);
	print_map(ftmap);

	std::cout << "mymap contains:\n";

	std::pair<char,int> highest = *mymap.rbegin();          // last element
	std::map<char,int>::iterator it = mymap.begin();
	ft::pair<char,int> ft_highest = *ftmap.rbegin();          // last element
	ft::map<char,int>::iterator ft = ftmap.begin();

	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( mymap.value_comp()(*it++, highest) );
	do {
		std::cout << ft->first << " => " << ft->second << " ft\n";
	} while ( ftmap.value_comp()(*ft++, ft_highest) );


	return 0;
}