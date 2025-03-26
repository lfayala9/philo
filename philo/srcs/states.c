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

// COMER->DORMIR->PENSAR->COMER...

int	time_over(t_philo *p)
{
	int	is_over;

	is_over = timestamp() - p->last_meal > p->dinner->to_die;
	return (is_over);
}

void	philo_kill(t_philo *p)
{
	pthread_mutex_lock(&p->dinner->dead);
	if (p->dinner->philo_died == 0)
	{
		p->dinner->philo_died = 1;
		print_mutex(p, "died", timestamp(), p->id);	
	}
	pthread_mutex_unlock(&p->dinner->dead);
}

void	philo_eat(t_philo *p)
{
	if (check_die(p))
		return ;
	pthread_mutex_lock(&p->r_fork->fork);
	pthread_mutex_lock(&p->l_fork->fork);
	if (check_die(p))
	{
		pthread_mutex_unlock(&p->r_fork->fork);
		pthread_mutex_unlock(&p->l_fork->fork);
		return;
	}
	print_mutex(p, "has taken a fork", timestamp(), p->id);
	print_mutex(p, "has taken a fork", timestamp(), p->id);
	print_mutex(p, "is eating...", timestamp(), p->id);
	p->last_meal = timestamp();
	usleep(p->dinner->to_eat * 1000);
	pthread_mutex_unlock(&p->r_fork->fork);
	pthread_mutex_unlock(&p->l_fork->fork);
	pthread_mutex_lock(&p->dinner->meals);
	if (p->dinner->times_eat)
		p->meals++;
	pthread_mutex_unlock(&p->dinner->meals);
}
