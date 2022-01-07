int main ()
{
	std::map<char,int> first;
	ft::map<char,int> ft_first;

	first['a']=10;
	first['b']=30;
	first['c']=50;
	first['d']=70;
	ft_first['a']=10;
	ft_first['b']=30;
	ft_first['c']=50;
	ft_first['d']=70;
	std::cout << "default constuctor, and allocate : first generate\n";
	print_map(first);
	print_map(ft_first);
	std::map<char,int> second (first.begin(),first.end());
	ft::map<char,int> ft_second (ft_first.begin(),ft_first.end());
	std::cout << "Iterator constructor : second generate\n";
	print_map(second);
	print_map(ft_second);
	std::map<char,int> third (second);
	ft::map<char,int> ft_third (ft_second);
	std::cout << "Copy constructor : third generate\n";
	print_map(third);
	print_map(ft_third);
	std::map<char,int,classcomp> fourth;                 // class as Compare
	ft::map<char,int,classcomp> ft_fourth;                 // class as Compare
	std::cout << "Class as compare constructor : fourth generate\n";
	print_map(fourth);
	print_map(ft_fourth);
	bool(*fn_pt)(char,char) = fncomp;
	std::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
	bool(*ft_pt)(char,char) = fncomp;
	ft::map<char,int,bool(*)(char,char)> ft_fifth (ft_pt); // function pointer as Compare
	print_map(fifth);
	print_map(ft_fifth);
	return 0;
}