/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekkim <taekkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 10:13:52 by taekkim           #+#    #+#             */
/*   Updated: 2020/06/20 16:21:16 by taekkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_unvalid(const char *base)
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
		return (0);
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
	return ((int)len);
}

static int		ft_intlen_2(long long n)
{
	int len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = n * -1;
	}
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}
