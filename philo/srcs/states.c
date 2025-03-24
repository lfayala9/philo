#include "../philo.h"

// COMER->DORMIR->PENSAR->

void	philo_eat(t_philo *p)
{
	pthread_mutex_lock(&p->dinner->print);
	printf("%ld: %d Has taken the forks\n", \
		timestamp() - p->dinner->dinner_start, p->id);
	pthread_mutex_unlock(&p->dinner->print);
	pthread_mutex_lock(&p->r_fork->fork);
	pthread_mutex_lock(&p->l_fork->fork);
	pthread_mutex_lock(&p->dinner->print);
	printf("%ld: %d is eating...\n", \
		timestamp() - p->dinner->dinner_start, p->id);
	pthread_mutex_unlock(&p->dinner->print);
	pthread_mutex_unlock(&p->r_fork->fork);
	pthread_mutex_unlock(&p->l_fork->fork);
	p->meals++;
}
