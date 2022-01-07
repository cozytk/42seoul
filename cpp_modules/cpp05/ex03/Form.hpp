#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _signed;
		const int _signGrade;
		const int _execGrade;
		std::string _target;
		Form();

	public:
		Form(const std::string& name, const int signGrade, const int execGrade);
		Form(const Form& copy);
		Form& operator=(const Form& obj);
		virtual ~Form();
		std::string getName() const;
		bool getSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;
		std::string getTarget() const;
		void setTarget(std::string target);
		void beSigned(Bureaucrat & obj);
		void execute(Bureaucrat const & executor) const;
		virtual void action(void) const	= 0;

		class GradeTooHighException : public std::runtime_error
		{
			public:
				GradeTooHighException() : std::runtime_error("Grade Too High.") {}
		};
		class GradeTooLowException : public std::runtime_error
		{
			public:
				GradeTooLowException() : std::runtime_error("Grade Too Low.") {}
		};
		class FormNotSignedException : public std::runtime_error
		{
			public:
				FormNotSignedException() : std::runtime_error("Form Not Signed.") {}
		};
};

std::ostream&	operator<<(std::ostream& out, const Form& form);

#endif
