#include "main.hpp"

int	main(void)
{
	try
	{
		Form	form1("form1", 42, 0);
	}
	catch (std::exception & e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}

	Form		form2("form2", 42, 21);
	Bureaucrat	taekkim1("taekkim1", 142);
	Bureaucrat	taekkim2("taekkim2", 24);

	taekkim1.signForm(form2);
	std::cout << form2 << std::endl;
	taekkim2.signForm(form2);
	std::cout << form2 << std::endl;
	return (0);
}