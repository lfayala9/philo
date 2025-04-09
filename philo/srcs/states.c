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

// COMER->DORMIR->PENSAR->COMER

void	philo_sleep(t_philo *p)
{
	if (check_die(p) || time_over(p))
		return ;
	print_mutex(p, "\001\033[1;34m\002is sleeping\001\033[0m\002", timestamp(), \
	p->id);
	do_usleep(p, p->dinner->to_sleep);
	p->is_sleeping = 0;
	p->is_thinking = 1;
}

void	philo_think(t_philo *p)
{
	print_mutex(p, "\001\033[1;32m\002is thinking\001\033[0m\002", timestamp(), \
	p->id);
	p->is_thinking = 0;
	p->is_eating = 1;
}

void	philo_kill(t_philo *p)
{
	pthread_mutex_lock(&p->dinner->dead);
	if (p->dinner->philo_died == 0)
	{
		p->dinner->philo_died = 1;
		print_mutex(p, "\001\033[1;31m\002died\001\033[0m\002", timestamp(), \
		p->id);
	}
	pthread_mutex_unlock(&p->dinner->dead);
}

void	philo_eat(t_philo *p)
{
	if (check_die(p) || time_over(p))
		return ;
	if (p->dinner->diners == 3)
	{
		if (!grab_if3(p))
			return ;
	}
	else
	{
		if (!grab_forks(p))
			return ;
	}
	print_mutex(p, "\001\033[1;33m\002is eating\001\033[0m\002", timestamp(), \
	p->id);
	pthread_mutex_lock(&p->death);
	p->last_meal = timestamp();
	pthread_mutex_unlock(&p->death);
	do_usleep(p, p->dinner->to_eat);
	pthread_mutex_unlock(&p->r_fork->fork);
	pthread_mutex_unlock(&p->l_fork->fork);
	pthread_mutex_lock(&p->dinner->meals);
	p->meals++;
	pthread_mutex_unlock(&p->dinner->meals);
	p->is_eating = 0;
	p->is_sleeping = 1;
}
