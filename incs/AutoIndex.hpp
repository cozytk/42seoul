#ifndef AUTOINDEX_HPP
# define AUTOINDEX_HPP

# include <webserv.hpp>

class AutoIndex {
private:
	/* class */
	class File {
		friend class AutoIndex;

	private:
		/* static */
		static std::string units[6];

		/* enum */
		enum type {
			directory,
			symbolic,
			file
		};

		/* member */
		type _type;

		std::string _name;
		time_t _time;
		off_t _size;

	public:
		/* coplien */
		File();
		File(File const &x);
		~File();

		File &operator=(File const &x);

		std::string getSize();
	};

	/* member */
	std::vector<File> _directory;
	std::vector<File> _file;
	std::string _basepath;
	std::string _path;

	std::string _page[3];

public:
	/* exception */
	class DirectoryException : public std::exception {
		virtual const char *what() const throw();
	};

	class FileException : public std::exception {
		virtual const char *what() const throw();
	};

	/* coplien */
	AutoIndex();
	AutoIndex(AutoIndex const &x);
	~AutoIndex();

	AutoIndex &operator=(AutoIndex const &x);

	/* member */
	std::string getPwd();
	void newList(std::string const &path, std::string const &filename);
	void path(std::string const &path);

	std::string make();
};

#endif
