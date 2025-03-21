#include "../philo.h"

void	*philo(void *a)
{
	t_philo	*philo = (t_philo *)a;
		// pthread_mutex_lock(&philo->dinner->print);
		// printf("%ld: Filósofo %d está pensando\n",
		// 	timestamp() - philo->dinner->dinner_start, philo->id);
		// pthread_mutex_unlock(&philo->dinner->print);
		// pthread_mutex_lock(&philo->l_fork->fork);
		// pthread_mutex_lock(&philo->r_fork->fork);
		// pthread_mutex_lock(&philo->dinner->print);
		// printf("%ld: Filósofo %d ha tomado los tenedores [%d] y [%d]\n",
		// 	timestamp() - philo->dinner->dinner_start,
		// 	philo->id,
		// 	philo->l_fork->id,
		// 	philo->r_fork->id);
		// pthread_mutex_unlock(&philo->dinner->print);
		// pthread_mutex_lock(&philo->dinner->print);
		// printf("%ld: Filósofo %d está comiendo y tardó %dms\n",
		// 	timestamp() - philo->dinner->dinner_start,
		// 	philo->id,
		// 	philo->dinner->to_eat);
		// pthread_mutex_unlock(&philo->dinner->print);
		// pthread_mutex_unlock(&philo->r_fork->fork);
		// pthread_mutex_unlock(&philo->l_fork->fork);
	pthread_mutex_lock(&philo->dinner->print);
	printf("%ld --> %d is doing something\n", timestamp(), philo->id);
	pthread_mutex_unlock(&philo->dinner->print);
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
