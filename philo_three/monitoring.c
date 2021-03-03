/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekkim <taekkim@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:10:50 by taekkim           #+#    #+#             */
/*   Updated: 2021/03/03 16:10:53 by taekkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	*death_timer(void *b)
{
	t_data *a;

	a = (t_data *)b;
	while (1)
	{
		if (get_time(a) - a->time > a->stat->time_to_die)
		{
			a->pos = DIE;
			print_status(a);
			exit(1);
			return ((void *)0);
		}
		usleep(1000);
	}
}

void	*monitoring(void *b)
{
	t_stat	*stat;
	int		j;
	int		cnt;

	stat = (t_stat *)b;
	cnt = 0;
	while (1)
	{
		if (stat->argc == 6)
		{
			while (cnt < stat->must_eat)
			{
				j = 0;
				while (j < stat->number_of_philo)
				{
					sem_wait(stat->philo[j].eat_cnt);
					++j;
				}
				++cnt;
			}
			print_status(&(stat->philo[stat->number_of_philo]));
			free_process(stat, stat->pid);
			exit(1);
		}
	}
}
