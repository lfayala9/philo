/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layala-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:08:44 by layala-s          #+#    #+#             */
/*   Updated: 2025/03/25 12:09:30 by layala-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_die(t_philo *p)
{
	int dead_philo;

	pthread_mutex_lock(&p->dinner->dead);
	if (p->dinner->philo_died)
		dead_philo = 1;
	else
		dead_philo = 0;
	pthread_mutex_unlock(&p->dinner->dead);
	return (dead_philo);
}

int	check_one(t_philo *p)
{
	if (p->dinner->diners == 1)
	{
		print_mutex(p, "has taken a fork", timestamp(), p->id);
		usleep(p->dinner->to_die * 1000);
		philo_kill(p);
		return (1);
	}
	return (0);
}

void	*philo(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	check_one(p);
	if (p->id % 2 == 0)
		usleep(100);
	while (1)
	{
		if (time_over(arg))
		{
			philo_kill(arg);
			break ;
		}
		if (check_die(arg))
			break ;
		if (p->is_thinking == 1)
			philo_think(arg);
		if (p->is_eating == 1 && !check_die(arg))
			philo_eat(arg);
		if (p->is_sleeping == 1 && !check_die(arg))
			philo_sleep(arg);
		if (!keep_eating(arg))
			break ;
	}
	return (NULL);
}

void	do_dinner(t_dinner *d)
{
	int	i;

	i = -1;
	d->dinner_start = timestamp();
	while (++i < d->diners)
	{
		d->philos[i].last_meal = d->dinner_start;
		pthread_create(&d->philos[i].thread, NULL, philo, &d->philos[i]);
	}
		i = -1;
	while (++i < d->diners)
		pthread_join(d->philos[i].thread, NULL);
}
