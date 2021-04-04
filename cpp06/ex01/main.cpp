#include "serialize.hpp"

int	main()
{
	void	*ptr;
	Data	*data;

	srand(time(0));

	ptr = serialize();
	data = deserialize(ptr);

	std::cout << "Data translates to :" << std::endl;
	std::cout << "s1 : " << data->s1 << std::endl;
	std::cout << "n : " << data->n << std::endl;
	std::cout << "s2 : " << data->s2 << std::endl;

	delete data;
	delete reinterpret_cast <Data *> (ptr);

	while (1)
		;

	return (0);
}
