#ifndef CONF_HPP
# define CONF_HPP

# include <iostream>
# include <vector>
# include <map>

# include "ConfigReader.hpp"
# include "ConfigSyntax.hpp"
# include "../utils/utils.hpp"

class Config
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

	enum Cursor
	{
		syntax,
		escape,
		string,
		comment
	};

	std::map<std::string, node> children;
	Cursor cursor;

	void syntaxCursor(char c);
	void syntaxProcess(std::vector<std::string> &v);
	
public:
	/* exception */

	/* coplien form */
	Config();
	Config(Config const &x);
	~Config();
	
	Config &operator=(Config const &x);
	node &operator[](std::string const &name);

	/* new */
	void file(std::string const &path);
	void mapping(std::string const &line);
};

#endif
