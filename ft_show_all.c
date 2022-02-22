#include "ft_printf.h"

void	ft_change_accur(t_elem *elem)
{
	char	c;

	c = elem->type;
	if ((c == 'c' || c == 's'))
	{
		if (c == 's' && (!(elem->is_dot)
				|| elem->accur > ft_strlen(elem->data_char)))
			elem->accur = ft_strlen(elem->data_char);
		else if (c == 's' && elem->accur < 0)
			elem->accur = ft_strlen(elem->data_char);
		else if (c == 'c')
			elem->accur = 1;
	}
	else if (c == 'p' || c == '%')
		elem->accur = 0;
}

int	ft_is_numtype_zero(t_elem *elem)
{
	char	c;

	c = elem->type;
	if (c == 'd' || c == 'i')
	{
		if (elem->data_int == 0 && elem->accur == 0)
			return (0);
	}
	else if (c == 'u')
	{
		if (elem->unint == 0 && elem->accur == 0)
			return (0);
	}
	else if (c == 'x' || c == 'X')
	{
		if (elem->ul == 0 && elem->accur == 0)
			return (0);
	}
	return (1);
}

int	ft_minus_case(t_elem *elem, char add, int i, int res)
{
	int	tmp;

	if (elem->znak)
		res += ft_putstri("-", 1);
	ft_change_accur(elem);
	res += ft_show_accur(elem);
	if (ft_is_numtype_zero(elem))
		res += ft_show_type(elem);
	else if (elem->width != 0)
		res += ft_putstri(" ", 1);
	tmp = ft_add(elem);
	if (!ft_is_numtype_zero(elem))
		add = ' ';
	while (i++ < tmp)
		res += ft_putstri(&add, 1);
	return (res);
}

int	ft_stand_case(t_elem *elem, char add, int res, int i)
{
	int	tmp;

	if (elem->accur && elem->zero)
		add = '0';
	ft_change_accur(elem);
	tmp = ft_add(elem);
	if (elem->accur > 0)
		add = ' ';
	if (elem->znak && add == '0')
		res += ft_putstri("-", 1);
	if (!ft_is_numtype_zero(elem))
		add = ' ';
	while (i++ < tmp)
		res += ft_putstri(&add, 1);
	if (elem->znak && add != '0')
		res += ft_putstri("-", 1);
	res += ft_show_accur(elem);
	if (ft_is_numtype_zero(elem))
		res += ft_show_type(elem);
	else if (elem->width != 0)
		res += ft_putstri(" ", 1);
	return (res);
}

int	ft_show(t_elem *elem)
{
	int		res;
	char	add;

	res = 0;
	add = ' ';
	if (elem->minus)
		res += ft_minus_case(elem, add, 0, 0);
	else
		res += ft_stand_case(elem, add, 0, 0);
	return (res);
}
