/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekkim <taekkim@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:07:24 by taekkim           #+#    #+#             */
/*   Updated: 2021/03/03 16:07:25 by taekkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	*monitoring(void *b)
{
	t_stat	*stat;
	int		j;

	stat = (t_stat *)b;
	while (1)
	{
		if (stat->argc == 6)
		{
			j = 0;
			while (j < stat->number_of_philo)
			{
				if (stat->philo[j].cnt < stat->must_eat)
					break ;
				++j;
			}
			if (j == stat->number_of_philo)
			{
				print_status(&(stat->philo[stat->number_of_philo]));
				return (0);
			}
		}
		j = 1;
		if (stat->dead)
			return (0);
	}
}
