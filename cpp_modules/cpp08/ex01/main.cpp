#include "span.hpp"

int	main(void)
{
	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	Span		stor(100002);

	try
	{
		stor.shortestSpan();
	}
	catch (std::exception & e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	stor.addNumber(1);
	try
	{
		stor.longestSpan();
	}
	catch (std::exception & e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	for (int i = 2 ; i <= 10 ; i++)
		stor.addNumber(i);
	std::cout << "Shortest span : " << stor.shortestSpan() << std::endl;
	std::cout << "Longest span : " << stor.longestSpan() << std::endl;
	stor.addNumbers(11, 100000);
	std::cout << "Shortest span : " << stor.shortestSpan() << std::endl;
	std::cout << "Longest span : " << stor.longestSpan() << std::endl;
	stor.addNumber(-100000);
	std::cout << "Shortest span : " << stor.shortestSpan() << std::endl;
	std::cout << "Longest span : " << stor.longestSpan() << std::endl;
	try
	{
		stor.addNumber(42);
	}
	catch (std::exception & e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	return (0);
}