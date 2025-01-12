/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 20:21:07 by bdenfir           #+#    #+#             */
/*   Updated: 2025/01/12 13:53:09 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void eat(t_philo *philo)
{
    if (philo->l_fork < philo->r_fork && !is_he_dead(philo)) {
        pthread_mutex_lock(philo->l_fork);
        print_message('f', philo);
        pthread_mutex_lock(philo->r_fork);
        print_message('f', philo);
    } else if (!is_he_dead(philo)) {
        pthread_mutex_lock(philo->r_fork);
        print_message('f', philo);
        pthread_mutex_lock(philo->l_fork);
        print_message('f', philo);
    }

    pthread_mutex_lock(philo->meal_lock);
    philo->eating = 1;
    philo->last_meal = get_timestamp();
    print_message('e', philo);
    pthread_mutex_unlock(philo->meal_lock);

    usleep(philo->eat_time * 1000);
    if (philo->l_fork < philo->r_fork) {
        pthread_mutex_unlock(philo->r_fork);
        pthread_mutex_unlock(philo->l_fork);
    } else {
        pthread_mutex_unlock(philo->l_fork);
        pthread_mutex_unlock(philo->r_fork);
    }
    pthread_mutex_lock(philo->meal_lock);
    philo->eating = 0;
    philo->meals_eaten++;
    pthread_mutex_unlock(philo->meal_lock);
}

void	think(t_philo *philo)
{
	print_message('t', philo);
	usleep(philo->sleep_time * 1000);
}

void ft_sleep(t_philo *philo)
{
	print_message('s', philo);
	usleep(philo->sleep_time * 1000);
}

int	philosopher_dead(t_philo *philo, size_t time_to_die)
{
	pthread_mutex_lock(philo->meal_lock);
	if (get_timestamp() - philo->last_meal >= time_to_die
		&& philo->eating == 0)
		return (pthread_mutex_unlock(philo->meal_lock), 1);
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}