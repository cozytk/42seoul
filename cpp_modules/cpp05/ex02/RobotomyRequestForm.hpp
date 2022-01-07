#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include <string>
# include <iostream>

# include "Form.hpp"

class RobotomyRequestForm : public Form
{
	private:
		RobotomyRequestForm();
	public:
		RobotomyRequestForm(const std::string & target);
		RobotomyRequestForm(const RobotomyRequestForm& copy);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);
		virtual ~RobotomyRequestForm();

		void action(void) const;
};

#endif
