#include "../incs/Stack.hpp"
#include <stack>


template <typename T>
void print_stack(std::stack<T> stk)
{
	if (stk.empty())
	{
		std::cout << "It's empty stack\n";
		return ;
	}
	while (!stk.empty())
	{
		std::cout << stk.top() << ' ';
		stk.pop();
	}
	std::cout << "\n";
}

template <typename T>
void print_stack(ft::stack<T> stk)
{
	/*
	 * empty
	 */
	if (stk.empty())
	{
		std::cout << "It's empty stack ft\n";
		return;
	}
	/*
	 * top, pop
	 */
	while (!stk.empty())
	{
		std::cout << stk.top() << ' ';
		stk.pop();
	}
	std::cout << "ft \n";
}

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
}

