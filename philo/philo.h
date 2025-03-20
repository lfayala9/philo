#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

/*TYPES*/

typedef struct	s_fork		t_fork;
typedef struct	s_philo		t_philo;
typedef struct	s_program	t_program;

/*STRUCTS*/

struct s_fork
{
	pthread_mutex_t	fork;
	t_philo			*philo;
	int				id;
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
	t_philo	*philos;
	t_fork	*forks;
	int		philo_died;
	int		diners;
	int		to_die;
	int		to_eat;
	int		to_think;
	int		times_eat;
};

/*FUNCTIONS*/

int	ft_strlen(char *s);
long ft_atol(const char *s);
int check_input(int ac, char **av, t_program *program);

#endif