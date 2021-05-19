#ifndef CONF_HPP
# define CONF_HPP

# include <iostream>
# include <vector>
# include <map>
# include <stack>

# include "ConfigReader.hpp"
# include "ConfigSyntax.hpp"
# include "../utils/utils.hpp"

class Config
{
private:
	class node
	{
	private:
		std::vector<std::string> value;
		std::multimap<std::string, node *> children;

	public:
		node();
		node(node const &x);
		~node();

		node &operator=(node const &x);
		node &operator()(std::string name, int index = 0);
		std::vector<std::string> &operator*();
		std::multimap<std::string, node *> &getChildren();
	};

	enum Cursor
	{
		syntax,
		escape,
		string,
		comment
	};

	/* tree */
	node *root;

	void parsing(std::vector<std::string>::iterator f, std::vector<std::string>::iterator l);
	void configTree();

	/* parse */
	std::vector<std::string> store;
	std::stack<node *> brackets;
	Cursor cursor;

	void syntaxCursor(char c);
	void mapping(std::string const &line);

public:
	/* exception */
	class OutOfBoundsException : public std::exception
	{
		virtual const char *what() const throw();
	};

	/* coplien form */
	Config();
	Config(Config const &x);
	~Config();
	
	Config &operator=(Config const &x);
	node& operator()(std::string const &name, int index = 0);

	/* new */
	void file(std::string const &path);
};

#endif
