#include "ft_printf.h"

int	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (6);
	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int	ft_specificator(int c)
{
	if (c == 'c' || c == 's' || c == 'd' || c == 'i' || c == 'u')
		return (1);
	else if (c == 'x' || c == 'X' || c == 'p' || c == '%')
		return (1);
	else
		return (0);
}

int	ft_putstri(const char *str, int how)
{
	if (!str)
		write(1, "(null)", how);
	else
		write(1, str, how);
	return (how);
}

int	ft_isdigit(int ch)
{
	if (ch >= 48 && ch <= 57)
		return (1);
	else
		return (0);
}
