/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bdenfir <bdenfir@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/01/14 17:34:35 by bdenfir		   #+#	#+#			 */
/*   Updated: 2025/02/23 15:28:27 by bdenfir		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "philo.h"

static int	validate_args(int argc, char *argv[])
{
	if (argc < 5 || argc > 6)
		return (KO);
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[2]) <= 0
		|| ft_atoi(argv[3]) <= 0 || ft_atoi(argv[4]) <= 0)
		return (KO);
	if (argc == 6 && ft_atoi(argv[5]) <= 0)
		return (KO);
	return (OK);
}

static int	initialize_resources(t_program *program,
	t_philo **philos, pthread_mutex_t **forks, int philo_num)
{
	*philos = malloc(sizeof(t_philo) * philo_num);
	*forks = malloc(sizeof(pthread_mutex_t) * philo_num);
	if (!(*philos) || !(*forks))
		return (KO);
	init_program(program, *philos);
	return (OK);
}

int	main(int argc, char *argv[])
{
	t_program		program;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	int				philo_num;

	if (validate_args(argc, argv) == KO)
		return (KO);
	philo_num = ft_atoi(argv[1]);
	if (initialize_resources(&program, &philos, &forks, philo_num) == KO)
		return (KO);
	if (philo_num == 1)
		one_philo(ft_atoi(argv[2]));
	else
	{
		init_forks(forks, philo_num);
		init_philos(philos, &program, forks, argv);
		init_threads(&program, forks);
	}
	free(philos);
	free(forks);
	return (OK);
}
