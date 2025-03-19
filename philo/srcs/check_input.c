#include "../philo.h"

int	parse_input(int ac, char **av, t_program *program)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (ft_atoi(av[i]) > 2147483647 || ft_atoi(av[i]) < 1)
			return (0);
	}
	i = 1;
	while (++i < 5)
	{
		if (ft_atoi(av[i]) < 60)
			return (0);
	}
	program->diners = ft_atoi(av[1]);
	program->to_die = ft_atoi(av[2]);
	program->to_eat = ft_atoi(av[3]);
	program->to_think = ft_atoi(av[4]);
	if (av[5])
		program->times_eat = ft_atoi(av[5]);
	return (1);
}

int check_input(int ac, char **av, t_program *program)
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
