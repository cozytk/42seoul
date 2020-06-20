/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   confirm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekkim <taekkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 10:14:08 by taekkim           #+#    #+#             */
/*   Updated: 2020/06/20 16:42:08 by taekkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int		con_ast_pos(t_fmt *fmt, int i)
{
	if (fmt->ast == 0 && fmt->dot == -1 && i == 0)
		fmt->ast = 10;
	else if (fmt->ast == 0 && fmt->dot >= 0)
		fmt->ast = 01;
	else if (fmt->ast == 10 && fmt->dot == i - 1)
		fmt->ast = 11;
	else
		return (0);
	return (1);
}

int		con_ast(va_list ap, t_fmt *fmt)
{
	if (fmt->ast == 1)
		fmt->len = va_arg(ap, int);
	else if (fmt->ast == 10)
		fmt->width = va_arg(ap, int);
	else if (fmt->ast == 11)
	{
		fmt->width = va_arg(ap, int);
		fmt->len = va_arg(ap, int);
	}
	else
		return (-1);
	return (0);
}

int		con_width_s(t_fmt *fmt)
{
	if (fmt->width > fmt->s_len)
		fmt->width = fmt->width - fmt->s_len;
	else
		return (0);
	if (fmt->minus > 0)
		fmt->minus_w = fmt->width;
	else
	{
		fmt->res += fmt->s_len;
		while ((fmt->width)--)
			write(1, " ", 1);
	}
	return (0);
}
