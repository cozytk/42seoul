#include "main.hpp"

/*
 * test 1, starting grade 1.
 */

int		main(void)
{
	try
	{
		Bureaucrat taekkim("taekkim", 1);
		std::cout << taekkim << std::endl;
		taekkim.decGrade();
		std::cout << taekkim << std::endl;
		taekkim.incGrade();
		std::cout << taekkim << std::endl;
		taekkim.incGrade();
		std::cout << taekkim << std::endl;

	}
	catch (std::exception & e)
	{
		std::cout << "Exception! " << e.what() << std::endl;
	}
	return (0);
}

/*
 * test 2, starting grade 150.
 */

/*
int		main(void)
{
	try
	{
		Bureaucrat taekkim("taekkim", 150);
		std::cout << taekkim << std::endl;
		taekkim.decGrade();
		std::cout << taekkim << std::endl;

	}
	catch (std::exception & e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	return (0);
}
 */