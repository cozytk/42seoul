#include "philo_one.h"

int philo_num;
int die_time;
int eat_time;
int sleep_time;
int must_eat_num;
pthread_t *spoon;

int init(void)
{
	int i;

	i = -1;
	if (!(spoon = malloc(sizeof(pthread_t) * (philo_num + 1))))
		return (0);
	while (++i < philo_num)
		spoon[i] = (pthread_t)1;
	return (1);
}

int ft_strlen(char *s)
{
	int len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_write(char *s, int fd)
{
	int len;

	len = ft_strlen(s);
	return(write(fd, s, len));
}

int ft_atoi(char *s)
{
	int		sign;
	int		i;
	int		ret;

	i = 0;
	sign = 1;
	ret = 0;
	while (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		ret = ret * 10 + (s[i] - 48);
		i++;
	}
	return (ret * sign);
}

void argv_to_num(char **argv)
{
	philo_num = ft_atoi(argv[1]);
	die_time = ft_atoi(argv[2]);
	eat_time = ft_atoi(argv[3]);
	sleep_time = ft_atoi(argv[4]);
	must_eat_num = ft_atoi(argv[5]);
}
//
//void create_pthreads(void)
//{
//	int num;
//	int res;
//
//	num = philo_num;
//	while (num--)
//		pthread_create(res, NULL, t_function, NULL);
//}
//
//void *t_function(void *data)
//{
//	(void)data;
//
//
//}

int main(int argc, char *argv[])
{
	struct timeval time;
	pthread_mutex_t mutex_lock;
	int before;
	int after;

	if (!(argc == 5 || argc == 6))
		return (ft_write("Arguments error", 2));
	argv_to_num(argv);
	gettimeofday(&time, NULL);
	before = time.tv_usec;
	printf("%d %d %d %d %d\n", philo_num, die_time, eat_time, sleep_time, must_eat_num);
	gettimeofday(&time, NULL);
	usleep(100000);
	after = time.tv_usec;
	printf("%d\n", after - before);
//	pthread_mutex_init(&mutex_lock, NULL);
//	create_pthreads();
	return (0);
}