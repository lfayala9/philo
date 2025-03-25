/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layala-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:11:19 by layala-s          #+#    #+#             */
/*   Updated: 2025/03/25 12:11:20 by layala-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// COMER->DORMIR->PENSAR->

void	philo_eat(t_philo *p)
{
	while (1)
	{
		pthread_mutex_lock(&p->dinner->meals);
		p->dinner->keep_eating = (p->meals < p->dinner->times_eat \
		|| !p->dinner->times_eat);
		pthread_mutex_unlock(&p->dinner->meals);
		if (!p->dinner->keep_eating)
			break ;
		pthread_mutex_lock(&p->dinner->print);
		printf("%ld: %d Has taken the forks\n", timestamp(), p->id);
		pthread_mutex_unlock(&p->dinner->print);
		pthread_mutex_lock(&p->r_fork->fork);
		pthread_mutex_lock(&p->l_fork->fork);
		pthread_mutex_lock(&p->dinner->print);
		printf("%ld: %d is eating...\n", timestamp(), p->id);
		pthread_mutex_unlock(&p->dinner->print);
		usleep(p->dinner->to_eat * 1000);
		pthread_mutex_unlock(&p->r_fork->fork);
		pthread_mutex_unlock(&p->l_fork->fork);
		pthread_mutex_lock(&p->dinner->meals);
		if (p->dinner->times_eat)
			p->meals++;
		pthread_mutex_unlock(&p->dinner->meals);
	}
}
