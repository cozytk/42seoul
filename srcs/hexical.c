/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexical.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 16:39:48 by taekkim           #+#    #+#             */
/*   Updated: 2020/07/24 01:15:57 by taekkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		con_width_p(t_fmt *fmt)
{
	if (fmt->s_len >= fmt->width)
		return (0);
	fmt->width -= fmt->s_len;
	if (fmt->minus)
		fmt->minus_w = fmt->width;
	else
	{
		fmt->res += fmt->width;
		while ((fmt->width)--)
			write(1, " ", 1);
	}
	return (0);
}

int		width_zero_d(t_fmt *fmt)
{
	if (fmt->s_len >= fmt->width)
		return (0);
	fmt->width -= fmt->s_len;
	if (fmt->minus)
		fmt->minus_w = fmt->width;
	else
	{
		fmt->res += fmt->width;
		if (fmt->zero && fmt->num < 0)
			width_neg_d(fmt);
		while ((fmt->width)--)
		{
			if (fmt->zero)
				write(1, "0", 1);
			else
				write(1, " ", 1);
		}
	}
	return (0);
}

int		print_minus_w(t_fmt *fmt)
{
	if (fmt->minus_w)
	{
		fmt->res += fmt->width;
		while ((fmt->width)--)
			write(1, " ", 1);
	}
	return (0);
}

int		hex_len(long long n)
{
	int res;

	res = 0;
	while (n >= 16)
	{
		n = n / 16;
		res++;
	}
	return (res);
}

int		decimal_to_hex(t_fmt *fmt)
{
	int		mod;
	int		len;

	len = hex_len(fmt->num);
	if (!(fmt->str = (char *)malloc(len + 2)))
		return (-1);
	fmt->str[len + 1] = 0;
	while (1)
	{
		mod = fmt->num % 16;
		if (mod < 10)
			fmt->str[len] = 48 + mod;
		else if (fmt->spec == 'X')
			fmt->str[len] = 65 + (mod - 10);
		else
			fmt->str[len] = 97 + (mod - 10);
		fmt->num = fmt->num / 16;
		len--;
		if (fmt->num == 0)
			break ;
	}
	return (0);
}
