SRCS		= ft_printf_conv_ascii.c ft_printf_conv_int.c ft_printf_list.c ft_printf_put.c ft_printf_utils.c ft_printf.c ft_printf_flags.c

OBJS		= $(SRCS:.c=.o)

OBJSBONUS   = $(BONUS:.c=.o)

NAME		= libftprintf.a

LIBFT		= libft
LIBFT_FILE	= $(LIBFT)/libft.a

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

.c.o:
			$(CC) $(CFLAGS) -c -I libft $< -o $@

$(NAME):	compile_lib $(OBJS)
			ar rc $(NAME) $(OBJS)

all:		$(NAME)

compile_lib:
			$(MAKE) -C $(LIBFT)
			cp $(LIBFT_FILE) $(NAME)

clean:
			$(RM) $(OBJS) $(OBJSBONUS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re compile_lib
