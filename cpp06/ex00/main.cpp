#include "main.hpp"

int	main(int ac, char **av)
{
	std::string input;

	if (ac == 2)
	{
		input = av[1];
		if (is_char(input))
			print_char((int)input[0]);
		else if (is_int(input))
			print_int(atoi(input.c_str()));
		else if (is_float(input))
			print_float(atof(input.c_str()));
		else if (is_double(input))
			print_double(atof(input.c_str()));
		else if (input == "-inff" || input == "+inff" || input == "nanf"
		         || input == "-inf" || input == "+inf" || input == "nan")
			print_nan(input);
		else
			print_inv();
	}
	else
		return (1);
	return (0);
}
