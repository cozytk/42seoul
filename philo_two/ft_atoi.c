/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekkim <taekkim@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:08:41 by taekkim           #+#    #+#             */
/*   Updated: 2021/03/03 16:08:42 by taekkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"
#include <limits.h>

static int	check_over_range(unsigned long long num, int m)
{
	if (num > LLONG_MAX - 1 && m == -1)
		return (0);
	if (num > LLONG_MAX && m == 1)
		return (-1);
	return (num * m);
}

int			ft_atoi(const char *str)
{
	int					m;
	unsigned long long	num;

	m = 1;
	num = 0;
	while (*str && (*str == ' ' || *str == '\t' || *str == '\n' || \
		*str == '\v' || *str == '\f' || *str == '\r'))
		str++;
	if (*str == '-')
		m = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		num = num * 10 + *str - '0';
		str++;
	}
	return (check_over_range(num, m));
}
