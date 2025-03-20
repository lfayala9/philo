/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layala-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:44:26 by layala-s          #+#    #+#             */
/*   Updated: 2025/03/20 13:44:28 by layala-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	parse_input(int ac, char **av, t_program *program)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (ft_atol(av[i]) > 2147483647 || ft_atol(av[i]) < 1 \
			|| ft_strlen(av[i]) > 11)
			return (0);
	}
	i = 1;
	while (++i < 5)
	{
		if (ft_atol(av[i]) < 60)
			return (0);
	}
	program->diners = ft_atol(av[1]);
	program->to_die = ft_atol(av[2]);
	program->to_eat = ft_atol(av[3]);
	program->to_think = ft_atol(av[4]);
	if (av[5])
		program->times_eat = ft_atol(av[5]);
	return (1);
}

int	check_input(int ac, char **av, t_program *program)
{
	if (ac < 5 || ac > 6)
		return (0);
	else
	{
		if (parse_input(ac, av, program) == 0)
		{
			write(2, "Error: Invalid input\n", 22);
			return (0);
		}
	}
	return (1);
}
