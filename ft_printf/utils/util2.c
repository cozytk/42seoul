/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekkim <taekkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 10:13:52 by taekkim           #+#    #+#             */
/*   Updated: 2020/07/24 00:57:27 by taekkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		no_num_and_len(t_fmt *fmt)
{
	if (fmt->len == 0 && fmt->num == 0)
	{
		if (fmt->width)
		{
			fmt->res += fmt->width;
			while (fmt->width--)
				write(1, " ", 1);
		}
		return (1);
	}
	return (0);
}

int		ft_printing(long long nbr, char *base, int length)
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
	return (0);
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
	return ((int)len);
}

int		ft_intlen_2(long long n)
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

int		ft_numlen(long long n)
{
	int len;

	len = 1;
	if (n < 0)
		n = n * -1;
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}
