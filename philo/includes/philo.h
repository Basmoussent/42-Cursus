#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			death_time;
	size_t			eat_time;
	size_t			sleep_time;
	long long		start_time;
	int				nb_philos;
	int				nb_to_eat;
	int				*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}					t_philo;
typedef struct s_program
{
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	long long		start_time;
	t_philo			*philos;
}					t_program;

int			ft_isdigit(int str);
int			ft_atoi(const char *str);
void 		edge_philo(char **argv, t_philo *philos, int i, pthread_mutex_t *forks);
int			is_dead(t_philo *philos);
int 		is_full(t_philo *philos);
long long	get_timestamp();
void		init_program(t_program *program, t_philo *philos);
void 		init_forks(pthread_mutex_t *forks, int philo_num);
void 		edge_philo(char **argv, t_philo *philos, int i, pthread_mutex_t *forks);
void		init_philos(t_philo *philos, t_program *program, pthread_mutex_t *forks, char **argv);
void 		init_threads(t_program *program, pthread_mutex_t *forks);
void		*philosopher_routine(void *ptr);
int			philosopher_dead(t_philo *philo, size_t time_to_die);
void		print_message(char c, t_philo *philo);
void 		ft_sleep(t_philo *philo);
void		think(t_philo *philo);
void		eat(t_philo *philo);
int			is_he_dead(t_philo *philo);

enum {
	KO = 1,
	OK = 0
};

#endif