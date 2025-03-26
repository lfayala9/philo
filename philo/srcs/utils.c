/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layala-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:39:09 by layala-s          #+#    #+#             */
/*   Updated: 2025/03/20 13:43:58 by layala-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

long	ft_atol(const char *s)
{
	size_t	i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '-')
		sign = -1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
		res = res * 10 + (s[i++] - '0');
	return (sign * res);
}

void	print_mutex(t_philo *p, char *msg, long time, int id)
{
	pthread_mutex_lock(&p->dinner->print);
	printf("%ld: %d %s\n", time - p->dinner->dinner_start, id, msg);
	pthread_mutex_unlock(&p->dinner->print);
}
