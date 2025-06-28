#include <unistd.h>

int	ft_strlen(char *str)
{
	int len;

	len = 0;
	while(str[len])
		len++;
	return(len);
}

int	ft_control(char *str, char *search)
{
	int	i;

	if (ft_strlen(str) == 0)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == search[0])
			return (1);
		i++;
	}
	return (0);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_search_and_replace(char *str, char search, char replace)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == search)
			str[i] = replace;
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 4 || ft_strlen(argv[2]) != 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	if (ft_control(argv[1], argv[2]) == 0)
	{
		ft_putstr(argv[1]);
		write(1, "\n", 1);
		return (0);
	}
	ft_search_and_replace(argv[1], argv[2][0], argv[3][0]);
	ft_putstr(argv[1]);
	write(1, "\n", 1);
	return (0);
}
