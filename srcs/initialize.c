/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initilaize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 16:35:52 by taekkim           #+#    #+#             */
/*   Updated: 2020/06/20 18:54:48 by taekkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void		init_fmt(t_fmt *fmt)
{
	fmt->digit = 0;
	fmt->minus = 0;
	fmt->minus_w = 0;
	fmt->zero = 0;
	fmt->width = -1;
	fmt->dot = -1;
	fmt->len = -1;
	fmt->ast = 0;
	fmt->spec = 0;
	fmt->res = 0;
	fmt->num = 0;
	fmt->s_len = 0;
	fmt->str = 0;
	fmt->str_d_l = 0;
	fmt->num_d_l = 0;
}

int			is_spec(char c)
{
	if (c == 'c' || c == 's' || c == 'd' || c == 'i' || c == 'u' || c == 'x'
		|| c == 'X' || c == '%' || c == 'p')
		return (1);
	else
		return (0);
}

char		*ft_itoa(long long n)
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

int		width_neg_d(t_fmt *fmt)
{
	char *temp;

	temp = fmt->str;
	fmt->str = ft_strndup(temp + 1, ft_strlen(fmt->str) - 1);
	free(temp);
	fmt->num *= -1;
	fmt->s_len--;
	write(1, "-", 1);
	fmt->res++;
	return (1);
}

int		no_len(t_fmt *fmt)
{
	if (!(fmt->len == 0 && fmt->num == 0))
		return (0);
	fmt->str[0] = ' ';
	return (0);
}
