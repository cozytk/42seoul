#include <iostream>
#include <string>
#include <fstream>

int	main(int argc, char **argv)
{
	std::ofstream	fdest;
	std::ifstream	fsrc;
	std::string		filename;
	std::string		line;
	std::string		dest;
	std::string		src;
	std::size_t		pos;

	if (argc !=4)
	{
		std::cout<<"./replace [file] [src] [dest]\n";
		return (-1);
	}
	filename = argv[1];
	dest = argv[2];
	src = argv[3];
	fsrc.open(filename);
	filename.append(".replace");
	fdest.open(filename);
	if (!fsrc.is_open() || !fdest.is_open())
	{
		std::cout << "Error : wrong file\n";
		return (-1);
	}
	while (std::getline(fsrc, line))
	{
		pos = 0;
		while ((pos = line.find(dest, pos)) != std::string::npos)
		{
			line.replace(pos, dest.length(), src);
			pos += src.length();
		}
		fdest << line;
		if (!fsrc.eof())
			fdest << std::endl;
	}
	fsrc.close();
	fdest.close();
	return (0);
}

