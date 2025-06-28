#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*ft_strdup(char *src)
{
	char	*cpy;
	int		len;
	int		i;

	if (!src)
		return (NULL);
	len = 0;
	while (src[len])
		len++;
	cpy = (char *) malloc(sizeof(char) * (len + 1));
	if (!cpy)
		return (NULL);
	i = 0;
	while (src[i])
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE];
	char			line[70000];
	static int		buf_pos = 0;
	static int		buf_read = 0;
	unsigned int	i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	while (1)
	{
		if (buf_pos >= buf_read)
		{
			buf_read = read(fd, buffer, BUFFER_SIZE);
			buf_pos = 0;
			if (buf_read <= 0)
				break ;
		}
		line[i++] = buffer[buf_pos++];
		if (buffer[buf_pos - 1] == '\n' || i >= sizeof(line) - 1)
			break ;
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));
}
