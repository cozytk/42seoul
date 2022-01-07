#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Base
{
	public:
		virtual ~Base() {};
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base	*generate()
{
	int num = std::rand() % 3;

	if (num == 0)
		return (new A);
	else if (num == 1)
		return (new B);
	else
		return (new C);
}

void identify_from_pointer(Base *p)
{
	if (dynamic_cast <A *> (p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast <B *> (p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast <C *> (p))
		std::cout << "C" << std::endl;
}

void identify_from_reference(Base &p)
{
	if (dynamic_cast <A *> (&p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast <B *> (&p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast <C *> (&p))
		std::cout << "C" << std::endl;
}

int	main()
{
	std::srand(std::time(0));

	std::cout << "Generating random pointer" << std::endl;
	Base *randomBase = generate();
	std::cout << "Identify from pointer: ";
	identify_from_pointer(randomBase);
	std::cout << "Identify from reference: ";
	identify_from_reference(*randomBase);
	delete randomBase;
}