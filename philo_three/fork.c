/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekkim <taekkim@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:10:19 by taekkim           #+#    #+#             */
/*   Updated: 2021/03/03 16:10:22 by taekkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int		get_fork(t_data *a)
{
	if (get_time(a) - a->time > a->stat->time_to_die)
	{
		a->pos = DIE;
		print_status(a);
		return (1);
	}
	sem_wait(a->stat->fork_lock);
	if (get_time(a) - a->time > a->stat->time_to_die)
	{
		a->pos = DIE;
		print_status(a);
		return (1);
	}
	++a->fork;
	a->pos = FORK;
	print_status(a);
	return (0);
}

int		return_fork(t_data *a)
{
	sem_post(a->stat->fork_lock);
	sem_post(a->stat->fork_lock);
	a->fork -= 2;
	return (1);
}
