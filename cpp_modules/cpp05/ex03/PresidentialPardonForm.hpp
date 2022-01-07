#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include <string>
# include <iostream>

# include "Form.hpp"

class PresidentialPardonForm : public Form
{
	private:
		PresidentialPardonForm();
	public:
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& copy);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& obj);
		virtual ~PresidentialPardonForm();

		void action(void) const;
};

#endif
