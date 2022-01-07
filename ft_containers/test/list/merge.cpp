
// compare only integral part:
bool mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }

int main ()
{
	std::list<double> first, second;
	ft::list<double> ft_first, ft_second;

	first.push_back (3.1);
	first.push_back (2.2);
	first.push_back (2.9);
	second.push_back (3.7);
	second.push_back (7.1);
	second.push_back (1.4);
	ft_first.push_back (3.1);
	ft_first.push_back (2.2);
	ft_first.push_back (2.9);
	ft_second.push_back (3.7);
	ft_second.push_back (7.1);
	ft_second.push_back (1.4);

	std::cout << "first contains:\n";
	print_list(first);
	print_list(ft_first);
	std::cout << "second contains:\n";
	print_list(second);
	print_list(ft_second);
	first.sort();
	second.sort();
	ft_first.sort();
	ft_second.sort();
	std::cout << "after sort\n";
	print_list(first);
	print_list(ft_first);
	print_list(second);
	print_list(ft_second);

	std::cout << "after merge\n";
	first.merge(second);
	ft_first.merge(ft_second);
	print_list(first);
	print_list(ft_first);
	if (second.empty())
		std::cout << "second is empty\n";
	else
		print_list(second);
	if (ft_second.empty())
		std::cout << "second is empty ft\n";
	else
		print_list(ft_second);

	std::cout << "push_back 2.1 on second\n";

	second.push_back (2.1);
	ft_second.push_back (2.1);

	std::cout << "after merge with function(mycomparison)\n";

	first.merge(second,mycomparison);
	first.merge(second,mycomparison);
	ft_first.merge(ft_second,mycomparison);
	ft_first.merge(ft_second,mycomparison);

	std::cout << "first contains:\n";
	print_list(first);
	print_list(ft_first);

	return 0;
}