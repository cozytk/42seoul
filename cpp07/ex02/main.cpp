#include "Array.tpp"
#include "Array.cpp"
#include <iomanip>

int	main(void)
{
	Array<float> a(5);
	std::cout << "Checking default Initialization for length [5] float Array:" << std::endl;
	std::cout << std::setprecision(1) << std::fixed;
	a.print();
	std::cout << "changing default values..." << std::endl;
	for (int i = 0; i < 5; i++)
		a[i] = i;
	a.print();
	std::cout << "------------------------------------------------------------" << std::endl;
	Array<int> b(0);
	std::cout << "Checking empty int Array:" << std::endl;
	b.print();
	std::cout << "Trying to change value at [0]:" << std::endl;
	try
	{
		b[0] = 42;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n' << std::endl;
	}
	std::cout << "------------------------------------------------------------" << std::endl;
	Array<size_t> c(10);
	std::cout << "Checking default Initialization for length [10] size_t Array:" << std::endl;
	c.print();
	std::cout << "changing default values..." << std::endl;
	for (int i = 0; i < 10; i++)
		c[i] = i * 10 + 2;
	c.print();

	Array<std::string> d(5);
	std::cout << "Checking default Initialization for length [5] string Array:" << std::endl;
	d.print();
	std::cout << "changing default values..." << std::endl;
	d[0] = "Woow";
	d[1] = "everything";
	d[2] = "works";
	d[3] = "as";
	d[4] = "expected !";
	d.print();
	std::cout << "------------------------------------------------------------" << std::endl;
	Array<char> e(5);
	std::cout << "Checking default Initialization for length [5] char Array:" << std::endl;
	e.print();
	std::cout << "changing default values..." << std::endl;
	e[0] = 'H';
	e[1] = 'e';
	e[2] = 'l';
	e[3] = 'l';
	e[4] = 'o';
	e.print();
	std::cout << "Trying to edit value at index [42]:" << std::endl;
	try
	{
		e[42] = '*';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n' << std::endl;
	}
	std::cout << "------------------------------------------------------------" << std::endl;
	return 0;
}