#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_elem
{
	int					minus;
	int					znak;
	int					accur;
	int					zero;
	int					width;
	int					type;
	int					is_dot;
	char				*data_char;
	long int			data_int;
	unsigned long		ul;
	unsigned long int	unint;
	int					chr;
}				t_elem;

t_elem	ft_newel(void);
void	ft_str_accur(t_elem *elem);
int		ft_putnbr(long long int n);
int		ft_strlen(const char *str);
int		ft_puthex(unsigned long num, char *hex_set, char system, int is_dot);
int		ft_isalpha(int ch);
int		ft_specificator(int c);
int		ft_howhex_num(unsigned long num, char system, int is_dot);
int		ft_printf(const char *str, ...);
int		ft_flag_checker(t_elem *elem, const char *str);
int		ft_width_checker(t_elem *elem, const char *str, va_list param);
int		ft_isdigit(int ch);
int		ft_accur_checker(t_elem *elem, const char *str, va_list param);
int		ft_type_checker(t_elem *elem, char s, va_list param);
int		ft_howdec_num(long long int num);
int		ft_how_symbols(t_elem *elem);
int		ft_is_numtype_zero(t_elem *elem);
int		ft_add(t_elem *elem);
int		ft_show_type(t_elem *elem);
int		ft_putstri(const char *str, int how);
int		ft_show_accur(t_elem *elem);
int		ft_show(t_elem *elem);
int		ft_write(t_elem *elem, const char *str, va_list param);
void	ft_change_accur(t_elem *elem);
int		ft_minus_case(t_elem *elem, char add, int i, int res);
int		ft_stand_case(t_elem *elem, char add, int res, int i);

#endif
