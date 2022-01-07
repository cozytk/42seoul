#ifndef SHRUBBERRY_CREATION_FORM_HPP
# define SHRUBBERRY_CREATION_FORM_HPP

# include <string>
# include <iostream>
# include <fstream>

# include "Form.hpp"

class ShrubberryCreationForm : public Form
{
	private:
		ShrubberryCreationForm();
	public:
		ShrubberryCreationForm(const std::string& target);
		ShrubberryCreationForm(const ShrubberryCreationForm& copy);

		ShrubberryCreationForm& operator=(const ShrubberryCreationForm& obj);
		virtual ~ShrubberryCreationForm();

		void action(void) const;
};

#endif
