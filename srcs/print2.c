/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 16:34:05 by taekkim           #+#    #+#             */
/*   Updated: 2020/06/21 09:50:28 by taekkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		print_s(va_list ap, t_fmt *fmt)
{
	char *str;

	if (fmt->ast)
		con_ast(ap, fmt);
	va_copy(fmt->cp, ap);
	str = va_arg(fmt->cp, char *);
	if (!str)
		return (-1);
	fmt->s_len = ft_strlen(str);
	if (fmt->dot >= 0)
		fmt->s_len = fmt->len < fmt->s_len ? fmt->len : fmt->s_len;
	con_width_s(fmt);
	fmt->str = va_arg(ap, char *);
	if (!(fmt->str))
		return (-1);
	write(1, fmt->str, fmt->s_len);
	fmt->res += fmt->s_len;
	print_minus_w(fmt);
	return (fmt->res);
}

int		print_hex(va_list ap, t_fmt *fmt)
{
	unsigned int num;

	if (fmt->zero && (fmt->len || fmt->dot >= 0))
		return (0);
	if (fmt->ast)
		con_ast(ap, fmt);
	va_copy(fmt->cp, ap);
	fmt->str = decimal_to_hex(va_arg(fmt->cp, unsigned int));
	fmt->s_len = ft_strlen(fmt->str);
	width_zero_d(fmt);
	num = va_arg(ap, int);
	if (fmt->spec == 'x')
		ft_putnbr_base(num, "0123456789abcdef");
	else
		ft_putnbr_base(num, "0123456789ABCDEF");
	fmt->res += fmt->s_len;
	print_minus_w(fmt);
	free(fmt->str);
	return (fmt->res);
}

int		print_per(va_list ap, t_fmt *fmt)
{
	if (fmt->ast)
		con_ast(ap, fmt);
	fmt->s_len = 1;
	width_zero_d(fmt);
	write(1, "%", 1);
	fmt->res += fmt->s_len;
	print_minus_w(fmt);
	return (fmt->res);
}
