
int main ()
{
	std::map<char,int> mymap;
	ft::map<char,int> ftmap;

	// first insert function version (single parameter):
	mymap.insert ( std::pair<char,int>('a',100) );
	mymap.insert ( std::pair<char,int>('z',200) );
	ftmap.insert ( ft::pair<char,int>('a',100) );
	ftmap.insert ( ft::pair<char,int>('z',200) );

	std::pair<std::map<char,int>::iterator,bool> ret;
	ret = mymap.insert ( std::pair<char,int>('z',500) );
	if (ret.second==false) {
		std::cout << "element 'z' already existed";
		std::cout << " with a value of " << ret.first->second << '\n';
	}
	ft::pair<ft::map<char,int>::iterator,bool> ft_ret;
	ft_ret = ftmap.insert ( ft::pair<char,int>('z',500) );
	if (ft_ret.second==false) {
		std::cout << "element 'z' already existed";
		std::cout << " with a value of " << ft_ret.first->second << '\n';
	}

	// second insert function version (with hint position):
	std::map<char,int>::iterator it = mymap.begin();
	mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
	mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting
	ft::map<char,int>::iterator ft = ftmap.begin();
	ftmap.insert (ft, ft::pair<char,int>('b',300));  // max efficiency inserting
	ftmap.insert (ft, ft::pair<char,int>('c',400));  // no max efficiency inserting

	// third insert function version (range insertion):
	std::map<char,int> anothermap;
	anothermap.insert(mymap.begin(),mymap.find('c'));
	ft::map<char,int> ftanothermap;
	ftanothermap.insert(ftmap.begin(),ftmap.find('c'));

	// showing contents:
	std::cout << "mymap contains:\n";
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << "ftmap contains:\n";
	for (ft=ftmap.begin(); ft!=ftmap.end(); ++ft)
		std::cout << ft->first << " => " << ft->second << '\n';

	std::cout << "anothermap contains:\n";
	for (it=anothermap.begin(); it!=anothermap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << "anothermap contains:\n";
	for (ft=ftanothermap.begin(); ft!=ftanothermap.end(); ++ft)
		std::cout << ft->first << " => " << ft->second << '\n';

	return 0;
}
