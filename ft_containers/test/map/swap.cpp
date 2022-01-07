int main ()
{
	std::map<char,int> foo,bar;
	ft::map<char,int> ft_foo,ft_bar;

	foo['x']=100;
	foo['y']=200;
	ft_foo['x']=100;
	ft_foo['y']=200;

	bar['a']=11;
	bar['b']=22;
	bar['c']=33;
	ft_bar['a']=11;
	ft_bar['b']=22;
	ft_bar['c']=33;
	std::cout << "foo contains:\n";
	print_map(foo);
	print_map(ft_foo);
	std::cout << "bar contains:\n";
	print_map(bar);
	print_map(ft_bar);

	foo.swap(bar);
	ft_foo.swap(ft_bar);

	std::cout << "swap foo , boo\n";

	std::cout << "foo contains:\n";
	print_map(foo);
	print_map(ft_foo);
	std::cout << "bar contains:\n";
	print_map(bar);
	print_map(ft_bar);

	return 0;
}