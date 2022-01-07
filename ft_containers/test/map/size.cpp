int main ()
{
	std::map<char,int> mymap;
	ft::map<char,int> ftmap;
	mymap['a']=101;
	mymap['b']=202;
	mymap['c']=302;
	ftmap['a']=101;
	ftmap['b']=202;
	ftmap['c']=302;

	std::cout << "mymap.size() is " << mymap.size() << '\n';
	std::cout << "ftmap.size() is " << ftmap.size() << '\n';
	std::cout << "mymap.size() is " << mymap.max_size() << '\n';
	std::cout << "ftmap.size() is " << ftmap.max_size() << '\n';

	return 0;
}