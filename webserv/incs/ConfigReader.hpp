#ifndef CONFIGREADER_HPP
# define CONFIGREADER_HPP

# include <webserv.hpp>

class ConfigReader
{
private:
	std::vector<std::string> line;

	void split(std::string &content);

public:
	/* exception */
	class FileNotFoundException : public std::exception
	{
		virtual const char *what() const throw();
	};

	/* coplien form */
	ConfigReader();
	ConfigReader(ConfigReader const &x);
	~ConfigReader();

	ConfigReader &operator=(ConfigReader const &x);
	std::string &operator[](int l);

	void file(std::string const &path);
	bool exist(int i);
};

#endif
