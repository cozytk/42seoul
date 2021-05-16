#include "Conf.hpp"

/* node */
Conf::node &Conf::node::operator[](std::string const &name)
{
	if (children.find(name) == children.end())
	{
		//push(name);
	}
	return (children.find(name)->second);
}

std::vector<std::string> const &Conf::node::getValue() const
{
	return (this->value);
}

void Conf::node::setValue(std::string const &value)
{
	this->value.push_back(value);
}

/*
void Conf::node::push(std::string const &name, std::string const &value)
{
	node	dump;

	dump.value = value;
	children.insert(std::pair<std::string, node>(name, dump));
}*/

/* exception */
const char *Conf::ConfigSyntaxException::what() const throw()
{
	return ("ConfigSyntaxException: Syntax Error");
}

/* coplien form */
Conf::Conf()
{
	this->bracket = 0;
	this->cursor = syntax;
}

Conf::Conf(Conf const &x)
{
}

Conf::~Conf()
{
}

Conf &Conf::operator=(Conf const &x)
{
}

Conf::node &Conf::operator[](std::string const &name)
{
	if (children.find(name) == children.end())
	{
		//push(name);
	}
	return (children.find(name)->second);
}

void Conf::syntaxCursor(char c)
{
	if (this->cursor == syntax)
	{
		if (c == '\"')
			this->cursor = string;
		else if (c == '#')
			this->cursor = comment;
	}
	else if (this->cursor == escape)
	{
		if (c == '\"')
			this->cursor = string;
	}
	else if (this->cursor == string)
	{
		if (c == '\\')
			this->cursor = escape;
		else if (c == '\"')
			this->cursor = syntax;
	}
	else if (this->cursor == comment)
		if (c == '\n')
			this->cursor = syntax;
}

void Conf::syntaxProcess(std::vector<std::string> &v)
{
	std::vector<std::string>::iterator it = v.begin();
	std::cout << "syntax=> ";
	while (it != v.end())
		std::cout << "[" << *(it++) << "]" << " ";
	std::cout << std::endl;
}

void Conf::mapping(std::string const &line)
{
	std::vector<std::string> v;
	int i = 0;
	int start;

	while (i < line.length())
	{
		while (this->cursor == syntax && i < line.length() && isspace(line[i]))
			syntaxCursor(line[i++]);
		start = i;
		if (this->cursor == syntax)
		{
			while (this->cursor == syntax && i < line.length() && !isspace(line[i]))
				syntaxCursor(line[i++]);
			v.push_back(std::string(line, start, i - start) + std::to_string(this->cursor));
		}
		else if (this->cursor == string)
		{
			while ((this->cursor == escape || this->cursor == string)
					&& i < line.length())
				syntaxCursor(line[i++]);
	//		v.push_back(std::string(line, start, i - start) + std::to_string(this->cursor));
			v.push_back(std::string(line, start, i - start));
		}
		else if (this->cursor == comment)
			break ;
	}
	syntaxCursor('\n');
	syntaxProcess(v);
}

void Conf::file(std::string const &path)
{
	ConfigReader cr;
	int i = 0;

	cr.file(path);
	while (cr.exist(i))
		mapping(cr[i++]);
}

/*
void Conf::push(std::string const &name, std::string const &value)
{
	node	dump;

	dump.setValue(value);
	children.insert(std::pair<std::string, node>(name, dump));
}*/
