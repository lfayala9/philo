/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layala-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:34:57 by layala-s          #+#    #+#             */
/*   Updated: 2025/03/20 13:34:59 by layala-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>

/*TYPES*/
typedef struct s_fork		t_fork;
typedef struct s_philo		t_philo;
typedef struct s_program	t_program;

/*STRUCTS*/

struct s_fork
{
	int				id;
	pthread_mutex_t	fork;
	t_philo			*philo;
};

struct	s_philo
{
	int			id;
	int			is_dead;
	t_fork		*r_fork;
	t_fork		*l_fork;
	t_program	*program;
};

struct	s_program
{
	int		philo_died;
	int		diners;
	int		to_die;
	int		to_eat;
	int		to_think;
	int		times_eat;
	t_philo	*philos;
	t_fork	*forks;
};

/*FUNCTIONS*/

long	ft_atol(const char *s);
int		ft_strlen(char *s);
int		check_input(int ac, char **av, t_program *program);

#endif
