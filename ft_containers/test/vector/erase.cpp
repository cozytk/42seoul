int main ()
{
	std::vector<int> myvector;
	ft::vector<int> ft_vec;

	for (int i=1; i<=10; i++) myvector.push_back(i);
	for (int i=1; i<=10; i++) ft_vec.push_back(i);


	std_print_vec(myvector);
	ft_print_vec(ft_vec);

	myvector.erase (myvector.begin(),myvector.begin()+3);
	ft_vec.erase (ft_vec.begin(),ft_vec.begin()+3);

	myvector.erase (myvector.begin()+5);
	ft_vec.erase (ft_vec.begin()+5);

	std_print_vec(myvector);
	ft_print_vec(ft_vec);

	return 0;
