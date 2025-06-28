#include <stdlib.h>

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	len;

	while (str[len])
		len++;
	return (len);
}

char *ft_strdup(char *src)
{
	int	i;
	char *copy;

	copy = (char *) malloc ((ft_strlen(src) + 1) * sizeof (char));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
/*
int	main(void)
{
	char src[] = "Salut les gars!";
	printf("%s\n", ft_strdup(src));
	return (0);
}
*/
