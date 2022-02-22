SRCS =  ft_printf.c ft_strings.c ft_flag_checker.c\
		ft_put_num.c ft_count.c\
		ft_show_part.c ft_show_all.c
		
OBJ = $(SRCS:.c=.o)
REM = rm -rf
NAME = libftprintf.a
HEADER = ft_printf.h

$(NAME): $(OBJ) ft_printf.h Makefile
	ar rcs $(NAME) $?

all: $(NAME)

.c.o:
	gcc -Wall -Wextra -Werror -I $(HEADER) -c $< -o $@

clean:
	$(REM) $(OBJ)

fclean:	clean
	$(REM) $(NAME)

re:	fclean all

.PHONY: all clean fclean
