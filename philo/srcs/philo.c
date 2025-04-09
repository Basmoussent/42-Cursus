/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   philo.c											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bdenfir <bdenfir@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/01/14 17:33:48 by bdenfir		   #+#	#+#			 */
/*   Updated: 2025/01/14 19:05:44 by bdenfir		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].nb_philos)
	{
		if (philosopher_dead(&philos[i], philos[i].death_time))
		{
			print_message('d', philos);
			pthread_mutex_lock(philos[0].dead_lock);
			*philos->dead = 1;
			pthread_mutex_unlock(philos[0].dead_lock);
			return (1);
		}
		pthread_mutex_lock(philos[0].dead_lock);
		if (*philos->dead == 1)
		{
			pthread_mutex_unlock(philos[0].dead_lock);
			return (1);
		}
		pthread_mutex_unlock(philos[0].dead_lock);
		i++;
	}
	return (0);
}

int	is_full(t_philo *philos)
{
	int	i;
	int	full_count;

	i = 0;
	full_count = 0;
	while (i < philos[0].nb_philos)
	{
		pthread_mutex_lock(philos[i].meal_lock);
		if (philos[i].meals_eaten >= philos[i].nb_to_eat
			&& philos[i].nb_to_eat != -1)
			full_count++;
		pthread_mutex_unlock(philos[i].meal_lock);
		i++;
	}
	if (full_count == philos[0].nb_philos)
	{	
		pthread_mutex_lock(philos[0].dead_lock);
		*philos->dead = 1;
		pthread_mutex_unlock(philos[0].dead_lock);
		return (1);
	}
	return (0);
}

void	*philosopher_routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2)
		usleep(15000);
	while (!is_he_dead(philo))
	{
		eat(philo);
		think(philo);
		ft_sleep(philo);
	}
	return (NULL);
}
