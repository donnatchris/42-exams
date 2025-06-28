#include <unistd.h>
#include <stdarg.h>

void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_putstr(char *str, int *len)
{
	if (!str)
	{
		ft_putstr("(null)", len);
		return ;
	}
	while (*str)
	{
		ft_putchar(*str, len);
		str++;
	}
}

void	ft_putnbr(long n, int *len)
{
	if (n < 0)
	{
		n = -n;
		ft_putchar('-', len);
	}
	if (n > 9)
		ft_putnbr(n / 10, len);
	ft_putchar(n % 10 + 48, len);
}

void	ft_puthexa(unsigned int n, int *len)
{
	char	*str = "0123456789abcdef";

	if (n > 15)
		ft_puthexa(n / 16, len);
	ft_putchar(str[n % 16], len);
}

int	ft_printf(char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, format);
	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			if (format[i] == 's')
				ft_putstr(va_arg(args, char *), &len);
			else if (format[i] == 'd')
				ft_putnbr(va_arg(args, int), &len);
			else if (format[i] == 'x')
				ft_puthexa(va_arg(args, unsigned int), &len);
			else if (format[i] == '%')
				ft_putchar('%', &len);
			else
				ft_putchar(format[i], &len);
		}
		else
			ft_putchar(format[i], &len);
		i++;
	}
	return (len);
}
