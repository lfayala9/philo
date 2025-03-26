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

void	*philo(void *arg)
{
	t_philo	*p;
	int		keep;

	p = (t_philo *)arg;
	while (1)
	{
		if (check_die(arg))
			break ;
		if (!check_die(arg))
			philo_eat(arg);
		if (time_over(arg))
		{
			philo_kill(arg);
			break ;
		}
		pthread_mutex_lock(&p->dinner->meals);
		keep = (p->meals < p->dinner->times_eat \
		|| !p->dinner->times_eat);
		pthread_mutex_unlock(&p->dinner->meals);
		if (!keep)
			break ;
	}
	return (NULL);
}

void	do_dinner(t_dinner *d)
{
	int	i;

	i = -1;
	while (++i < d->diners)
		pthread_create(&d->philos[i].thread, NULL, philo, &d->philos[i]);
	i = -1;
	// IF philo died || meals done
	//			--> break ; 
	while (++i < d->diners)
	{
		// printf("------------------------> Cerrado el hilo del filosofo %d\n", d->philos[i].id);
		pthread_join(d->philos[i].thread, NULL);
	}
}
