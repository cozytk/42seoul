int main ()
{
	std::vector<int> myvector;
	ft::vector<int> ft_myvector;
	int i, ft_i;
	for (i=1; i<=5; i++) myvector.push_back(i);
	for (ft_i=1; ft_i<=5; ft_i++) ft_myvector.push_back(ft_i);

	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "ftvector contains:";
	for (ft::vector<int>::iterator it = ft_myvector.begin() ; it != ft_myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	i = 0;
	ft_i = 0;
	std::vector<int>::reverse_iterator rit = myvector.rbegin();
	for (; rit!= myvector.rend(); ++rit)
		*rit = ++i;
	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	ft::vector<int>::reverse_iterator ft_rit = ft_myvector.rbegin();
	for (; ft_rit!= ft_myvector.rend(); ++ft_rit)
		*ft_rit = ++ft_i;
	std::cout << "ftvector contains:";
	for (ft::vector<int>::iterator it = ft_myvector.begin(); it != ft_myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	return 0;
}
