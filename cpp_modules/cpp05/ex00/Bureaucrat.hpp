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
		Bureaucrat(const std::string &_name, int _grade);
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat& operator=(const Bureaucrat& obj);
		virtual ~Bureaucrat();

		std::string getName() const;
		int getGrade() const;
		void incGrade();
		void decGrade();

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
};

/* global operator overload */
std::ostream&	operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif
