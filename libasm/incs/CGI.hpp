#ifndef CGI_HPP
# define CGI_HPP

# include <ParsedRequest.hpp>
# include <webserv.hpp>

class CGI {
private:
	std::map<std::string, std::string> envs;
	std::string _buffer;

	int _stdin;
	int _stdout;
public:
	/* exception */
	class FileIOException : public std::exception {
		virtual const char *what() const throw();
	};

	class ForkException : public std::exception {
		virtual const char *what() const throw();
	};

	/* coplien */
	CGI();
	CGI(CGI const &x);
	~CGI();
	
	CGI &operator=(CGI const &x);

	void setEnvs(ParsedRequest *request);
	char **getEnvs(ParsedRequest *request);
	void execute(ParsedRequest *reqeust);

	std::string &getBuffer();
};

#endif
