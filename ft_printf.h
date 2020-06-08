#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>

typedef	struct		s_fmt
{
	int		minus;
	int		zero;
	int		width;
	int		dot;
	int		len;
	int		ast;
	char	spec;
}					t_fmt;

static void		print_c(char *buff, va_list ap, t_fmt *fmt);
static void		print_d_i_u(char *buff, va_list ap, t_fmt *fmt);
static void		print_s(char *buff, va_list ap, t_fmt *fmt);
static void		print_p(char *buff, va_list ap, t_fmt *fmt);
static void		print_hex(char *buff, va_list ap, t_fmt *fmt);
static void		print_per(char *buff, va_list ap, t_fmt *fmt);
static void		init_fmt(t_fmt *fmt);
static int		ft_unvalid(char *base);
static void		ft_printing(long long nbr, char *base, int length);
static void		ft_putnbr_base(long long nbr, char *base);
static int		ft_intlen(long long num, int sign);
static char		*ft_itoa(long long n);
static int		con_per(char *f, va_list ap, t_fmt *fmt);
static int		find_per(va_list ap, char *f);
static int		is_spec(char c);
static int		find_spec(char *f);
static int		ft_printf(const char *fmt, ...);

#endif
