/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekkim <taekkim@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:11:08 by taekkim           #+#    #+#             */
/*   Updated: 2021/03/03 16:11:11 by taekkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

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
	exit(1);
	return (1);
}

int		free_process(t_stat *stat, pid_t *pid)
{
	int		i;
	char	name[16];

	ft_strcpy("eat_cnt", name);
	name[8] = '\0';
	i = -1;
	while (++i < stat->number_of_philo)
	{
		name[7] = '0' + i;
		sem_unlink(name);
		kill(pid[i], 9);
	}
	name[7] = '0' + i;
	sem_unlink(name);
	sem_unlink("write_lock");
	sem_unlink("fork_lock");
	free(pid);
	free(stat->philo);
	return (1);
}
