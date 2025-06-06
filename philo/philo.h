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

/*INCLUDES*/
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
	int				is_eating;
	int				is_thinking;
	int				is_sleeping;
	long			last_meal;
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
	long			dinner_start;
	t_fork			*forks;
	t_philo			*philos;
	pthread_mutex_t	dead;
	pthread_mutex_t	meals;
	pthread_mutex_t	print;
	pthread_mutex_t	take_forks;
};

/*FUNCTIONS*/
int		ft_strlen(char *s);
int		grab_if3(t_philo *p);
int		time_over(t_philo *p);
int		time_over(t_philo *p);
int		check_die(t_philo *p);
int		grab_forks(t_philo *p);
int		keep_eating(t_philo *p);
int		check_input(int ac, char **av, t_dinner *dinner);
void	philo_eat(t_philo *d);
void	init_sleep(t_philo *p);
void	do_dinner(t_dinner *d);
void	philo_kill(t_philo *p);
void	philo_think(t_philo *p);
void	philo_sleep(t_philo *p);
void	do_usleep(t_philo *p, long duration);
void	print_mutex(t_philo *p, char *msg, long time, int id);
long	timestamp(void);
long	ft_atol(const char *s);

#endif
