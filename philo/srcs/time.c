#include "philo.h"

long long	get_timestamp()
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000LL) + (t.tv_usec / 1000LL));
}