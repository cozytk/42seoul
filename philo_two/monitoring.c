/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeong <jujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 16:37:08 by jujeong           #+#    #+#             */
/*   Updated: 2020/08/15 16:46:47 by jujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	*monitoring(void *b)
{
	t_stat	*stat;
	int		j;

	stat = (t_stat *)b;
	while (1)
	{
		if (stat->argc == 6)
		{
			j = 0;
			while (j < stat->number_of_philo)
			{
				if (stat->philo[j].cnt < stat->must_eat)
					break ;
				++j;
			}
			if (j == stat->number_of_philo)
			{
				print_status(&(stat->philo[stat->number_of_philo]));
				return (0);
			}
		}
		j = 1;
		if (stat->dead)
			return (0);
	}
}
