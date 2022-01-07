/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekkim <taekkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 10:13:20 by taekkim           #+#    #+#             */
/*   Updated: 2020/07/24 00:57:10 by taekkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		print_d_i(va_list ap, t_fmt *fmt)
{
	if (fmt->ast)
		con_ast(ap, fmt);
	if (fmt->zero && fmt->dot >= 0 && !(fmt->minus_l))
		fmt->zero = 0;
	fmt->num = va_arg(ap, int);
	if (no_num_and_len(fmt))
		return (fmt->res);
	fmt->num_len = ft_numlen(fmt->num);
	fmt->s_len = ft_intlen_2(fmt->num);
	if (!(con_d_l(fmt)))
		fmt->str = ft_itoa(fmt->num);
	width_zero_d(fmt);
	write(1, fmt->str, fmt->s_len);
	fmt->res += fmt->s_len;
	print_minus_w(fmt);
	free(fmt->str);
	return (fmt->res);
}

int		print_u(va_list ap, t_fmt *fmt)
{
	if (fmt->ast)
		con_ast(ap, fmt);
	if (fmt->zero && fmt->dot >= 0 && !(fmt->minus_l))
		fmt->zero = 0;
	fmt->num = va_arg(ap, unsigned int);
	if (no_num_and_len(fmt))
		return (fmt->res);
	fmt->num_len = ft_numlen(fmt->num);
	fmt->s_len = ft_intlen_2(fmt->num);
	if (!(con_d_l(fmt)))
		fmt->str = ft_itoa(fmt->num);
	no_len(fmt);
	width_zero_d(fmt);
	write(1, fmt->str, fmt->s_len);
	fmt->res += fmt->s_len;
	print_minus_w(fmt);
	free(fmt->str);
	return (fmt->res);
}

int		print_c(va_list ap, t_fmt *fmt)
{
	char chr;

	if (fmt->ast)
		con_ast(ap, fmt);
	fmt->s_len = 1;
	con_width_s(fmt);
	chr = va_arg(ap, int);
	write(1, &chr, 1);
	fmt->res += fmt->s_len;
	print_minus_w(fmt);
	return (fmt->res);
}

int		print_p(va_list ap, t_fmt *fmt)
{
	int temp;

	if (fmt->zero)
		return (0);
	if (fmt->ast)
		con_ast(ap, fmt);
	fmt->num = va_arg(ap, unsigned long);
	temp = fmt->num;
	decimal_to_hex(fmt);
	fmt->s_len = !(fmt->len || temp) ? 2 : ft_strlen(fmt->str) + 2;
	con_width_p(fmt);
	write(1, "0x", 2);
	write(1, fmt->str, fmt->s_len - 2);
	fmt->res += fmt->s_len;
	print_minus_w(fmt);
	free(fmt->str);
	return (fmt->res);
}
