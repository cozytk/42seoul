#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int main()
{
	ZombieEvent heap;
	Zombie *a;
	Zombie *b;

	heap.setZombieType("heap");
	a = heap.newZombie("Gam");
	a->announce();
	b = heap.randomChump();
	delete a;
	std::cout << "delete dynamic memory" << std::endl;
	delete b;
	std::cout << "delete dynamic memory" << std::endl;
	return (0);
}