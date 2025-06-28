#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_rev(char *str)
{
	int	len;
	int i;

	len = ft_strlen(str);
	i = 1;
	while (i <= len)
	{
		ft_putchar(str[len - i]);
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
	ft_rev(av[1]);
	write(1, "\n", 1);
	return (0);
}
