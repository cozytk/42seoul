int main ()
{
	std::vector<int> myvector;
	ft::vector<int> ftvector;
	int sum (0);
	int ft_sum (0);
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);
	ftvector.push_back (100);
	ftvector.push_back (200);
	ftvector.push_back (300);

	while (!myvector.empty())
	{
		sum+=myvector.back();
		myvector.pop_back();
	}
	std::cout << "The elements of myvector add up to " << sum << '\n';
	while (!ftvector.empty())
	{
		ft_sum+=ftvector.back();
		ftvector.pop_back();
	}
	std::cout << "The elements of ftvector add up to " << sum << '\n';

	return 0;
}