int main ()
{
	std::vector<int>::size_type sz;
	ft::vector<int>::size_type ft_sz;

	std::vector<int> foo;
	ft::vector<int> ft_foo;
	sz = foo.capacity();
	ft_sz = ft_foo.capacity();
	std::cout << "capacity is : " <<  sz << std::endl;
	std::cout << "ft_capacity is : " <<  ft_sz << std::endl;
	std::cout << "making foo grow:\n";
	for (int i=0; i<100; ++i) {
		foo.push_back(i);
		if (sz!=foo.capacity()) {
			sz = foo.capacity();
			std::cout << "std : capacity changed: " << sz << '\n';
		}
	}
	for (int i=0; i<100; ++i) {
		ft_foo.push_back(i);
		if (ft_sz!=ft_foo.capacity()) {
			ft_sz = ft_foo.capacity();
			std::cout << "ft : capacity changed: " << ft_sz << '\n';
		}
	}
	std::vector<int> bar;
	sz = bar.capacity();
	bar.reserve(100);   // this is the only difference with foo above
	ft::vector<int> ft_bar;
	ft_sz = ft_bar.capacity();
	ft_bar.reserve(100);
	std::cout << "making bar grow:\n";
	for (int i=0; i<100; ++i) {
		bar.push_back(i);
		if (sz!=bar.capacity()) {
			sz = bar.capacity();
			std::cout << "std : capacity changed: " << sz << '\n';
		}
	}
	for (int i=0; i<100; ++i) {
		ft_bar.push_back(i);
		if (ft_sz!=ft_bar.capacity()) {
			ft_sz = ft_bar.capacity();
			std::cout << "ft : capacity changed: " << ft_sz << '\n';
		}
	}
	return 0;
}