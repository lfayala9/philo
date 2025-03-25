/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layala-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:33:33 by layala-s          #+#    #+#             */
/*   Updated: 2025/03/25 12:10:27 by layala-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, 0);
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
	t_philo	*p;

	pos = 0;
	while (pos < d->diners)
	{
		p = d->philos + pos;
		p->id = pos + 1;
		p->dinner = d;
		assign_forks(p, d->forks, pos);
		pos++;
	}
}

int	main(int ac, char **av)
{
	t_dinner	*d;

	d = (t_dinner *)malloc(sizeof(t_dinner));
	if (!d)
		return (-1);
	if (check_input(ac, av, d) == 0)
		return (free(d), -1);
	init_struct(d);
	pthread_mutex_init(&d->print, NULL);
	init_philos(d);
	d->dinner_start = timestamp();
	do_dinner(d);
	pthread_mutex_destroy(&d->print);
	pthread_mutex_destroy(&d->philo_died_mutex);
	free(d->philos);
	free(d->forks);
	return (free(d), 0);
}
