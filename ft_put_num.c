#include "ft_printf.h"

int	ft_puthex(unsigned long num, char *hex_set, char system, int is_dot)
{
	int				i;
	long unsigned	mid;

	i = 15;
	if (system == 'p')
		write(1, "0x", 2);
	if (!num)
	{
		if (!(is_dot && system == 'p'))
			write(1, "0", 1);
		return (ft_howhex_num(num, system, is_dot));
	}
	if (num == 0)
		write(1, "0", 1);
	while (i >= 0)
	{
		mid = num >> (i * 4);
		if (mid != 0 && num >> (i * 4))
			write(1, &hex_set[mid & 15], 1);
		i--;
	}
	return (ft_howhex_num(num, system, is_dot));
}

static void	ft_put(char c, long int n)
{
	if (n)
	{
		ft_put(c, n / 10);
		c = n % 10 + 48;
		write(1, &c, 1);
	}
}

int	ft_putnbr(long long int n)
{
	long long int	num;
	char			c;

	num = n;
	c = 0;
	if (n < 0)
		num *= -1;
	else if (n == 0)
		write(1, "0", 1);
	ft_put(c, num);
	return (ft_howdec_num(n));
}
