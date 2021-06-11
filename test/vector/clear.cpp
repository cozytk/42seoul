int main ()
{
//	std::vector<int> myvector;
//	myvector.push_back (100);
//	myvector.push_back (200);
//	myvector.push_back (300);
	ft::vector<int> myvector;
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);

	print_vec(myvector);

	myvector.clear();
	myvector.push_back (1101);
	myvector.push_back (2202);

	print_vec(myvector);
	return 0;
}