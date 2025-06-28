#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_repeat(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			while (j < (str[i] - 96))
			{
				ft_putchar(str[i]);
				j++;
			}
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			while (j < (str[i] - 64))
			{
				ft_putchar(str[i]);
				j++;
			}
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "\n", 1);

	return (0);
	}
	ft_repeat(av[1]);
	write(1, "\n", 1);
	return (0);
}
