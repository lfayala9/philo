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

void	*philo(void *a)
{
	t_philo	*philo;

	philo = (t_philo *)a;
	philo_eat(a);
	return (NULL);
}

void	do_dinner(t_dinner *d)
{
	int	i;

	i = -1;
	while (++i < d->diners)
		pthread_create(&d->philos[i].thread, NULL, philo, &d->philos[i]);
	i = -1;
	while (++i < d->diners)
		pthread_join(d->philos[i].thread, NULL);
}
