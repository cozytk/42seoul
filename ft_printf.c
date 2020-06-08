/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekkim <taekkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 19:54:25 by taekkim           #+#    #+#             */
/*   Updated: 2020/06/09 05:46:47 by taekkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static size_t	ft_strlen(const char *s)
{
	size_t length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

static int		ft_atoi(const char *nptr)
{
	int			sign;
	int			result;

	sign = 1;
	result = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
		result = result * 10 + *nptr++ - '0';
	return (result * sign);
}

static char		*ft_strndup(const char *s1, size_t n)
{
	char	*p;
	size_t	i;

	i = 0;
	if (!(p = (char *)malloc(ft_strlen(s1) + 1)))
		return (0);
	while (s1 && s1[i] && i < n)
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}


static char		*ft_strdup(const char *s1)
{
	char	*p;
	int		i;

	i = 0;
	if (!(p = (char *)malloc(ft_strlen(s1) + 1)))
		return (0);
	while (s1 && s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

static void		init_fmt(t_fmt	*fmt)
{
	fmt->minus = 0;
	fmt->zero = 0;
	fmt->width = 0;
	fmt->dot = -1;
	fmt->len = 0;
	fmt->ast = 0;
	fmt->ast_pos = 0;
	fmt->spec = 0;
}

static int		ft_unvalid(char *base)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (i);
}

static int		ft_printing(long long nbr, char *base, int length)
{
	long long nb;

	nb = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nb = nbr * -1;
	}
	else
		nb = nbr;
	if (nb >= (long long)length)
	{
		ft_printing(nb / length, base, length);
		ft_printing(nb % length, base, length);
	}
	if (nb < (long long)length)
		write(1, &base[nb % length], 1);
}

static int		ft_putnbr_base(long long nbr, char *base)
{
	int length;

	length = ft_unvalid(base);
	if (length == 0)
		return ;
	ft_printing(nbr, base, length);
}

static int		ft_intlen(long long num, int sign)
{
	long long len;

	len = 1;
	while (num >= 10)
	{
		len++;
		num = num / 10;
	}
	if (sign == -1)
		len++;
	return (len);
}

static char		*ft_itoa(long long n)
{
	char		*arr;
	int			sign;
	int			len;
	long long	num;

	sign = n >= 0 ? 1 : -1;
	num = (long long)n;
	if (num < 0)
		num = -num;
	len = ft_intlen(num, sign);
	if (!(arr = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	arr[len] = '\0';
	if (num == 0)
		arr[0] = '0';
	while (num > 0)
	{
		arr[--len] = num % 10 + '0';
		num = num / 10;
	}
	if (sign == -1)
		arr[0] = '-';
	return (arr);
}

static void		minus_zero(char c, t_fmt *fmt)
{
	if ((c == '-' || c == '0'))
	{
		if (c == '-')
			fmt->minus = 1;
		else if (c == '0')
			fmt->zero = 1;
		return (1);
	}
	return (0);
}

static int		is_vaild_ast(char *buff, int i)
{
	if (i == 0)
		return (1);
	else if (buff[i - 1] == '.')
		return (1);
	return (0);
}

static int		ast_dot(char *buff, t_fmt *fmt)
{
	int i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '*')
		{
			if (!(is_valid_ast(buff, i)) || fmt->ast > 1)
				return (0);
			(fmt->ast)++;
		}
		else if (buff[i] == '.')
		{
			if (fmt->dot != -1)
				return (0);
			fmt->dot = i;
		} 
		else if (!(is_digit(buff[i])))
			return (0);
		i++;
	}
	fmt->dot = 0;
	return (1);
}

static int		num_ast(char *buff)

static int		width_len(char *buff, t_fmt *fmt)
{
	char	*width;
	char	*len;

	if (!(fmt->dot))
		width = ft_strdup(buff);
	else if (fmt->ast == 2 && fmt->dot == 1)
		return (1);
	else if (fmt->ast == 1 && fmt->dot == 1)
	{
		if (fmt->ast_pos == 1)
			fmt->width = 0;
		else if (fmt->ast_pos == 10)
			width = ft_strndup(buff, 
		len = ft_strdup(buff + fmt->dot + 1);
	if (!(fmt->width = ft_atoi(width)))
		return (0);
	if (!(fmt->len = ft_atoi(len)))
		return (0);
	return (1);
}

static int		set_ast_pos(char *str)
{
	int		len;

	len = strlen(str);
	if (str[i] == '*')
		return (10);
	else if (str[len - i] == '*')
		return (1);
	else
		return (-1)
}

static int		set_fmt(char *buff, t_fmt *fmt)
{
	if (minus_zero(buff[0], fmt))
		buff++;
	if (!(ast_dot(buff, fmt)))
		return (0);
	if (fmt->ast == 1)
		if ((fmt->ast_pos = set_ast_pos(buff)) < 0)
			return (0);
	if (!(width_len(buff, fmt)))
		return (0);
	return (1);
}

static int		print_s(char *buff, va_list ap, t_fmt *fmt)
{
	char *str;

	if (fmt->star)

	str = va_arg(ap, char *);
	write(1, str, strlen(str));
	(void)buff;
	(void)fmt;
}

static int		print_d_i_u(char *buff, va_list ap, t_fmt *fmt)
{
	long long num;
	char *str;

	if (fmt->spec == 'u')
		num = va_arg(ap, unsigned int);
	else
		num = va_arg(ap, int);
	str = ft_itoa(num);
	write(1, str, strlen(str));
	free(str);
	(void)buff;
	(void)fmt;
}
	
static int		print_c(char *buff, va_list ap, t_fmt *fmt)
{
	char chr;

	chr = va_arg(ap, int);
	write(1, &chr, 1);
	(void)buff;
	(void)fmt;
}
	
static int		print_p(char *buff, va_list ap, t_fmt *fmt)
{
	unsigned long	n;

	n = va_arg(ap, unsigned long);
	write(1, "0x", 2);
	ft_putnbr_base(n, "0123456789abcdef");
	(void)buff;
	(void)fmt;
}
	
static int		print_hex(char *buff, va_list ap, t_fmt *fmt)
{
	unsigned int	num;

	num = va_arg(ap, unsigned int);
	if (fmt->spec == 'x')
		ft_putnbr_base(num, "0123456789abcdef");
	else
		ft_putnbr_base(num, "0123456789ABCDEF");
	(void)buff;
	(void)fmt;
}

static int		print_per(char *buff, va_list ap, t_fmt *fmt)
{
	char per;

	per = va_arg(ap, int);
	write(1, &per, 1);
	(void)buff;
	(void)fmt;
}
	
static int		sort_spec(char *buff, va_list ap, t_fmt *fmt)
{
	if (fmt->spec == 's')
		print_s(buff, ap, fmt);
	else if ((fmt->spec == 'd') || (fmt->spec == 'i') || (fmt->spec == 'u'))
		print_d_i_u(buff, ap, fmt);
	else if (fmt->spec == 'c')
		print_c(buff, ap, fmt);
	else if (fmt->spec == 'p')
		print_p(buff, ap, fmt);
	else if (fmt->spec == 'x' || fmt->spec == 'X')
		print_hex(buff, ap, fmt);
	else if (fmt->spec == '%')
		print_per(buff, ap, fmt);
}

static int		con_per(char *f, va_list ap, t_fmt *fmt)
{
	char *buff;
	int end;
	
	init_fmt(fmt);
	end = find_spec(f);
	buff = strndup(f + 1, end);
	fmt->spec = buff[end - 1];
	if (!(set_fmt(buff, fmt)))
		return (-1);
	sort_spec(buff, ap, fmt);
	free(buff);
	return (end);
}

static int		find_per(va_list ap, char *f)
{
	int		i;
	t_fmt	fmt;
//	int	res;

	i = 0;
	while (f[i])
	{
		if (f[i] == '%')
			i = i + con_per(f + i, ap,  &fmt);
		else
			write(1, (f + i), 1);
		i++;
	}
	return (0);
	//return (res);
}

static int		is_spec(char c)
{
	if (c == 'c' || c == 's' || c == 'd' || c == 'i' || c == 'u' || c == 'x'
			|| c == 'X' || c == '%' || c == 'p')
		return (1);
	else
		return (0);
}


static int		find_spec(char *f)
{
	char *str;
	int i;

	str = strdup(f);
	i = 1;
	while (str[i])
	{
		if (is_spec(str[i]))
		{
			free(str);
			return (i);
		}
		else
			i++;
	}
	free(str);
	return (0);
}

/*
static int	check_fmt(char *f)
{
	int i;

	if (!f)
		return (0);
	i = 0;
	while (f[i])
	{
		if (f[i] == '%')
		{
			i++;
			if (!(i = find_spec(f, i)))
					return (0);
		}
		else
			i++;
	}
	return (i);
}
*/

static int		ft_printf(const char *fmt, ...)
{
	va_list		ap;
	int			result;
	char		*f;

	f = (char *)fmt;
	/*if (!(check_fmt(f)))
		return (0);*/
	va_start(ap, fmt);
	result = find_per(ap, f);
	va_end(ap);
	return (result);
}

int	main(void)
{
	char *s1 = "Hello";
	int	num1 = 10;
	//char *s2 = "Bye";

	//ft_printf("Hello");
	printf("I want you to say %i my lady %6s wow %p %x %X\n", num1, s1, s1, 100, 5678876);
	ft_printf("I want you to say %i my lady %6s wow %p %x %X\n", num1, s1, s1, 100, 5678876);
	
	return (0);
}
