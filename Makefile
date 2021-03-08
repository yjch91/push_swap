NAME = checker

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LFLAGS = -L ./libft

LIBS = -lft

SRCS = ft_stack.c utils.c ft_swap.c ft_push.c ft_rotate.c ft_set_stack.c \
	get_next_line.c   ft_checker.c

OBJS = $(SRCS:.c=.o)

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
			make -C ./libft bonus
			$(CC) $(CFLAGS) $(LFLAGS) $(LIBS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)
	make -C ./libft clean

fclean:	clean
		rm -f $(NAME)
		make -C ./libft fclean

re:	fclean all

.PHONY: all clean fclean re
