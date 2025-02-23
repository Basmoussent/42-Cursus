/* ************************************************************************** */
/*									  */
/*							:::	 ::::::::   */
/*   actions.c					  :+:   :+:	:+:   */
/*						  +:+ +:+	   +:+	*/
/*   By: bdenfir <bdenfir@42.fr>					+#+  +:+	   +#+	*/
/*						+#+#+#+#+#+   +#+	 */
/*   Created: 2025/01/07 20:21:07 by bdenfir		   #+#  #+#		  */
/*   Updated: 2025/01/14 17:34:16 by bdenfir		  ###   ########.fr	*/
/*									  */
/* ************************************************************************** */

#include "philo.h"

void eat(t_philo *philo)
{
    get_that_fork(philo);
    pthread_mutex_lock(philo->meal_lock);
    philo->eating = 1;
    philo->last_meal = get_timestamp();
    print_message('e', philo);
    pthread_mutex_unlock(philo->meal_lock);

    usleep(philo->eat_time * 1000); // Simulate eating
    pthread_mutex_unlock(philo->l_fork);
    pthread_mutex_unlock(philo->r_fork);

    pthread_mutex_lock(philo->meal_lock);
    philo->eating = 0;
    philo->meals_eaten++;
    pthread_mutex_unlock(philo->meal_lock);
}

void get_that_fork(t_philo *philo)
{
    if (philo->id % 2 == 0)
    {
        pthread_mutex_lock(philo->l_fork);
        print_message('f', philo);
        pthread_mutex_lock(philo->r_fork);
        print_message('f', philo);
    }
    else
    {
        pthread_mutex_lock(philo->r_fork);
        print_message('f', philo);
        pthread_mutex_lock(philo->l_fork);
        print_message('f', philo);
    }
}


void	think(t_philo *philo)
{
	print_message('t', philo);
	usleep(philo->sleep_time * 1000);
}

void	ft_sleep(t_philo *philo)
{
	print_message('s', philo);
	usleep(philo->sleep_time * 1000);
}

int philosopher_dead(t_philo *philo, long long time_to_die)
{
    pthread_mutex_lock(philo->meal_lock);
    long long current_time = get_timestamp();
    long long time_since_last_meal = current_time - philo->last_meal;

    printf("DEBUG: Philosopher %d - Current time: %lld, Last meal: %lld, Time since last meal: %lld, Time to die: %lld\n",
           philo->id, current_time, philo->last_meal, time_since_last_meal, time_to_die);

    if (time_since_last_meal >= time_to_die && philo->eating == 0)
    {
        pthread_mutex_unlock(philo->meal_lock);
        return 1;
    }
    pthread_mutex_unlock(philo->meal_lock);
    return 0;
}

