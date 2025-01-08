#include "philo.h"

int	is_dead(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].nb_philos)
	{
		if (philosopher_dead(&philos[i], philos[i].death_time))
		{
			print_message('d', philos[i].id, *&philos[i].start_time);
			pthread_mutex_lock(philos[0].dead_lock);
			*philos->dead = 1;
			pthread_mutex_unlock(philos[0].dead_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

int is_full(t_philo *philos)
{
	int	i;

	i = 0;
	while (i <= philos[0].nb_philos)
	{
		if (philos[i].meals_eaten != philos[i].nb_to_eat)
			return (KO);
		i++;
	}
	return (OK);
}

void	*philosopher_routine(void *ptr)
{
    t_philo	*philo;

    philo = (t_philo *)ptr;
    while (!(*philo->dead))
    {
        eat(philo);
		think(philo);
		ft_sleep(philo);
    }
    return (NULL);
}
