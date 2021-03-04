#include "phonebook.h"

int main(void)
{
	int i = 0;
	int k;
	Phonebook phonebook[8];
	std::string cmd;

	while (i <= 8)
	{
		std::cout << "you should accept the ADD command, the SEARCH command or the EXIT command." << std::endl;
		std::cin >> cmd;
		if (cmd.compare("EXIT") == SAME)
		{
			std::cout << "---------- EXITED ----------" << std::endl;
			return (0);
		}
		else if (cmd.compare("ADD") == SAME)
		{
			if (i == 8)
			{
				std::cout << "----------------- TOO_MANY_CONTACTS -------------\n";
				continue ;
			}
			phonebook[i].get_info(i);
			std::cout << "----------- " << i + 1 << " ADDED SUCCESS --------------" << std::endl;
			i++;
		}
		else if (cmd.compare("SEARCH") == SAME)
		{
			if (!i)
			{
				std::cout << "--------------- NOTHING_TO_SEARCH ----------------" << std::endl;
				continue ;
			}
			for (int j = 0; j < i; j++)
			{
				std::cout << "------------" << std::endl;
				phonebook[j].display();
				std::cout << "------------" << std::endl;
			}
			std::cout << "ENTER THE INDEX\n";
			std::cin >> k;
			if (k > i)
			{
				std::cout << "-----------Wrong Index----------------\n";
				continue ;
			}
			phonebook[k - 1].search();
		}
		else
			std::cout << "not a valid command." << std::endl;
	}
	return (0);
}
