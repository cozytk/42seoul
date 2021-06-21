#include <iostream>
#include <string>

int main()
{
	std::string s1;
	s1.reserve(100);
	std::cout << s1.capacity() << std::endl;
    std::string &s2 = s1;
    s2 = "";
    std::cout << s2.capacity() << std::endl;
}
//
// Created by Taekyun Kim on 6/16/21.
//

