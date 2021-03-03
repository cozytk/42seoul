/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekkim <taekkim@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:10:55 by taekkim           #+#    #+#             */
/*   Updated: 2021/03/03 16:10:58 by taekkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	print_status(t_data *a)
{
	sem_wait(a->stat->write_lock);
	if (a->stat->dead)
		return ;
	ft_putnbr_fd(get_time(a), 1);
	write(1, " \t", 2);
	print_status1(a);
	if (a->pos == DIE)
	{
		a->stat->dead = 1;
		write(1, " died\n", 6);
		return ;
	}
	if (a->pos == MUST)
	{
		ft_sleep(a, a->stat->time_to_eat);
		a->stat->dead = 1;
		write(1, "all philosophers eat ", 22);
		ft_putnbr_fd(a->stat->must_eat, 1);
		write(1, "\n", 1);
		return ;
	}
	sem_post(a->stat->write_lock);
}

void	print_status1(t_data *a)
{
	if (a->num)
		ft_putnbr_fd(a->num, 1);
	if (a->pos == FORK)
		write(1, " has taken a fork\n", 18);
	if (a->pos == EAT)
		write(1, " is eating\n", 11);
	if (a->pos == SLEEP)
		write(1, " is sleeping\n", 13);
	if (a->pos == THINK)
		write(1, " is thinking\n", 13);
}

void	*philo(void *b)
{
	t_data *a;

	a = (t_data *)b;
	a->time = get_time(a);
	if (pthread_create(&a->p_thread, NULL, death_timer, a) < 0)
		return (0);
	pthread_detach(a->p_thread);
	usleep(100);
	while (1)
	{
		if (get_time(a) - a->time > a->stat->time_to_die)
		{
			a->pos = DIE;
			print_status(a);
			return ((void *)0);
		}
		if (a->fork < 2 && get_fork(a))
			return ((void *)0);
		if (a->fork == 2)
			eat(a);
	}
	return ((void *)1);
}

void	eat(t_data *a)
{
	a->pos = EAT;
	++a->cnt;
	print_status(a);
	a->time = get_time(a);
	ft_sleep(a, a->stat->time_to_eat);
	sem_post(a->eat_cnt);
	return_fork(a);
	a->pos = SLEEP;
	print_status(a);
	ft_sleep(a, a->stat->time_to_sleep);
	a->pos = THINK;
	print_status(a);
}
