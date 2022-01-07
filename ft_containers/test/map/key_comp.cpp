
int main ()
{
	std::map<char,int> mymap;
	ft::map<char,int> ftmap;

	std::map<char,int>::key_compare mycomp = mymap.key_comp();
	ft::map<char,int>::key_compare ftcomp = ftmap.key_comp();

	mymap['a']=100;
	mymap['b']=200;
	mymap['c']=300;
	ftmap['a']=100;
	ftmap['b']=200;
	ftmap['c']=300;

	std::cout << "mymap contains:\n";
	char highest = mymap.rbegin()->first;     // key value of last element
	std::map<char,int>::iterator it = mymap.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( mycomp((*it++).first, highest) );
	std::cout << '\n';
	std::cout << "ftmap contains:\n";
	char fthighest = ftmap.rbegin()->first;     // key value of last element
	ft::map<char,int>::iterator ft = ftmap.begin();
	do {
		std::cout << ft->first << " => " << ft->second << '\n';
	} while ( ftcomp((*ft++).first, fthighest) );
	std::cout << '\n';

	return 0;
}