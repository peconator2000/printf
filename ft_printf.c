#include "ft_printf.h"

t_elem	ft_newel(void)
{
	t_elem	el;

	el.zero = 0;
	el.znak = 0;
	el.minus = 0;
	el.type = 0;
	el.width = 0;
	el.accur = -1;
	el.data_int = 0;
	el.data_char = NULL;
	el.ul = 0;
	el.is_dot = 1;
	el.chr = 0;
	el.unint = 0;
	return (el);
}

int	ft_write(t_elem *elem, const char *str, va_list param)
{
	int	i;

	i = 0;
	i += ft_flag_checker(elem, &str[i]);
	i += ft_width_checker(elem, &str[i], param);
	i += ft_accur_checker(elem, &str[i], param);
	i += ft_type_checker(elem, str[i], param);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	t_elem	newel;
	va_list	param;
	int		res;

	if (!str)
		return (0);
	i = 0;
	res = 0;
	va_start(param, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			newel = ft_newel();
			i += ft_write(&newel, &str[i + 1], param) + 1;
			res += ft_show(&newel);
		}
		else
			res += ft_putstri(&str[i++], 1);
	}
	va_end(param);
	return (res);
}
