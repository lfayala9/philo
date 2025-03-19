#include "philo.h"

void *philo(void *a)
{
	t_philo	*philo = (t_philo *)a;
	printf("%ld is thinking\n", pthread_self());
	return (NULL);
}

int main(int ac, char **av)
{
	// int 		i;
	// int 		philo_count;
	// t_program	*program;
	// pthread_t	threads[philo_count];
	// t_philo		philos[philo_count];	
	if (check_input(ac, av) == 0)
		return (0);
	// philo_count = ft_atoi(av[1]);
	// i = 0;
	// while (i < philo_count)
	// {
	// 	philos[i].id = i + 1;
	// 	if (pthread_create(&threads[i], NULL, philo, &philos[i]) != 0)
	// 		printf("No se pudo crear hilo");
	// 	i++;
	// }
	// for (int i = 0; i < philo_count; i++)
	// 	pthread_join(threads[i], NULL);
	// return (0);
}
