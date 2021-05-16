#include "ConfigReader.hpp"

/* exception */
const char *ConfigReader::FileNotFoundException::what() const throw()
{
	return ("FileNotFoundException: file dose not exist");
}

/* coplien form */
ConfigReader::ConfigReader()
{
}

ConfigReader::ConfigReader(ConfigReader const &x)
{
}

ConfigReader::~ConfigReader()
{
}

ConfigReader &ConfigReader::operator=(ConfigReader const &x)
{
}

std::string &ConfigReader::operator[](int l)
{
	return (line[l]);
}

void ConfigReader::split(std::string &content)
{
	int start;

	for (int i = 0; i < content.length(); i++)
	{
		start = i;
		while (i < content.length() && content[i] != '\n')
			i++;
		line.push_back(std::string(content, start, i - start));
	}
}

void ConfigReader::file(std::string const &path)
{
	std::string content;
	char buf[129];
	int bytes;
	int	fd;

	/* set */
	line.clear();
	
	/* read */
	if ((fd = open(path.c_str(), O_RDONLY)) == -1)
		throw FileNotFoundException();
	while ((bytes = read(fd, buf, 128)) > 0)
	{
		buf[bytes] = 0;
		content += buf;
	}
	split(content);
}

bool ConfigReader::exist(int i)
{
	if (line.size() <= i)
		return (false);
	return (true);
}
