#include "philo.h"

void	init_philos(t_philo *philos, t_program *program, pthread_mutex_t *forks, char **argv)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		philos[i].id = i;
		philos[i].eating = 0;
		philos[i].meals_eaten = 0;
		philos[i].death_time = ft_atoi(argv[2]);
		philos[i].eat_time = ft_atoi(argv[3]);
		philos[i].sleep_time = ft_atoi(argv[4]);
		philos[i].nb_philos = ft_atoi(argv[1]);
		philos[i].write_lock = &program->write_lock;
		philos[i].dead_lock = &program->dead_lock;
		philos[i].meal_lock = &program->meal_lock;
		philos[i].dead = &program->dead_flag;
		philos[i].l_fork = &forks[i];
		philos[i].start_time = program->start_time;
		philos[i].last_meal = get_timestamp();
		edge_philo(argv, philos, i, forks);
		i++;
	}
}

void edge_philo(char **argv, t_philo *philos, int i, pthread_mutex_t *forks)
{
	if (argv[5])
		philos[i].nb_to_eat = ft_atoi(argv[5]);
	else
		philos[i].nb_to_eat = -1;
	if (i == 0)
		philos[i].r_fork = &forks[philos[i].nb_philos - 1];
	else
		philos[i].r_fork = &forks[i - 1];
}
void init_forks(pthread_mutex_t *forks, int philo_num)
{
	int	i;

	i = 0;
	while (i < philo_num)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	init_program(t_program *program, t_philo *philos)
{
	struct timeval	tv;
	
	program->dead_flag = 0;
	program->philos = philos;
	gettimeofday(&tv, NULL);
	program->start_time = tv.tv_sec * 1000LL + tv.tv_usec / 1000LL;
	pthread_mutex_init(&program->write_lock, NULL);
	pthread_mutex_init(&program->dead_lock, NULL);
	pthread_mutex_init(&program->meal_lock, NULL);
}