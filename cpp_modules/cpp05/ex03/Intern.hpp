#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"
# include "Form.hpp"
# include "ShrubberryCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern& copy);
		Intern& operator=(const Intern& obj);
		virtual ~Intern();

		Form *makeForm(std::string form, std::string target);
};

#endif
