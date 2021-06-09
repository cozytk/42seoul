int main() {
	typedef std::iterator_traits<int*> traits;
	if (typeid(traits::iterator_category)==typeid(std::random_access_iterator_tag))
		std::cout << "int* is a random-access iterator";
	typedef ft::iterator_traits<int*> ftraits;
	std::cout << std::endl;
	if (typeid(ftraits::iterator_category)==typeid(ft::random_access_iterator_tag))
		std::cout << "fnt* is a random-access iterator";
	return 0;
}