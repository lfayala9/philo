#include "philo.h"

void *philo(void *a)
{
	t_philo	*philo = (t_philo *)a;
	printf("%ld is thinking\n", pthread_self());
	return (NULL);
}

void	init_struct(t_program *p)
{
	p->philo_died = 0;
	p->philos = (t_philo *)malloc(sizeof(t_philo) * p->diners);
	if (!p->philos)
		return ;
	p->forks = (t_fork *)malloc(sizeof(t_fork) * p->diners);
	if (!p->forks)
		return ;
}

int main(int ac, char **av)
{
	t_program	*program;

	program = (t_program *)malloc(sizeof(t_program));
	if (!program)
		return (1);
	if (check_input(ac, av, program) == 0)
	{
		free(program);
		return (1);
	}
	init_struct(program);
	return (0);
}
