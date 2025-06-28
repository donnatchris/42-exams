#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	ft_change(char c)
{
	int	i;

	if (c >= 'a' && c <= 'z')
	{
		i = 0;
		while (i < 13)
		{
			if (c == 'z')
				c = 'a';
			else
				c++;
			i++;
		}
	}
	if (c >= 'A' && c <= 'Z')
	{
		i = 0;
		while (i < 13)
		{
			if (c == 'Z')
				c = 'A';
			else
				c++;
			i++;
		}
	}
	return (c);
}

void	ft_rot_13(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || str[i] >= 'A' && str[i] <= 'Z')
			ft_putchar(ft_change(str[i]));
		else
			ft_putchar(str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	ft_rot_13(argv[1]);
	write(1, "\n", 1);
	return (0);
}
