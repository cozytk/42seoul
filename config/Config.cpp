#include "Config.hpp"

/* node */
Config::node::node()
{
	value.clear();
	children.clear();
}

Config::node::node(node const &x)
{
}

Config::node::~node()
{
}

Config::node &Config::node::operator=(node const &x)
{
}

Config::node &Config::node::operator[](std::string const &name)
{
	if (children.find(name) == children.end())
	{
		node	dump;

		children.insert(std::pair<std::string, node>(name, dump));
	}
	return (children.find(name)->second);
}

std::vector<std::string> const &Config::node::getValue() const
{
	return (this->value);
}

void Config::node::setValue(std::vector<std::string> const &value)
{
	this->value = value;
}

/*
void Config::node::push(std::string const &name, std::string const &value)
{
	node	dump;

	dump.value = value;
	children.insert(std::pair<std::string, node>(name, dump));
}*/

/* exception */


/* coplien form */
Config::Config()
{
	this->cursor = syntax;
}

Config::Config(Config const &x)
{
}

Config::~Config()
{
}

Config &Config::operator=(Config const &x)
{
}

void Config::pushNode(std::string const &name, std::vector<std::string> &v)
{
}

void Config::parsing(std::vector<std::string>::iterator &first, std::vector<std::string>::iterator &last)
{
	if (*last == ";") // assign
		std::cout << "assign" << std::endl;
	else if (*last == "{") // into child, name is *first
		std::cout << "get child -> " << std::endl;
	else if (*last == "}") // back to parents
		std::cout << "get parents -> " << std::endl;
}

void Config::configTree()
{
	std::vector<std::string>::iterator first;
	std::vector<std::string>::iterator it = store.begin();

	while (it != store.end())
	{
		first = it;
		while (it != store.end() && *it != ";" && *it != "{" && *it != "}")
			it++;
		parsing(first, it);
		if (*it == ";" || *it == "{" || *it == "}")
			it++;
	}
}

void Config::syntaxCursor(char c)
{
	if (this->cursor == syntax)
	{
		if (c == '\"')
			this->cursor = string;
		else if (c == '#')
			this->cursor = comment;
	}
	else if (this->cursor == escape)
		this->cursor = string;
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

void Config::mapping(std::string const &line)
{
	std::vector<std::string> v;
	std::string buffer;
	int i = 0;
	int start;

	while (i < line.length())
	{
		buffer = "";
		while (i < line.length() && ft::isspace(line[i]))
			i++;
		if (i == line.length())
			break;
		syntaxCursor(line[i]);
		if (this->cursor == syntax)
		{
			while (i < line.length() && this->cursor == syntax && !ft::isspace(line[i]))
			{
				buffer += line[i++];
				syntaxCursor(line[i]);
			}
		}
		else if (this->cursor == string)
		{
			while (i < line.length())
			{
				if (this->cursor != escape)
					buffer += line[i];
				i++;
				syntaxCursor(line[i]);
				if (line[i] == '\"' && this->cursor == syntax)
				{
					i++;
					break;
				}
			}
			buffer.erase(buffer.begin());
		}
		else if (this->cursor == comment)
			break ;
		if (buffer[buffer.size() - 1] == ';')
		{
			buffer.erase(buffer.end() - 1);
			v.push_back(buffer);
			v.push_back(";");
		}
		else
			v.push_back(buffer);
	}
	syntaxCursor('\n');
	store.insert(store.end(), v.begin(), v.end());
}

void Config::file(std::string const &path)
{
	ConfigReader cr;
	ConfigSyntax cs;
	int i = 0;

	/* reset */
	// need to add node, root reset
	store.clear();
	this->cursor = syntax;
	/* load */
	cr.file(path);
	cs.syntax(cr);
	while (cr.exist(i))
		mapping(cr[i++]);
	/* tree */
	configTree();
}
