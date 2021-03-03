/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeong <jujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 16:26:03 by jujeong           #+#    #+#             */
/*   Updated: 2020/08/15 16:26:19 by jujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		get_fork(t_data *a)
{
	static int	j = 1;

	pthread_mutex_lock(&a->stat->fork_lock);
	if (a->num != j)
	{
		pthread_mutex_unlock(&a->stat->fork_lock);
		return (0);
	}
	if (a->stat->fork > 1 && a->fork == 0)
	{
		a->fork += 2;
		a->stat->fork -= 2;
		a->pos = FORK;
		print_status(a);
		print_status(a);
		++j;
		if (a->num == a->stat->number_of_philo)
			j = 1;
	}
	pthread_mutex_unlock(&a->stat->fork_lock);
	return (0);
}

int		return_fork(t_data *a)
{
	if (a->fork == 2)
	{
		pthread_mutex_lock(&a->stat->fork_lock);
		a->stat->fork += 2;
		pthread_mutex_unlock(&a->stat->fork_lock);
		a->fork -= 2;
		return (0);
	}
	return (1);
}
