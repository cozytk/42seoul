int main ()
{
	std::map<char,int> mymap;
	ft::map<char,int> ftmap;

	print_map(mymap);
	print_map(ftmap);

	std::cout << "after allocate \n";

	mymap['b'] = 100;
	mymap['a'] = 200;
	mymap['c'] = 300;
	ftmap['b'] = 100;
	ftmap['a'] = 200;
	ftmap['c'] = 300;

	// show content:
	print_map(mymap);
	print_map(ftmap);
	std::map<char,int>::reverse_iterator rit;
	for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
		std::cout << rit->first << " => " << rit->second << '\n';
	ft::map<char,int>::reverse_iterator rft;
	for (rft=ftmap.rbegin(); rft!=ftmap.rend(); ++rft)
		std::cout << rft->first << " => " << rft->second << '\n';
	return 0;
}