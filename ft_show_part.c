#include "ft_printf.h"

int	ft_show_accur(t_elem *elem)
{
	int		i;
	int		cur_acc;
	char	c;
	int		res;

	i = 0;
	res = 0;
	c = elem->type;
	i = elem->accur;
	if (c == 'd' || c == 'i')
		cur_acc = ft_howdec_num(elem->data_int);
	else if (c == 'u')
		cur_acc = ft_howdec_num(elem->unint);
	else if (c == 'x' || c == 'X')
		cur_acc = ft_howhex_num(elem->ul, 'x', elem->is_dot);
	else
		return (0);
	while (i-- > cur_acc)
		res += ft_putstri("0", 1);
	return (res);
}

int	ft_show_type(t_elem *elem)
{
	if (elem->type == 'c')
		return (ft_putstri((char *)&(elem->data_int), 1));
	else if (elem->type == 's')
		return (ft_putstri(elem->data_char, elem->accur));
	else if (elem->type == 'p')
		return (ft_puthex(elem->ul, "0123456789abcdef", 'p', elem->is_dot));
	else if (elem ->type == 'd' || elem->type == 'i')
		return (ft_putnbr(elem->data_int));
	else if (elem->type == 'X')
		return (ft_puthex(elem->ul, "0123456789ABCDEF", 'X', elem->is_dot));
	else if (elem->type == 'x')
		return (ft_puthex(elem->ul, "0123456789abcdef", 'x', elem->is_dot));
	else if (elem->type == '%')
		return (ft_putstri("%", 1));
	else if (elem->type == 'u')
		return (ft_putnbr(elem->unint));
	else
		return (ft_putstri((char *)&(elem->type), 1));
}

int	ft_add(t_elem *elem)
{
	char	c;
	int		add_ac;
	int		add_w;

	c = elem->type;
	add_ac = elem->accur - ft_how_symbols(elem);
	if (c == 's' || c == 'c')
		add_w = elem->width - elem->accur;
	else if (add_ac < 0)
		add_w = elem->width - ft_how_symbols(elem) - elem->znak;
	else
		add_w = elem->width - (ft_how_symbols(elem) + add_ac) - elem->znak;
	if (add_w <= 0)
		return (0);
	return (add_w);
}
