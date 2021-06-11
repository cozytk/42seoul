#include "../incs/Stack.hpp"
#include <stack>

int main()
{
	/*
	 * constructor
	 */
	std::stack<int> stdstk;
	ft::stack<int> ftstk;
	ft::stack<int> otherftstk;

	print_stack(stdstk);
	print_stack(ftstk);

	/*
	 * push, size
	 */
	for (int i = 0; i < 5; i++) stdstk.push(i);
	for (int i = 0; i < 5; i++) ftstk.push(i);

	print_stack(stdstk);
	print_stack(ftstk);

	std::cout << "size is \n";
	std::cout << stdstk.size() << std::endl;
	std::cout << ftstk.size() << " ft" << std::endl;

	for (int i = 0; i < 5; i++) otherftstk.push(i);

	if (otherftstk == ftstk)
		std::cout << "==  ";
	ftstk.push(42);
	if (ftstk >= otherftstk)
		std::cout << "!=  ";
	if (otherftstk < ftstk)
		std::cout << "<  ";
	if (otherftstk < ftstk)
		std::cout << "<=  ";
	ftstk.pop();
	ftstk.pop();
	if (otherftstk > ftstk)
		std::cout << ">  ";
	if (otherftstk > ftstk)
		std::cout << ">=";

	return (0);
}//
// Created by Taekyun Kim on 6/11/21.
//

