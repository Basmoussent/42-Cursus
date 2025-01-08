#include "philo.h"

int	ft_isdigit(int str)
{
	if (str >= '0' && str <= '9')
		return (2048);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	min;
	int	rslt;

	i = 0;
	min = 1;
	rslt = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			min = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		rslt *= 10;
		rslt += str[i++] - '0';
	}
	if (str && str[0] && rslt == 0)
		return (-1);
	return (rslt * min);
}

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	n;
	unsigned char	c;

	if (fd == -1)
		return ;
	if (nb < 0)
	{
		write(fd, "-", 1);
		n = -nb;
	}
	else
		n = nb;
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		c = n + '0';
		write(fd, &c, 1);
	}
}

void	print_message(char c, t_philo *philo)
{
	pthread_mutex_lock(philo->write_lock);
	if (c == 'd')
		printf("%lld %d died\n", get_timestamp() - philo->start_time , philo->id);
	else if (c == 'e')
		printf("%lld %d is eating\n", get_timestamp() - philo->start_time, philo->id);
	else if (c == 't')
		printf("%lld %d is thinking\n", get_timestamp() - philo->start_time, philo->id);
	else if (c == 's')
		printf("%lld %d is sleeping\n", get_timestamp() - philo->start_time, philo->id);
	else if (c == 'f')
		printf("%lld %d has taken a fork\n", get_timestamp() - philo->start_time, philo->id);
	pthread_mutex_unlock(philo->write_lock);
}

int	is_he_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
	{
		pthread_mutex_unlock(philo->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

void	detach_threads(t_philo *philosophers, int num_philosophers)
{
	int	i;

	i = 0;
	while (i < num_philosophers)
	{
		if (pthread_detach(philosophers[i].thread) != 0)
		{
			perror("Error detaching thread");
			exit(1);
		}
		i++;
	}
}
