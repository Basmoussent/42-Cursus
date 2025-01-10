#include "philo.h"

void	*monitor_it(void *ptr)
{
	t_philo	*philos;

	philos = (t_philo *)ptr;
	while (1)
	{
		if (is_dead(philos) || is_full(philos))
			break ;
	}
	return (ptr);
}
void init_threads(t_program *program, pthread_mutex_t *forks)
{
    pthread_t monitor;
    int i;

    for (i = 0; i < program->philos[0].nb_philos; i++) {
        if (pthread_create(&program->philos[i].thread, NULL, &philosopher_routine, &program->philos[i]) != 0) {
            for (int j = 0; j < i; j++) {
                pthread_join(program->philos[j].thread, NULL);
            }
            for (int j = 0; j < program->philos[0].nb_philos; j++) {
                pthread_mutex_destroy(&forks[j]);
            }
            return;
        }
    }
    if (pthread_create(&monitor, NULL, &monitor_it, program->philos) != 0) {
        for (int j = 0; j < program->philos[0].nb_philos; j++) {
            pthread_join(program->philos[j].thread, NULL);
        }
        for (int j = 0; j < program->philos[0].nb_philos; j++) {
            pthread_mutex_destroy(&forks[j]);
        }
        return;
    }
    pthread_join(monitor, NULL);
    for (i = 0; i < program->philos[0].nb_philos; i++) {
        pthread_join(program->philos[i].thread, NULL);
    }
}
