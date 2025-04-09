/* ************************************************************************** */
/*                      */
/*              :::      ::::::::   */
/*   threading.c                    :+:      :+:    :+:   */
/*                +:+ +:+    +:+     */
/*   By: bdenfir <bdenfir@42.fr>            +#+  +:+       +#+  */
/*            +#+#+#+#+#+   +#+    */
/*   Created: 2025/01/14 17:34:59 by bdenfir       #+#    #+#        */
/*   Updated: 2025/01/14 17:35:47 by bdenfir      ###   ########.fr       */
/*                      */
/* ************************************************************************** */

#include "philo.h"

void	*monitor_it(void *ptr)
{
	t_philo	*philos;

	philos = (t_philo *)ptr;
	while (1)
	{
		if (is_dead(philos) || is_full(philos))
			break ;
		usleep(50);
	}
	return (ptr);
}

void	init_threads(t_program *program, pthread_mutex_t *forks)
{
	pthread_t	monitor;
	int			i;

	i = 0;
	while (i < program->philos[0].nb_philos)
	{
		if (pthread_create(&program->philos[i].thread, NULL,
				&philosopher_routine, &program->philos[i]) != 0)
		{
			destroy_mutex(i, program, forks);
			return ;
		}
		i++;
	}
	if (pthread_create(&monitor, NULL, &monitor_it, program->philos) != 0)
	{
		destroy_mutex(i, program, forks);
		return ;
	}
	pthread_join(monitor, NULL);
	i = -1;
	while (++i < program->philos[0].nb_philos)
		pthread_join(program->philos[i].thread, NULL);
}

void	destroy_mutex(int i, t_program *program, pthread_mutex_t *forks)
{
	int	j;

	j = -1;
	while (++j < i)
	{
		if (program->philos[j].thread)
			pthread_join(program->philos[j].thread, NULL);
	}
	j = -1;
	while (++j < program->philos[0].nb_philos)
	{
		pthread_mutex_destroy(&forks[j]);
	}
}

void	one_philo(int death_time)
{
	long long	start;

	start = get_timestamp();
	printf("0 0 has taken a fork\n");
	usleep(death_time * 1000);
	printf("%lld 0 has died\n", get_timestamp() - start);
}
