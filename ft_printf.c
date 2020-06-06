/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekkim <taekkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 19:54:25 by taekkim           #+#    #+#             */
/*   Updated: 2020/06/06 21:20:53 by taekkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_unvalid(char *base)
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

void	ft_printing(int nbr, char *base, int length)
{
	unsigned int nb;

	nb = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nb = nbr * -1;
	}
	else
		nb = nbr;
	if (nb >= (unsigned int)length)
	{
		ft_printing(nb / length, base, length);
		ft_printing(nb % length, base, length);
	}
	if (nb < (unsigned int)length)
		write(1, &base[nb % length], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int length;

	length = ft_unvalid(base);
	if (length == 0)
		return ;
	ft_printing(nbr, base, length);
}

int		ft_intlen(long long num, int sign)
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

char	*ft_itoa(long long n)
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

void	con_per(const char *fmt, va_list ap, int i)
{
	char *buff = strndup(fmt + i, 2);
	char con = buff[1];

	if (con == 's')
	{
		char *str = va_arg(ap, char *);
		write(1, str, strlen(str));
	}
	else if ((con == 'd') || (con == 'i') || (con == 'u'))
	{
		long long num;
		if (con == 'u')
			num = va_arg(ap, unsigned int);
		else
			num = va_arg(ap, int);
		char *str = ft_itoa(num);
		write(1, str, strlen(str));
	}
	else if (con == 'c')
	{
		char chr = va_arg(ap, int);
		write(1, &chr, 1);
	}
	else if (con == 'p')
	{
		unsigned long n = va_arg(ap, unsigned long);
		printf("%lu\n", n);
		unsigned long *ptr = &n; 
		char *str =  ft_itoa(*ptr);
		write(1, str, strlen(str));
	}
	free(buff);
}

int		ft_printf(const char *fmt, ...)
{
	va_list ap;
	int i = 0;

	va_start(ap, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			con_per(fmt, ap, i);
			i++;
		}
		else
		{
			write(1, (fmt + i), 1);
		}
		i++;
	}
	va_end(ap);
	return (0);
}

int	main(void)
{
	char *s1 = "Hello";
	int	num1 = 10;
	//char *s2 = "Bye";

	//ft_printf("Hello");
	printf("I want you to say %i my lady %s wow %p\n", num1, s1, s1);
	ft_printf("I want you to say %i my lady %s wow %p\n", num1, s1, s1);
	
	return (0);
}
