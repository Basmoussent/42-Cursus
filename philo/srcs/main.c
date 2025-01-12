#include "philo.h"

int	main(int argc, char *argv[])
{
	t_program		program;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	int				philo_num;

	if (argc < 5 || argc > 6) return (KO);
	philo_num = ft_atoi(argv[1]);
	if (philo_num <= 0 || ft_atoi(argv[2]) <= 0 || ft_atoi(argv[3]) <= 0 || ft_atoi(argv[4]) <= 0) return (KO);
	if (argc == 6 && ft_atoi(argv[5]) <= 0) return (KO);
	philos = malloc(sizeof(t_philo) * philo_num);
	forks = malloc(sizeof(pthread_mutex_t) * philo_num);
	if (!philos || !forks) return (KO);
	printf("philo_num: %d\n", philo_num);
	printf("eat_time: %d\n", ft_atoi(argv[2]));
	printf("sleep_time: %d\n", ft_atoi(argv[3]));
	printf("death_time: %d\n", ft_atoi(argv[4]));
	if (argc == 6) printf("nb_to_eat: %d\n", ft_atoi(argv[5]));
	init_program(&program, philos);
	init_forks(forks, philo_num);
	init_philos(philos, &program, forks, argv);
	init_threads(&program, forks);
	free(philos);
	free(forks);
	return (OK);
}