#include "../philo.h"

void	*philo(void *a)
{
	t_philo	*philo = (t_philo *)a;

	philo_eat(a);
	return (NULL);
}

void	do_dinner(t_dinner *d)
{
	int	i;

	i = -1;
	while (++i < d->diners)
		pthread_create(&d->philos[i].thread, NULL, philo, &d->philos[i]);
	i = -1;
	while (++i < d->diners)
		pthread_join(d->philos[i].thread, NULL);
}
