int main ()
{
	std::map<char,std::string> mymap;
	ft::map<char,std::string> ftmap;

	mymap['a']="an element";
	mymap['b']="another element";
	mymap['c']=mymap['b'];
	ftmap['a']="an element";
	ftmap['b']="another element";
	ftmap['c']=ftmap['b'];

	std::cout << "mymap['a'] is " << mymap['a'] << '\n';
	std::cout << "mymap['b'] is " << mymap['b'] << '\n';
	std::cout << "mymap['c'] is " << mymap['c'] << '\n';
	std::cout << "mymap['d'] is " << mymap['d'] << '\n';
	std::cout << "ftmap['a'] is " << ftmap['a'] << '\n';
	std::cout << "ftmap['b'] is " << ftmap['b'] << '\n';
	std::cout << "ftmap['c'] is " << ftmap['c'] << '\n';
	std::cout << "ftmap['d'] is " << ftmap['d'] << '\n';

	std::cout << "mymap now contains " << mymap.size() << " elements.\n";
	std::cout << "ftmap now contains " << ftmap.size() << " elements.\n";

	return 0;
}