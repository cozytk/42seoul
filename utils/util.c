/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekkim <taekkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 10:13:46 by taekkim           #+#    #+#             */
/*   Updated: 2020/06/20 18:55:33 by taekkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

size_t	ft_strlen(const char *s)
{
	size_t length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

int		ft_atoi(char *buff, t_fmt *fmt)
{
	char *width;
	char *len;

	if (!buff)
		return (0);
	width = ft_strndup(buff, fmt->dot);
	if (fmt->dot >= 0)
		len = ft_strndup(buff + fmt->dot + 1, ft_strlen(buff) - fmt->dot - 2);
	else
		len = "";
	if (width && !(fmt->ast == 10 || fmt->ast == 11))
		fmt->width = 0;
	if (len && !(fmt->ast == 1 || fmt->ast == 11))
		fmt->len = 0;
	while (ft_isdigit(*width))
		fmt->width = fmt->width * 10 + *width++ - '0';
	while (ft_isdigit(*len))
		fmt->len = fmt->len * 10 + *len++ - '0';
	return (1);
}

char	*ft_strndup(const char *s1, size_t n)
{
	char	*p;
	size_t	i;

	i = 0;
	if (!(p = (char *)malloc(ft_strlen(s1))))
		return (0);
	while (s1 && s1[i] && i < n)
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
