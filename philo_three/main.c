/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekkim <taekkim@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:10:42 by taekkim           #+#    #+#             */
/*   Updated: 2021/03/03 16:10:47 by taekkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int		init_state(t_stat *stat, int argc, char *argv[])
{
	struct timeval	start_time;

	stat->number_of_philo = ft_atoi(argv[1]);
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
	if (!(stat->philo = (t_data *)malloc(sizeof(t_data) * \
		(stat->number_of_philo + 1))))
		return (ft_err("malloc error\n"));
	stat->start_time = start_time.tv_sec * 1000 + start_time.tv_usec / 1000;
	stat->write_lock = sem_open("write_lock", O_CREAT, 0644, 1);
	stat->fork_lock = sem_open("fork_lock", O_CREAT, 0644, \
		stat->number_of_philo);
	return (init_state2(stat));
}

int		init_state2(t_stat *stat)
{
	int		i;
	char	name[16];

	i = -1;
	ft_strcpy("eat_cnt", name);
	name[8] = '\0';
	while (++i < stat->number_of_philo + 1)
	{
		name[7] = '0' + i;
		sem_unlink(name);
		stat->philo[i].num = i + 1;
		stat->philo[i].fork = 0;
		stat->philo[i].pos = THINK;
		stat->philo[i].stat = stat;
		stat->philo[i].time = stat->start_time;
		stat->philo[i].cnt = 0;
		stat->philo[i].eat_cnt = sem_open(name, O_CREAT, 0644, 0);
	}
	stat->philo[stat->number_of_philo].num = 0;
	stat->philo[stat->number_of_philo].pos = MUST;
	return (0);
}

int		init_process(t_stat *stat, pid_t *pid)
{
	pthread_t	check;
	int			i;

	i = -1;
	while (++i < stat->number_of_philo)
	{
		pid[i] = fork();
		if (pid[i] > 0)
			continue ;
		else if (pid[i] == 0)
		{
			philo(&stat->philo[i]);
			exit(1);
		}
		else
		{
			return (ft_err("fork error\n"));
		}
	}
	if (pthread_create(&check, NULL, monitoring, stat) < 0)
		return (ft_err("thread create error\n"));
	pthread_detach(check);
	return (0);
}

int		main(int argc, char *argv[])
{
	pid_t		*pid;
	t_stat		stat;

	if (argc < 5 || argc > 6)
		return (ft_err("bad arguments\n"));
	sem_unlink("write_lock");
	sem_unlink("fork_lock");
	if (init_state(&stat, argc, argv))
		return (1);
	if (!(pid = (int *)malloc(sizeof(int) * (stat.number_of_philo))))
		return (ft_err("malloc error\n"));
	stat.pid = pid;
	if (init_process(&stat, pid))
		return (1);
	waitpid(-1, NULL, 0);
	free_process(&stat, pid);
	return (0);
}
