int main ()
{
	// constructors used in the same order as described above:
	std::list<int> first;                                // empty list of ints
	std::list<int> second (4,100);                       // four ints with value 100
	std::list<int> third (second.begin(),second.end());  // iterating through second
	std::list<int> fourth (third);                       // a copy of third
	ft::list<int> ft_first;                                // empty list of ints
	ft::list<int> ft_second (4,100);                       // four ints with value 100
	ft::list<int> ft_third (ft_second.begin(),ft_second.end());  // iterating through second
	ft::list<int> ft_fourth (ft_third);                       // a copy of third

	// the iterator constructor can also be used to construct from arrays:
	int myints[] = {16,2,77,29};
	std::list<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
	ft::list<int> ft_fifth (myints, myints + sizeof(myints) / sizeof(int) );

	std::cout << "The contents of fifth are: ";
	for (std::list<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
		std::cout << *it << ' ';
	std::cout << '\n';
	std::cout << "The contents of fifth are: ";
	for (ft::list<int>::iterator it = ft_fifth.begin(); it != ft_fifth.end(); it++)
		std::cout << *it << ' ';
	std::cout << "-> ft";

	return 0;
}