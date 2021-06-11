int main ()
{
	std::vector<int> myvector (10);   // 10 zero-initialized ints
	ft::vector<int> ftvector (10);   // 10 zero-initialized ints

	// assign some values:
	for (unsigned i=0; i<myvector.size(); i++)
		myvector.at(i)=i;
	for (unsigned i=0; i<ftvector.size(); i++)
		ftvector.at(i)=i;

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector.at(i);
	std::cout << '\n';
	std::cout << "ftvector contains:";
	for (unsigned i=0; i<ftvector.size(); i++)
		std::cout << ' ' << ftvector.at(i);
	std::cout << '\n';
	std::cout << "back - front : " <<  myvector.back() - myvector.front() << std::endl;
	std::cout << "back - front : " <<  ftvector.back() - ftvector.front() << " ft" << std::endl;
	return 0;
}