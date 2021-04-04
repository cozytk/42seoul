#include "serialize.hpp"

void	*serialize(void)
{
	std::string		s1;
	std::string		s2;
	int				n = rand();
	std::string		chars = "abcdefghijklmnopqrstuvwxyz0123456789";
	Data			*data = new Data;

	for ( int i = 0 ; i < 8 ; i++ )
	{
		s1 += chars[rand() % 36];
		s2 += chars[rand() % 36];
	}
	data->s1 = s1;
	data->n = n;
	data->s2 = s2;

	std::cout << "serialize :" << std::endl;
	std::cout << "s1 : " << data->s1 << std::endl;
	std::cout << "n : " << data->n << std::endl;
	std::cout << "s2 : " << data->s2 << std::endl;

	return (reinterpret_cast <void *> (data));
}

Data	*deserialize(void *ptr)
{
	return (reinterpret_cast <Data *> (ptr));
}
