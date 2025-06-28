#include <unistd.h>

void	ft_putnchar(char *str, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_last(char *str)
{
	char	*backup;
	int		n;

	while (*str)
	{
/*		while (*str == 32 || (*str >= 9 && *str >= 13))
			str++;*/
		backup = str;
		n = 0;
		while (((*str >= 1 && *str <= 8) || (*str >= 14 && *str <= 31) || (*str > 32)) && *str != '\0')
		{
			str++;
			n++;
		}
		while (*str == 32 || (*str >= 9 && *str <= 13))
		{
			str++;
		}
		if (*str == '\0')
		{
			ft_putnchar(backup, n);
			return ;
		}
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	ft_last(av[1]);
	write(1, "\n", 1);
	return (0);
}
