# include "AutoIndex.hpp"

/* File */ /* static */
std::string AutoIndex::File::units[6] = {"B", "KB", "MB", "GB", "TB", "Ex"};

/* coplien */
AutoIndex::File::File() {
}

AutoIndex::File::File(File const &x) :
	_type(x._type), _name(x._name), _time(x._time), _size(x._size) {
}

AutoIndex::File::~File() {
}

AutoIndex::File &AutoIndex::File::operator=(File const &x) {
	this->_type = x._type;
	this->_name = x._name;
	this->_time = x._time;
	this->_size = x._size;
	return (*this);
}

std::string AutoIndex::File::getSize() {
	long psize;
	long size;
	int unit_count;

	psize = 0;
	size = this->_size;
	unit_count = -1;
	while (size) {
		++unit_count;
		psize = size;
		size /= 1000;
	}
	return (ft::to_string(psize) + " " + units[unit_count]);
}

/* Auto Index */
/* exception */
const char *AutoIndex::DirectoryException::what() const throw() {
	return ("AutoIndexException: Failed to open directory");
}

const char *AutoIndex::FileException::what() const throw() {
	return ("AutoIndexException: Failed to open file");
}

/* coplien */
AutoIndex::AutoIndex() {
	std::string buffer = "";
	char buf[2048];
	int auto_fd;
	int len;

	if ((auto_fd = open("srcs/AutoIndex.html", O_RDONLY)) < 0)
		throw FileException();
	while ((len = read(auto_fd, buf, 2047)) > 0) {
		buf[len] = 0;
		buffer += buf;
	}
	if (len == -1)
		throw FileException();	
	buf[len] = 0;
	buffer += buf;
	close(auto_fd);
	this->_page[0] = std::string(buffer.begin(), buffer.begin() + 558);
	this->_page[1] = std::string(buffer.begin() + 558, buffer.begin() + 933);
	this->_page[2] = std::string(buffer.begin() + 933, buffer.end());
}

AutoIndex::AutoIndex(AutoIndex const &x) {
}

AutoIndex::~AutoIndex() {
}

AutoIndex &AutoIndex::operator=(AutoIndex const &x) {
	return (*this);
}

std::string AutoIndex::getPwd() {
	char buf[2048];
	getcwd(buf, 2047);
	return (std::string(buf));
}

void AutoIndex::newList(std::string const &path, std::string const &filename) {
	struct stat buf;
	File file;

	if (lstat((path + filename).c_str(), &buf) == -1)
		throw FileException();
	switch (buf.st_mode & S_IFMT) {
		case S_IFDIR:
			file._type = File::directory; break ;
		case S_IFLNK:
			file._type = File::symbolic; break ;
		default:
			file._type = File::file; break ;
	}
	file._name = filename;
	file._time = buf.st_mtime;
	file._size = buf.st_size;
	if (file._type == File::directory)
		this->_directory.push_back(file);
	else
		this->_file.push_back(file);
}

void AutoIndex::path(std::string const &path) {
	DIR *dir_info = NULL;
	dirent *file = NULL;

	this->_basepath = getPwd();
	this->_path = path;
	if((dir_info = opendir((this->_basepath + this->_path).c_str())) == NULL)
		throw DirectoryException();
	while((file = readdir(dir_info)) != NULL)
		newList(this->_basepath + this->_path, std::string(file->d_name));
	closedir(dir_info);
}

std::string AutoIndex::make() {
	std::vector<File>::iterator it;
	std::string page = this->_page[0];

	page += "Index of " + this->_path;
	page += this->_page[1];
	page += "path: \'" + this->_path + "\',\n";
	page += "index: [\n";
	for (it = _directory.begin(); it != _directory.end(); it++)
		page += ("{ name: \"" + it->_name +
				"/\", time: \"" + std::string(ctime(&it->_time), 0, 24) +
				"\", size: \"-" +
				"\", link: \"" + this->_path + it->_name + "\" },\n");
	for (it = _file.begin(); it != _file.end(); it++)
		page += ("{ name: \"" + it->_name +
				"\", time: \"" + std::string(ctime(&it->_time), 0, 24) +
				"\", size: \"" + it->getSize() +
				"\", link: \"" + this->_path + it->_name + "\" },\n");
	page += "]\n";
	page += this->_page[2];
	return (page);
}
