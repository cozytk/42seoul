int main ()
{
	std::list<int> first (3);      // list of 3 zero-initialized ints
	std::list<int> second (5);     // list of 5 zero-initialized ints
	ft::list<int> ft_first (3);      // list of 3 zero-initialized ints
	ft::list<int> ft_second (5);     // list of 5 zero-initialized ints

	second = first;
	first = std::list<int>();
	ft_second = ft_first;
	ft_first = ft::list<int>();

	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "Size of second: " << int (second.size()) << '\n';
	std::cout << "Size of first: " << int (ft_first.size()) << "-> ft\n";
	std::cout << "Size of second: " << int (ft_second.size()) << "-> ft\n";
	return 0;
}