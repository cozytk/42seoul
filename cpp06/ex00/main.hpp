#ifndef MAIN_HPP
# define MAIN_HPP

# include <iostream>
# include <cstdlib>

int		is_char(std::string input);
int		is_int(std::string input);
int		is_float(std::string input);
int		is_double(std::string input);

void	print_char(char c);
void	print_int(int n);
void	print_float(float f);
void	print_double(double d);
void	print_nan(std::string nan);
void	print_inv(void);

#endif
