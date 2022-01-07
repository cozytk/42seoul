#include <iostream>

#include <Queue.hpp>
#include <queue>

template <typename T>
void print_queue(std::queue<T> que)
{
	if (que.empty())
	{
		std::cout << "It's empty queue\n";
		return ;
	}
	while (!que.empty())
	{
		std::cout << que.front() << ' ';
		que.pop();
	}
	std::cout << "\n";
}
template <typename T>
void print_queue(ft::queue<T> que)
{
	/*
	 * empty, front, pop
	 */
	if (que.empty())
	{
		std::cout << "It's empty queue ft\n";
		return ;
	}
	while (!que.empty())
	{
		std::cout << que.front() << ' ';
		que.pop();
	}
	std::cout << " ft\n";
}

int main()
{
	/*
	 * constructor
	 */
	std::queue<int>que;
	ft::queue<int>ftque;

	print_queue(que);
	print_queue(ftque);
	/*
	 * push, size
	 */
	for (int i = 0; i < 5; i++)
		que.push(i);
	for (int i = 0; i < 5; i++)
		ftque.push(i);
	print_queue(que);
	print_queue(ftque);
	std::cout << "size is \n";
	std::cout << que.size() << std::endl;
	std::cout << ftque.size() << " ft" <<  std::endl;
	std::cout << "back - front \n";
	std::cout << que.back() - que.front() << std::endl;
	std::cout << ftque.back() - ftque.front() << " ft" <<  std::endl;
	/*
	 * boold operator
	 */
	ft::queue<int>otherftque;
	for (int i = 0; i < 5; i++) otherftque.push(i);
	if (otherftque == ftque)
		std::cout << "==  ";
	ftque.push(42);
	que.push(42);
	if (ftque >= otherftque)
		std::cout << "!=  ";
	if (otherftque < ftque)
		std::cout << "<  ";
	if (otherftque < ftque)
		std::cout << "<=  ";
	otherftque.push(42);
	if (otherftque >= ftque)
		std::cout << ">= ";
	otherftque.push(24);
	if (otherftque > ftque)
		std::cout << ">  ";
	return (0);
}
