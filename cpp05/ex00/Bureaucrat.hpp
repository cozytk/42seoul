#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
		Bureaucrat();

	public:
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat& operator=(const Bureaucrat& obj);
		virtual ~Bureaucrat();

		class
		void GradeTooHighException();
		void GradeTooLowException();

		/* declare member function */
};

/* global operator overload */
std::ostream&	operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif
