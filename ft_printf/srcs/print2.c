/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 16:34:05 by taekkim           #+#    #+#             */
/*   Updated: 2020/07/24 00:57:14 by taekkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		print_s(va_list ap, t_fmt *fmt)
{
	if (fmt->ast)
		con_ast(ap, fmt);
	fmt->str = va_arg(ap, char *);
	if (!(fmt->str))
		fmt->str = "(null)";
	fmt->s_len = ft_strlen(fmt->str);
	if (fmt->dot >= 0)
		fmt->s_len = fmt->len < fmt->s_len ? fmt->len : fmt->s_len;
	con_width_s(fmt);
	write(1, fmt->str, fmt->s_len);
	fmt->res += fmt->s_len;
	print_minus_w(fmt);
	return (fmt->res);
}

int		print_hex(va_list ap, t_fmt *fmt)
{
	char *str;

	if (fmt->ast)
		con_ast(ap, fmt);
	if (fmt->zero && fmt->dot >= 0 && !(fmt->minus_l))
		fmt->zero = 0;
	fmt->num = va_arg(ap, unsigned int);
	if (no_num_and_len(fmt))
		return (fmt->res);
	decimal_to_hex(fmt);
	fmt->s_len = ft_strlen(fmt->str);
	con_hex(fmt, &str);
	fmt->s_len = ft_strlen(str);
	width_zero_d(fmt);
	write(1, str, ft_strlen(str));
	fmt->res += ft_strlen(str);
	print_minus_w(fmt);
	free(fmt->str);
	free(str);
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
