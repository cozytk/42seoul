int main ()
{
	std::map<char,int> mymap;
	ft::map<char,int> ftmap;

	mymap['x']=100;
	mymap['y']=200;
	mymap['z']=300;
	ftmap['x']=100;
	ftmap['y']=200;
	ftmap['z']=300;

	std::cout << "mymap contains:\n";
	print_map(mymap);
	print_map(ftmap);

	mymap.clear();
	ftmap.clear();
	mymap['a']=1101;
	mymap['b']=2202;
	ftmap['a']=1101;
	ftmap['b']=2202;

	std::cout << "clear() and reallocate\n";

	std::cout << "mymap contains:\n";
	print_map(mymap);
	print_map(ftmap);

	return 0;
}
