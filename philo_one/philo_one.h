/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekkim <taekkim@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:07:39 by taekkim           #+#    #+#             */
/*   Updated: 2021/03/03 16:07:41 by taekkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

# define FORK 0
# define EAT 1
# define SLEEP 2
# define THINK 3
# define DIE 4
# define MUST 5

struct s_stat;

typedef struct		s_data
{
	int				num;
	int				pos;
	int				fork;
	int				cnt;
	long			time;
	struct s_stat	*stat;
}					t_data;

typedef struct		s_stat
{
	t_data			*philo;
	long			start_time;
	int				fork;
	int				dead;
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				argc;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	fork_lock;
}					t_stat;

size_t				ft_strlen(const char *str);
int					ft_atoi(const char *str);
void				ft_putnbr_fd(long n, int fd);
int					get_fork(t_data *a);
int					return_fork(t_data *a);
int					init_state(t_stat *stat, int argc, char *argv[]);
int					init_state2(t_stat *stat);
int					init_thread(t_stat *stat, pthread_t *p_thread);
void				*monitoring(void *b);
void				print_status(t_data *a);
void				print_status1(t_data *a);
void				*philo(void *b);
void				eat(t_data *a);
long				get_time(t_data *a);
void				ft_sleep(t_data *a, int time);
int					ft_err(char *str);
int					free_thread(t_stat *stat, pthread_t	*p_thread);

#endif
