#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>

typedef	struct		s_fmt
{
	int	    	minus;
	int	    	zero;
	int	    	width;
	int		    dot;
	int		    len;
	int	    	ast;
	int         minus_w;
	int         digit;
	int         res;
	int         s_len;
	char        spec;
	char        *str;
	long long   num;
	va_list     cp;
}					t_fmt;

static int      print_minus_w(t_fmt *fmt);
static int		print_c(const char *buff, va_list ap, t_fmt *fmt);
static int		print_d_i(const char *buff, va_list ap, t_fmt *fmt);
static int		print_u(const char *buff, va_list ap, t_fmt *fmt);
static int		print_s(char *buff, va_list ap, t_fmt *fmt);
static int		print_p(const char *buff, va_list ap, t_fmt *fmt);
static int		print_hex(const char *buff, va_list ap, t_fmt *fmt);
static int		print_per(const char *buff, va_list ap, t_fmt *fmt);
static void		init_fmt(t_fmt *fmt);
static int		ft_unvalid(const char *base);
static int		ft_printing(long long nbr, char *base, int length);
static int		ft_putnbr_base(long long nbr, char *base);
static int		ft_intlen(long long num, int sign);
static char		*ft_itoa(long long n);
static int		con_per(char *f, va_list ap, t_fmt *fmt);
static int		sort_spec(char *buff, va_list ap, t_fmt *fmt);
static int      con_width_s(t_fmt *fmt);
static int		find_per(va_list ap, char *f);
static int		is_spec(char c);
static int		find_spec(char *f);
static int		minus_zero(char *s, t_fmt *fmt);
static int		ast_dot(char *buff, t_fmt *fmt);
static int      con_ast_pos(char *buff, t_fmt *fmt, int i);
static int		width_len(char *buff, t_fmt *fmt);
static int		set_fmt(char *buff, t_fmt *fmt);
static int      con_ast(va_list ap, t_fmt *fmt);
static int		ft_printf(const char *fmt, ...);
static int		ft_isdigit(int c);
static size_t	ft_strlen(const char *s);
static int		ft_atoi(char *buff, t_fmt *fmt);
static char		*ft_strndup(const char *s1, size_t n);

#endif
