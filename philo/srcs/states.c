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
	print_mutex(p, "is sleeping", timestamp(), p->id);
	usleep(p->dinner->to_sleep * 1000);
	p->is_sleeping = 0;
	p->is_thinking = 1;
}

void	philo_think(t_philo *p)
{
	print_mutex(p, "is thinking", timestamp(), p->id);
	p->is_thinking = 0;
	p->is_eating = 1;
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
	if (check_die(p) || time_over(p))
		return ;
	pthread_mutex_lock(&p->r_fork->fork);
	print_mutex(p, "has taken a fork", timestamp(), p->id);
	pthread_mutex_lock(&p->l_fork->fork);
	print_mutex(p, "has taken a fork", timestamp(), p->id);
	print_mutex(p, "is eating", timestamp(), p->id);
	p->last_meal = timestamp();
	usleep(p->dinner->to_eat * 1000);
	pthread_mutex_unlock(&p->r_fork->fork);
	pthread_mutex_unlock(&p->l_fork->fork);
	pthread_mutex_lock(&p->dinner->meals);
	p->meals++;
	pthread_mutex_unlock(&p->dinner->meals);
	p->is_eating = 0;
	p->is_sleeping = 1;
}
