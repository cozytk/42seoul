#include "Brain.hpp"
#include "Human.hpp"

/*
 * https://modoocode.com/197 상수 멤버 함수에 대한 설명
 */

int main()
{
	Human	bob;

	std::cout << bob.identify() << std::endl;
	std::cout << bob.getBrain().identify() << std::endl;
}