#ifndef CONF_HPP
# define CONF_HPP

# include <webserv.hpp>

# include "ConfigReader.hpp"
# include "ConfigSyntax.hpp"


class Config
{
	friend class ServerManager;
	friend class Server;
	friend class ParsedRequest;

private:
	/* node */
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

		int size(std::string name);
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

	/* tree */
	node& operator()(std::string const &name, int index = 0);
	int size(std::string name);

	/* new */
	void file(std::string const &path);
};

#endif
