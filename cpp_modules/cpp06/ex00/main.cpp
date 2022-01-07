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
			print_int(stoi(input));
		else if (is_float(input))
			print_float(stof(input));
		else if (is_double(input))
			print_double(stod(input));
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
