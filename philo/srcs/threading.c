#include "philo.h"

void	*monitor_it(void *ptr)
{
	t_philo	*philos;

	philos = (t_philo *)ptr;
	while (1)
	{
		if (is_dead(philos))
			break ;
		if (philos->nb_to_eat != -1 && is_full(philos))
			break;
	}
	return (ptr);
}

void init_threads(t_program *program, pthread_mutex_t *forks)
{
	pthread_t	monitor;
	int			i;
	int			j;

	i = -1;
	while (++i < program->philos[0].nb_philos)
	{
		if (pthread_create(&program->philos[i].thread, NULL, &philosopher_routine, &program->philos[i]) != 0)
		{
			j = -1;
			while (++j < i)
				pthread_mutex_destroy(&forks[j]);
			return;
		}
	}
	if (pthread_create(&monitor, NULL, &monitor_it, program->philos) != 0)
	{
		j = -1;
		while (++j < program->philos[0].nb_philos)
			pthread_mutex_destroy(&forks[j]);
		return;
	}
	pthread_join(monitor, NULL);
}