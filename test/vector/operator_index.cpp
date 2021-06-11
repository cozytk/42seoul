
int main ()
{
	std::vector<int> myvector (10);   // 10 zero-initialized elements
	std::vector<int> ftvector (10);   // 10 zero-initialized elements

	std::vector<int>::size_type sz = myvector.size();
	ft::vector<int>::size_type ft_sz = ftvector.size();

	// assign some values:
	for (unsigned i=0; i<sz; i++) myvector[i]=i;
	for (unsigned i=0; i<ft_sz; i++) ftvector[i]=i;

	// reverse vector using operator[]:
	for (unsigned i=0; i<sz/2; i++)
	{
		int temp;
		temp = myvector[sz-1-i];
		myvector[sz-1-i]=myvector[i];
		myvector[i]=temp;
	}
	std::cout << "myvector contains:";
	for (unsigned i=0; i<ft_sz/2; i++)
	{
		int temp;
		temp = ftvector[ft_sz-1-i];
		ftvector[ft_sz-1-i]=ftvector[i];
		ftvector[i]=temp;
	}
	for (unsigned i=0; i<sz; i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
	std::cout << "ftvector contains:";
	for (unsigned i=0; i<ft_sz; i++)
		std::cout << ' ' << ftvector[i];
	std::cout << '\n';
	return 0;
}