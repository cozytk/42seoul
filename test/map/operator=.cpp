int main ()
{
	std::map<char,int> first;
	std::map<char,int> second;
	ft::map<char,int> ft_first;
	ft::map<char,int> ft_second;

	first['x']=8;
	first['y']=16;
	first['z']=32;
	ft_first['x']=8;
	ft_first['y']=16;
	ft_first['z']=32;

	second=first;                // second now contains 3 ints
	first=std::map<char,int>();  // and first is now empty
	ft_second=ft_first;                // second now contains 3 ints
	ft_first=ft::map<char,int>();  // and first is now empty

	std::cout << "Size of first: " << first.size() << '\n';
	std::cout << "Size of second: " << second.size() << '\n';
	std::cout << "Size of first: " << ft_first.size() << " ft\n";
	std::cout << "Size of second: " << ft_second.size() << " ft\n";
	return 0;
}