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
typedef struct s_dinner		t_dinner;

/*STRUCTS*/

struct s_fork
{
	int				id;
	pthread_mutex_t	fork;
	t_philo			*philo;
};

struct	s_philo
{
	int				id;
	int				meals;
	int				is_dead;
	t_fork			*r_fork;
	t_fork			*l_fork;
	t_dinner		*dinner;
	pthread_t		thread;
	pthread_mutex_t	death;
	pthread_mutex_t	print;
};

struct	s_dinner
{
	int				diners;
	int				to_die;
	int				to_eat;
	int				to_sleep;
	int				times_eat;
	int				philo_died;
	int				keep_eating;
	long unsigned	dinner_start;
	t_philo			*philos;
	t_fork			*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	meals;
	pthread_mutex_t	philo_died_mutex;
};

/*FUNCTIONS*/

void	do_dinner(t_dinner *d);
long	ft_atol(const char *s);
long	timestamp(void);
int		ft_strlen(char *s);
int		check_input(int ac, char **av, t_dinner *dinner);
void	philo_eat(t_philo *d);

#endif
