#include "Pony.hpp"

void ponyOnTheHeap()
{
	std::cout << "Pony on heap allocate\n";
	Pony *a = new Pony("heap", 3);
	a->print();
	delete a;
	std::cout << "Pony on heap delete\n";
}

void ponyOnTheStack()
{
	std::cout << "Pony on stack allocate\n";
	Pony b = Pony("stack", 5);
	b.print();
	std::cout << "Pony on stack died\n";
}

int main()
{
	ponyOnTheHeap();
	ponyOnTheStack();
}