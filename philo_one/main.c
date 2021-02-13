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
	spoon[i] = (pthread_t)0;
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

void *func(void *data)
{
	int *num = (int *)data;
	int i = 10;
	while (i--)
	{
		sleep(1);
		printf("%d\n", i);
	}
	printf("%d\n", *num);
	return (NULL);
}

int main(int argc, char *argv[]
{
	pthread_t p_thread[2];
	int result;
	int n1 = 1;
	int n2 = 2;

	if (!(argc == 5 || argc == 6))
		return (ft_write("Arguments error", 2));
	argv_to_num(argv);
	pthread_create(&p_thread[0], NULL, func, &n1);
	pthread_create(&p_thread[1], NULL, func, &n2);
	int i = 5;
	while (i--)
	{
		usleep(1000);
		printf("%d\n", i);
	}
	pause();
	return (0);
}
