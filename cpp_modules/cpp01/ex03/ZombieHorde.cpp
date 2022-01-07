#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int N)
{
	int i = 0;
	std::string names[4] = {"GUN", "GON", "GAM", "LEE"};

	zombieHorde = new Zombie[N];
	std::srand(std::time(0));
	while (i++ < N)
		zombieHorde[i].setZombie(names[std::rand() % 4], "TYPE");
	i = 0;
	while (i++ < N)
		zombieHorde[i].announce();
}

ZombieHorde::~ZombieHorde()
{
	std::cout << "ZombieHorde Destroyed, Release zombieHorde\n";
	delete[] zombieHorde;
}