/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:25:44 by bdenfir           #+#    #+#             */
/*   Updated: 2025/02/24 13:35:02 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	get_that_fork(philo);
	print_message('e', philo);
	usleep(philo->eat_time * 1000);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_timestamp();
	philo->meals_eaten++;
	philo->eat_time = 0;
	pthread_mutex_unlock(philo->meal_lock);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	get_that_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_message('f', philo);
	pthread_mutex_lock(philo->r_fork);
	print_message('f', philo);
}

void	think(t_philo *philo)
{
	print_message('t', philo);
}

void	ft_sleep(t_philo *philo)
{
	print_message('s', philo);
	usleep(philo->sleep_time * 1000);
}

int	philosopher_dead(t_philo *philo, long long time_to_die)
{
	long long	current_time;
	long long	time_since_last_meal;

	pthread_mutex_lock(philo->meal_lock);
	current_time = get_timestamp();
	time_since_last_meal = current_time - philo->last_meal;
	if (time_since_last_meal > time_to_die)
	{
		pthread_mutex_unlock(philo->meal_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}
