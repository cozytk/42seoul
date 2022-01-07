int main ()
{
	std::vector<int> myints;
	ft::vector<int> ftints;
	std::cout << "0. size: " << myints.size() << '\n';
	std::cout << "0. size: " << ftints.size() << '\n';

	for (int i=0; i<10; i++) myints.push_back(i);
	std::cout << "1. size: " << myints.size() << '\n';
	for (int i=0; i<10; i++) ftints.push_back(i);
	std::cout << "1. size: " << ftints.size() << '\n';

	myints.insert (myints.end(),10,100);
	std::cout << "2. size: " << myints.size() << '\n';
	ftints.insert (ftints.end(),10,100);
	std::cout << "2. size: " << ftints.size() << '\n';

	myints.pop_back();
	std::cout << "3. size: " << myints.size() << '\n';
	ftints.pop_back();
	std::cout << "3. size: " << ftints.size() << '\n';

	std::cout << "4. max_size : " << myints.max_size() << '\n';
	std::cout << "4. max_size : " << ftints.max_size() << '\n';

	myints.resize(5);
	myints.resize(8,100);
	myints.resize(12);
	ftints.resize(5);
	ftints.resize(8,100);
	ftints.resize(12);

	std::cout << "myvector contains:";
	for (unsigned int i=0;i<myints.size();i++)
		std::cout << ' ' << myints[i];
	std::cout << '\n';
	std::cout << "ftvector contains:";
	for (unsigned int i=0;i<ftints.size();i++)
		std::cout << ' ' << ftints[i];
	std::cout << '\n';

	return 0;
}