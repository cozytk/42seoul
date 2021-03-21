#include <iostream>
#include <string>
#include <fstream>

int		main(int argc, char **argv)
{
	std::ifstream	ifs;
	std::ofstream	ofs;
	std::string		file;
	std::string		line;
	std::string		s1;
	std::string		s2;
	std::string::size_type pos;

	if (argc !=4)  // 인자로 파일이름, 문자열 두개가 들어오지 않으면
	{
		std::cout<<"Error : wrong argument\n";
		return (-1);
	}
	file = argv[1];  //파일 이름
	s1=argv[2];  // 첫번째 문자열
	s2=argv[3];  // 두번째 문자열
	ifs.open(file);  // 읽을 파일 열기
	file += ".replace";  // 파일이름 수정
	ofs.open(file);  // 출력할 파일 열기
	if (!ifs.is_open() || !ofs.is_open())  // 둘중에 하나라도 파일이 안열렸다면
	{
		std::cout<<"Error : wrong file name\n";
		return (-1);
	}
	while (getline(ifs, line))  // 한줄씩 파일 읽기
	{
		while (true)
		{
			pos = line.find(s1);  // 한줄읽은 line에 문자열이 s1 있는 위치찾기
			if (pos == std::string::npos)  // line에 s1 문자열이 없으면
				break ;
			line.replace(pos, s1.length(), s2);  // s1의 문자열을 s2로 변경
		}
		ofs<<line;  // 변경된 문자열 출력할 파일에 넣기
		if (!ifs.eof())  // 읽을 파일을 다 안읽었다면
			ofs<<'\n';  // 출력할 파일에 개행추가
	}
	ifs.close();  // 읽을 파일 닫기
	ofs.close();  // 출력할 파일 닫기
	return (0);
}