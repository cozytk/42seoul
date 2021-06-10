int main ()
{
	std::map<char,int> mymap;
	ft::map<char,int> ftmap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;
	ftmap['a']=10;
	ftmap['b']=20;
	ftmap['c']=30;

	while (!mymap.empty())
	{
		std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
		mymap.erase(mymap.begin());
	}
	while (!ftmap.empty())
	{
		std::cout << ftmap.begin()->first << " => " << ftmap.begin()->second << '\n';
		ftmap.erase(ftmap.begin());
	}

	return 0;
}