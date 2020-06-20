/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekkim <taekkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 10:13:40 by taekkim           #+#    #+#             */
/*   Updated: 2020/06/18 10:13:41 by taekkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		minus_zero(char *s, t_fmt *fmt)
{
	if ((s[0] == '-' || s[0] == '0'))
	{
		if (s[0] == '-')
		{
			if (s[1] == 0)
				return (0);
			fmt->minus = 1;
		} else
		{
			if (fmt->spec == 'c' || fmt->spec == 's' || fmt->spec == 'p')
				return (0);
			fmt->zero = 1;
		}
	}
	return (1);
}

static int		ast_dot(char *buff, t_fmt *fmt)
{
	int i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '*')
		{
			if (!(con_ast_pos(buff, fmt, i)))
				return (0);
		} else if (buff[i] == '.')
		{
			if (fmt->dot >= 0)
				return (0);
			fmt->dot = i;
		} else if (is_spec(buff[i]))
			return (1);
		else if (!(ft_isdigit(buff[i])))
			return (0);
		fmt->digit = 1;
		i++;
	}
	return (1);
}

static int		width_len(char *buff, t_fmt *fmt)
{
	if (fmt->digit == 0)
		return (1);
	if (buff[0] == fmt->spec)
		return (1);
	if (!(ft_atoi(buff, fmt)))
		return (0);
	return (1);
}

static int		set_fmt(char *buff, t_fmt *fmt)
{
	if (!(minus_zero(buff, fmt)))
		return (0);
	if (fmt->minus || fmt->zero)
		buff++;
	if (!(ast_dot(buff, fmt)))
		return (0);
	if (!(width_len(buff, fmt)))
		return (0);
	return (1);
}
