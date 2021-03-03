/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekkim <taekkim@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:07:48 by taekkim           #+#    #+#             */
/*   Updated: 2021/03/03 16:07:54 by taekkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

long	get_time(t_data *a)
{
	long			time;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	time -= a->stat->start_time;
	return (time);
}

void	ft_sleep(t_data *a, int time)
{
	long	start;

	start = get_time(a);
	while ((get_time(a) - start) <= time)
		usleep(1000);
}

int		ft_err(char *str)
{
	write(2, str, ft_strlen(str));
	return (1);
}

int		free_thread(t_stat *stat, pthread_t *p_thread)
{
	free(p_thread);
	free(stat->philo);
	pthread_mutex_destroy(&stat->fork_lock);
	pthread_mutex_destroy(&stat->write_lock);
	return (1);
}
