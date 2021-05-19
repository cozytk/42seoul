#ifndef CONFIGSYNTAX_HPP
# define CONFIGSYNTAX_HPP

# include <iostream>
# include "ConfigReader.hpp"

class ConfigSyntax
{
private:
	int brackets;
	bool quotes; 
	
public:
	/* exception */
	class SyntaxException : public std::exception
	{
		virtual const char *what() const throw();
	};

	/* coplien form */
	ConfigSyntax();
	ConfigSyntax(ConfigSyntax const &x);
	~ConfigSyntax();

	ConfigSyntax &operator=(ConfigSyntax const &x);

	void syntax(ConfigReader &cr);
};

#endif
