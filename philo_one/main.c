/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekkim <taekkim@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:07:15 by taekkim           #+#    #+#             */
/*   Updated: 2021/03/03 16:07:17 by taekkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		init_state(t_stat *stat, int argc, char *argv[])
{
	struct timeval	start_time;

	stat->number_of_philo = ft_atoi(argv[1]);
	stat->fork = stat->number_of_philo;
	stat->time_to_die = ft_atoi(argv[2]);
	stat->time_to_eat = ft_atoi(argv[3]);
	stat->time_to_sleep = ft_atoi(argv[4]);
	stat->dead = 0;
	stat->argc = argc;
	if (argc == 6)
		if ((stat->must_eat = ft_atoi(argv[5])) < 1)
			return (ft_err("bad arguments\n"));
	if (stat->number_of_philo < 2 || stat->time_to_die < 0)
		return (ft_err("bad arguments\n"));
	if (stat->time_to_eat < 0 || stat->time_to_sleep < 0)
		return (ft_err("bad arguments\n"));
	gettimeofday(&start_time, NULL);
	if (!(stat->philo = (t_data *)malloc(sizeof(t_data) * (stat->fork + 1))))
		return (ft_err("malloc error\n"));
	stat->start_time = start_time.tv_sec * 1000 + start_time.tv_usec / 1000;
	pthread_mutex_init(&stat->write_lock, NULL);
	pthread_mutex_init(&stat->fork_lock, NULL);
	return (init_state2(stat));
}

int		init_state2(t_stat *stat)
{
	int	i;

	i = -1;
	while (++i < stat->fork + 1)
	{
		stat->philo[i].num = i + 1;
		stat->philo[i].fork = 0;
		stat->philo[i].pos = THINK;
		stat->philo[i].stat = stat;
		stat->philo[i].time = stat->start_time;
		stat->philo[i].cnt = 0;
	}
	stat->philo[stat->fork].num = 0;
	stat->philo[stat->fork].pos = MUST;
	return (0);
}

int		init_thread(t_stat *stat, pthread_t *p_thread)
{
	pthread_t	check;
	int			i;

	i = -1;
	while (++i < stat->number_of_philo)
	{
		if (pthread_create(&p_thread[i], NULL, philo, &stat->philo[i]) < 0)
			return (ft_err("thread create error\n"));
		pthread_detach(p_thread[i]);
	}
	if (pthread_create(&check, NULL, monitoring, stat) < 0)
		return (ft_err("thread create error\n"));
	pthread_join(check, NULL);
	return (0);
}

int		main(int argc, char *argv[])
{
	pthread_t	*p_thread;
	t_stat		stat;

	if (argc < 5 || argc > 6)
		return (ft_err("bad arguments\n"));
	if (init_state(&stat, argc, argv))
		return (1);
	if (!(p_thread = (pthread_t *)malloc(sizeof(pthread_t) * (stat.fork))))
		return (ft_err("malloc error\n"));
	if (init_thread(&stat, p_thread))
		return (1);
	free_thread(&stat, p_thread);
	return (0);
}
