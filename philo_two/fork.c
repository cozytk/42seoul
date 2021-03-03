/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeong <jujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 16:36:51 by jujeong           #+#    #+#             */
/*   Updated: 2020/08/15 16:39:18 by jujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int		get_fork(t_data *a)
{
	static int	j = 1;

	if (a->num != j)
		return (0);
	sem_wait(a->stat->fork_lock);
	sem_wait(a->stat->fork_lock);
	a->fork += 2;
	a->pos = FORK;
	print_status(a);
	print_status(a);
	++j;
	if (a->num == a->stat->number_of_philo)
		j = 1;
	return (0);
}

int		return_fork(t_data *a)
{
	sem_post(a->stat->fork_lock);
	sem_post(a->stat->fork_lock);
	a->fork -= 2;
	return (1);
}
