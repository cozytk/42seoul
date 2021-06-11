int main ()
{
	std::vector<int> myvector;
	ft::vector<int> ftvector;
	int sum (0);
	int ft_sum (0);

	for (int i=1;i<=10;i++) myvector.push_back(i);
	for (int i=1;i<=10;i++) ftvector.push_back(i);

	while (!myvector.empty())
	{
		sum += myvector.back();
		myvector.pop_back();
	}
	std::cout << "std_total: " << sum << '\n';
	while (!ftvector.empty())
	{
		ft_sum += ftvector.back();
		ftvector.pop_back();
	}

	std::cout << "ft_total: " << sum << '\n';

	return 0;
}