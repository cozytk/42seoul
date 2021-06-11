int main ()
{
	std::map<char,int> mymap;
	std::map<char,int>::iterator it;
	ft::map<char,int> ftmap;
	ft::map<char,int>::iterator ft;

	mymap['a']=50;
	mymap['b']=100;
	mymap['c']=150;
	mymap['d']=200;
	ftmap['a']=50;
	ftmap['b']=100;
	ftmap['c']=150;
	ftmap['d']=200;

	print_map(mymap);
	print_map(ftmap);

	it = mymap.find('b');
	if (it != mymap.end())
		mymap.erase (it);
	ft = ftmap.find('b');
	if (ft != ftmap.end())
		ftmap.erase (ft);

	// print content:
	std::cout << "elements in mymap:" << '\n';
	std::cout << "a => " << mymap.find('a')->second << '\n';
	std::cout << "c => " << mymap.find('c')->second << '\n';
	std::cout << "d => " << mymap.find('d')->second << '\n';
	std::cout << "elements in ftmap:" << '\n';
	std::cout << "a => " << ftmap.find('a')->second << '\n';
	std::cout << "c => " << ftmap.find('c')->second << '\n';
	std::cout << "d => " << ftmap.find('d')->second << '\n';

	return 0;
}