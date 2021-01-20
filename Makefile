SRCS		= ft_printf.c ft_printf_list.c ft_printf_conv_ascii.c ft_printf_conv_int.c \
			ft_printf_put.c ft_printf_utils.c ft_printf_flags.c

OBJS		= $(SRCS:.c=.o)

HEADER		= ft_printf.h

NAME		= libftprintf.a

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

.c.o:		$(HEADER)
			$(CC) $(CFLAGS) -c $< -o ${<:.c=.o} -I

$(NAME):	$(OBJS)
			$(MAKE) -C libft
			cp libft/libft.a $(NAME)
			ar rcs $(NAME) $?

all bonus:	$(NAME)

clean:
			${MAKE} clean -C libft
			$(RM) $(OBJS)

fclean:		clean
			${MAKE} fclean -C libft
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re
