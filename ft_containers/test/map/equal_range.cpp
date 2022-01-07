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

	std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
	ret = mymap.equal_range('b');
	ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ft_ret;
	ft_ret = ftmap.equal_range('b');

	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';
	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';
	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << " ft\n";
	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << " ft\n";

	return 0;
}