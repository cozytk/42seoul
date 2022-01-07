/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekkim <taekkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 19:54:25 by taekkim           #+#    #+#             */
/*   Updated: 2020/07/24 00:57:45 by taekkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

int		sort_spec(va_list ap, t_fmt *fmt)
{
	if (fmt->spec == 's')
		print_s(ap, fmt);
	else if ((fmt->spec == 'd') || (fmt->spec == 'i'))
		print_d_i(ap, fmt);
	else if (fmt->spec == 'u')
		print_u(ap, fmt);
	else if (fmt->spec == 'c')
		print_c(ap, fmt);
	else if (fmt->spec == 'p')
		print_p(ap, fmt);
	else if (fmt->spec == 'x' || fmt->spec == 'X')
		print_hex(ap, fmt);
	else if (fmt->spec == '%')
		print_per(ap, fmt);
	return (0);
}

int		con_per(char *f, va_list ap, t_fmt *fmt)
{
	char	*buff;
	int		end;

	init_fmt(fmt);
	end = find_spec(f);
	buff = ft_strndup(f + 1, end);
	fmt->spec = buff[end - 1];
	if (!(set_fmt(buff, fmt)))
		return (-1);
	sort_spec(ap, fmt);
	free(buff);
	return (end);
}

int		find_per(va_list ap, char *f)
{
	int		i;
	int		res;
	int		printed;
	t_fmt	fmt;

	i = 0;
	printed = 0;
	while (f[i])
	{
		if (f[i] == '%')
		{
			if ((res = con_per(f + i, ap, &fmt)) < 0)
				return (-1);
			i = i + res;
			printed += fmt.res;
		}
		else
		{
			write(1, (f + i), 1);
			printed++;
		}
		i++;
	}
	return (printed);
}

int		find_spec(char *f)
{
	char	*str;
	int		i;

	str = ft_strndup(f, ft_strlen(f));
	i = 1;
	while (str[i])
	{
		if (is_spec(str[i]))
		{
			free(str);
			return (i);
		}
		else
			i++;
	}
	free(str);
	return (0);
}

int		ft_printf(const char *fmt, ...)
{
	va_list		ap;
	int			result;
	char		*f;

	f = (char *)fmt;
	va_start(ap, fmt);
	if ((result = find_per(ap, f)) < 0)
		return (-1);
	va_end(ap);
	return (result);
}
