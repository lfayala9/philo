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

	p = (t_philo *)arg;
	if (p->id % 2 == 0)
		usleep(100);
	while (1)
	{
		if (check_die(arg))
			break ;
		if (p->is_thinking == 1)
			philo_think(arg);
		if (p->is_eating == 1 && !check_die(arg))
			philo_eat(arg);
		if (p->is_sleeping == 1 && !check_die(arg))
			philo_sleep(arg);
		if (time_over(arg))
		{
			philo_kill(arg);
			break ;
		}
		if (!keep_eating(arg))
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
		pthread_join(d->philos[i].thread, NULL);
}
