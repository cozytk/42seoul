/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekkim <taekkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 10:13:46 by taekkim           #+#    #+#             */
/*   Updated: 2020/07/24 00:57:24 by taekkim          ###   ########.fr       */
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
	char *temp_w;
	char *temp_l;

	if (!buff)
		return (0);
	width = ft_strndup(buff, fmt->dot);
	if (fmt->dot >= 0)
		len = ft_strndup(buff + fmt->dot + 1, ft_strlen(buff) - fmt->dot - 2);
	else
		len = ft_strndup("", 0);
	temp_w = width;
	temp_l = len;
	if (!(fmt->ast == 10 || fmt->ast == 11))
		fmt->width = 0;
	if ((fmt->dot >= 0 && !(fmt->ast == 1 || fmt->ast == 11)))
		fmt->len = 0;
	while (ft_isdigit(*width))
		fmt->width = fmt->width * 10 + *width++ - '0';
	while (ft_isdigit(*len))
		fmt->len = fmt->len * 10 + *len++ - '0';
	free(temp_w);
	free(temp_l);
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

int		con_hex(t_fmt *fmt, char **str)
{
	int		diff;
	int		i;
	int		j;

	if (fmt->s_len >= fmt->len)
	{
		*str = ft_strndup(fmt->str, fmt->s_len);
		return (0);
	}
	diff = fmt->len - fmt->s_len;
	if (!(fmt->str_d_l = (char *)malloc(fmt->s_len + diff + 1)))
		return (-1);
	fmt->str_d_l[fmt->s_len + diff] = '\0';
	i = 0;
	while (diff--)
		fmt->str_d_l[i++] = '0';
	fmt->num_d_l = ft_strndup(fmt->str, fmt->s_len);
	j = 0;
	while (fmt->num_d_l[j])
		fmt->str_d_l[i++] = fmt->num_d_l[j++];
	fmt->str_d_l[i] = '\0';
	*str = ft_strndup(fmt->str_d_l, i + 1);
	free(fmt->str_d_l);
	free(fmt->num_d_l);
	return (1);
}
