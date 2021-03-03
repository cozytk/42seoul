/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeong <jujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 16:25:03 by jujeong           #+#    #+#             */
/*   Updated: 2020/08/15 16:53:13 by jujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

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
	sem_t			*eat_cnt;
	struct s_stat	*stat;
	pthread_t		p_thread;
}					t_data;

typedef struct		s_stat
{
	t_data			*philo;
	long			start_time;
	int				dead;
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				argc;
	pid_t			*pid;
	sem_t			*write_lock;
	sem_t			*fork_lock;
}					t_stat;

size_t				ft_strlen(const char *str);
char				*ft_strcpy(char *src, char *dst);
int					ft_atoi(const char *str);
void				ft_putnbr_fd(long n, int fd);
int					get_fork(t_data *a);
int					return_fork(t_data *a);
int					init_state(t_stat *stat, int argc, char *argv[]);
int					init_state2(t_stat *stat);
int					init_process(t_stat *stat, pid_t *pid);
void				*death_timer(void *b);
void				*monitoring(void *b);
void				print_status(t_data *a);
void				print_status1(t_data *a);
void				*philo(void *b);
void				eat(t_data *a);
long				get_time(t_data *a);
void				ft_sleep(t_data *a, int time);
int					ft_err(char *str);
int					free_process(t_stat *stat, pid_t *pid);

#endif
