#include "ft_printf.h"

int	ft_how_symbols(t_elem *elem)
{
	char	c;

	c = elem->type;
	if (c == 'd' || c == 'i')
		return (ft_howdec_num(elem->data_int));
	else if (c == 'x' || c == 'X')
		return (ft_howhex_num(elem->ul, c, elem->is_dot));
	else if (c == 'p')
		return (ft_howhex_num(elem->ul, c, elem->is_dot));
	else if (c == 's')
		return (ft_strlen(elem->data_char));
	else if (c == 'c' || c == '%')
		return (1);
	else if (c == 'u')
		return (ft_howdec_num(elem->unint));
	else
		return (0);
}

int	ft_howhex_num(unsigned long num, char system, int is_dot)
{
	int				i;
	long unsigned	mid;
	int				res;

	i = 15;
	res = 0;
	if (system == 'p')
		res += 2;
	if (!num)
	{
		if (!(is_dot && system == 'p'))
			res++;
		return (res);
	}
	if (num == 0)
		return (res + 1);
	while (i >= 0)
	{
		mid = num >> (i * 4);
		if (mid != 0 && num >> (i * 4))
			res++;
		i--;
	}
	return (res);
}

int	ft_howdec_num(long long int num)
{
	int	res;

	res = 0;
	if (num < 0)
	{
		res++;
		num *= -1;
	}
	if (num == 0)
		return (1);
	while (num)
	{
		res++;
		num /= 10;
	}
	return (res);
}
