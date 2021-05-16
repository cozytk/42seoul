#ifndef CONF_HPP
# define CONF_HPP

# include <iostream>
# include <vector>
# include <map>

# include "ConfigReader.hpp"
# include "../utils/utils.hpp"

class Conf
{
private:
	class node // add coplien
	{
	private:
		std::vector<std::string> value;
		std::map<std::string, node> children;

	public:
		node &operator[](std::string const &name);

		std::vector<std::string> const &getValue() const;
		void setValue(std::string const &value);

		//node &operator[](std::string const &name);
		// operator << + ..?
	};

	std::map<std::string, node> children;

	enum Cursor
	{
		syntax,
		escape,
		string,
		comment
	};

	int bracket;
	Cursor cursor;

	void syntaxCursor(char c);
	void syntaxProcess(std::vector<std::string> &v);
	
public:
	/* exception */
	class ConfigSyntaxException : public std::exception
	{
		virtual const char *what() const throw();
	};

	/* coplien form */
	Conf();
	Conf(Conf const &x);
	~Conf();
	
	Conf &operator=(Conf const &x);
	node &operator[](std::string const &name);

	/* new */
	void file(std::string const &path);
	void mapping(std::string const &line);
};

#endif
