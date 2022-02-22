#include "ft_printf.h"

int	ft_flag_checker(t_elem *elem, const char *str)
{
	int	i;

	i = 0;
	while (str[i] == '0' || str[i] == '-')
	{
		if (str[i] == '0')
			(elem)->zero = 1;
		if (str[i] == '-')
			(elem)->minus = 1;
		i++;
	}
	if ((elem)->minus)
		(elem)->zero = 0;
	return (i);
}

int	ft_width_checker(t_elem *elem, const char *str, va_list param)
{
	int		i;
	int		wdth;

	i = 0;
	if (str[i] == '*')
	{
		(elem)->width = va_arg(param, int);
		if (elem->width < 0)
		{
			elem->minus = 1;
			elem->zero = 0;
			elem->width *= -1;
		}
		return (1);
	}
	wdth = 0;
	while (ft_isdigit(str[i]))
	{
		wdth = wdth * 10 + str[i] - '0';
		i++;
	}
	(elem)->width = wdth;
	return (i);
}

int	ft_accur_checker(t_elem *elem, const char *str, va_list param)
{
	int	i;
	int	accur;

	i = 0;
	if (str[i] != '.')
	{
		elem->is_dot = 0;
		return (0);
	}
	i++;
	if (str[i] == '*')
	{
		(elem)->accur = va_arg(param, int);
		return (2);
	}
	accur = 0;
	while (ft_isdigit(str[i]))
	{
		accur = accur * 10 + str[i] - '0';
		i++;
	}
	(elem)->accur = accur;
	return (i);
}

void	ft_dec_fill(t_elem *elem, va_list param)
{
	long long int	num;

	num = (va_arg(param, int));
	if (num < 0)
	{
		elem->znak = 1;
		num = -num;
	}
	elem->data_int = num;
}

int	ft_type_checker(t_elem *elem, char s, va_list param)
{
	if (ft_specificator(s))
	{
		(elem)->type = s;
		if (s == 'x' || s == 'X')
			elem->ul = (va_arg(param, unsigned int));
		else if (s == 's')
			elem->data_char = (va_arg(param, char *));
		else if (s == 'd' || s == 'i')
			ft_dec_fill(elem, param);
		else if (s == 'u')
			elem->unint = va_arg(param, unsigned int);
		else if (s == 'p')
			elem->ul = (va_arg(param, unsigned long int));
		else if (s == 'c')
			elem->data_int = va_arg(param, int);
		return (1);
	}
	return (0);
}
