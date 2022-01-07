# include "ConfigSyntax.hpp"
# include "ConfigReader.hpp"

/* exception */
const char *ConfigSyntax::SyntaxException::what() const throw()
{
	return ("SyntaxException: Syntax Error");
}

/* coplien form */
ConfigSyntax::ConfigSyntax()
{
	this->brackets = 0;
	this->quotes = false;
}

ConfigSyntax::ConfigSyntax(ConfigSyntax const &x)
{
}

ConfigSyntax::~ConfigSyntax()
{
}

ConfigSyntax &ConfigSyntax::operator=(ConfigSyntax const &x)
{
	return (*this);
}

void ConfigSyntax::syntax(ConfigReader &cr)
{
	int j;

	/* reset */
	this->brackets = 0;
	this->quotes = false;
	/* check */
	j = 0;
	while (cr.exist(j))
	{
		for (int i = 0; i < cr[j].length(); i++)
		{
			if (cr[j][i] == '\"')
			{
				if (i == 0 || (i > 0 && cr[j][i - 1] != '\\'))
					this->quotes = !this->quotes;
			}
			if (!this->quotes && cr[j][i] == '{')
				++this->brackets;
			if (!this->quotes && cr[j][i] == '}')
				--this->brackets;
		}
		j++;
	}
	if (this->quotes || this->brackets != 0)
		throw SyntaxException();
}
