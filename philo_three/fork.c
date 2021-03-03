/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeong <jujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 16:47:24 by jujeong           #+#    #+#             */
/*   Updated: 2020/08/15 16:48:56 by jujeong          ###   ########.fr       */
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
