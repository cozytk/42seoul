/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekkim <taekkim@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:08:46 by taekkim           #+#    #+#             */
/*   Updated: 2021/03/03 16:08:48 by taekkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	ft_putnbr_fd(long n, int fd)
{
	char		num[32];
	long long	l;
	int			len;

	l = (long long)n;
	if (l > 100000 || l < 0)
		return ;
	len = (l > 0) ? 0 : 1;
	l = (l > 0) ? l : l * -1;
	while (n)
		n = len++ ? n / 10 : n / 10;
	num[len] = '\0';
	while (l)
	{
		num[--len] = l % 10 + '0';
		l = l / 10;
	}
	if (len != 0 && num[1] == '\0')
		num[0] = '0';
	if (len != 0 && num[1] != '\0')
		num[0] = '-';
	write(fd, num, ft_strlen(num));
}
