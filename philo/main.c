/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layala-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:33:33 by layala-s          #+#    #+#             */
/*   Updated: 2025/03/20 13:33:35 by layala-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	*philo(void *a)
// {
// 	t_philo	*philo = (t_philo *)a;
// 	printf("%ld is thinking\n", pthread_self());
// 	return (NULL);
// }

void	init_struct(t_program *p)
{
	int	i;

	p->philo_died = 0;
	if (pthread_mutex_init(&p->philo_died_mutex, NULL) != 0)
		return ;
	p->philos = (t_philo *)malloc(sizeof(t_philo) * p->diners);
	if (!p->philos)
		return ;
	p->forks = (t_fork *)malloc(sizeof(t_fork) * p->diners);
	if (!p->forks)
	{
		free(p->philos);
		return ;
	}
	i = 0;
	while (i < p->diners)
	{
		p->forks[i].id = i;
		p->forks[i].philo = NULL;
		pthread_mutex_init(&p->forks[i].fork, NULL);
		i++;
	}
}

void	assign_forks(t_philo *philo, t_fork *forks, int pos)
{
	int	diners;

	diners = philo->program->diners;
	philo->r_fork = &forks[(pos + 1) % diners];
	philo->l_fork = &forks[pos];
	if (philo->id % 2)
	{
		philo->r_fork = &forks[pos];	
		philo->l_fork = &forks[(pos + 1) % diners];
	}
}

void	init_philos(t_program *p)
{
	int		pos;
	t_philo	*philo;

	pos = 0;
	while (pos < p->diners)
	{
		philo = p->philos + pos;
		philo->id = pos + 1;
		philo->program = p;
		assign_forks(philo, p->forks, pos);
		printf("Filosofo %d tiene tenedores [%d] y [%d]\n",
			philo->id,
			philo->l_fork->id,
			philo->r_fork->id);
		pos++;
	}
}

int	main(int ac, char **av)
{
	t_program	*program;
	
	program = (t_program *)malloc(sizeof(t_program));
	if (!program)
		return (-1);
	if (check_input(ac, av, program) == 0)
	{
		free(program);
		return (-1);
	}
	init_struct(program);
	init_philos(program);
	free(program->philos);
	free(program->forks);
	free(program);
	return (0);
}
