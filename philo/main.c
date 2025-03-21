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

long	timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	init_struct(t_dinner *d)
{
	int	i;

	d->philo_died = 0;
	if (pthread_mutex_init(&d->philo_died_mutex, NULL) != 0)
		return ;
	d->philos = (t_philo *)malloc(sizeof(t_philo) * d->diners);
	if (!d->philos)
		return ;
	d->forks = (t_fork *)malloc(sizeof(t_fork) * d->diners);
	if (!d->forks)
	{
		free(d->philos);
		return ;
	}
	i = 0;
	while (i < d->diners)
	{
		d->forks[i].id = i;
		d->forks[i].philo = NULL;
		pthread_mutex_init(&d->forks[i].fork, NULL);
		i++;
	}
}

void	assign_forks(t_philo *philo, t_fork *forks, int pos)
{
	int	diners;

	diners = philo->dinner->diners;
	philo->r_fork = &forks[(pos + 1) % diners];
	philo->l_fork = &forks[pos];
	if (philo->id % 2)
	{
		philo->r_fork = &forks[pos];	
		philo->l_fork = &forks[(pos + 1) % diners];
	}
}

void	init_philos(t_dinner *d)
{
	int		pos;
	t_philo	*philo;

	pos = 0;
	while (pos < d->diners)
	{
		philo = d->philos + pos;
		philo->id = pos + 1;
		philo->dinner = d;
		assign_forks(philo, d->forks, pos);
		// printf("Filosofo %d tiene tenedores [%d] y [%d]\n",
		// 	philo->id,
		// 	philo->l_fork->id,
		// 	philo->r_fork->id);
		pos++;
	}
}

int	main(int ac, char **av)
{
	t_dinner	*dinner;
	
	dinner = (t_dinner *)malloc(sizeof(t_dinner));
	if (!dinner)
		return (-1);
	if (check_input(ac, av, dinner) == 0)
		return (free(dinner), -1);
	init_struct(dinner);
	pthread_mutex_init(&dinner->print, NULL);
	init_philos(dinner);
	dinner->dinner_start = timestamp();
	do_dinner(dinner);
	pthread_mutex_destroy(&dinner->print);
	pthread_mutex_destroy(&dinner->philo_died_mutex);
	free(dinner->philos);
	free(dinner->forks);
	return (free(dinner), 0);
}
