#include "../philo.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while(s[i])
		i++;
	return (i);
}

long ft_atol(const char *s)
{
	size_t  i;
	long	result;
    int		sign;

    i = 0;
    result = 0;
    sign = 1;
    while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
            i++;
    if (s[i] == '-')
            sign = -1;
    if (s[i] == '-' || s[i] == '+')
            i++;
    while (s[i] >= '0' && s[i] <= '9')
            result = result * 10 + (s[i++] - '0');
    return (sign * result);
}
