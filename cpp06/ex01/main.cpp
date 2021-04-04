#include "serialize.hpp"

int	main()
{
	void	*ptr;
	Data	*data;

	srand(time(0));
	ptr = serialize();
	data = deserialize(ptr);
	std::cout << "deserialize :" << std::endl;
	std::cout << "s1 : " << data->s1 << std::endl;
	std::cout << "n : " << data->n << std::endl;
	std::cout << "s2 : " << data->s2 << std::endl;
	delete reinterpret_cast <Data *> (ptr);
	return (0);
}