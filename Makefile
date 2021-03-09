NAME = push_swap

NAME_C = checker

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LFLAGS = -L ./libft

LIBS = -lft

SRCS = ft_stack.c utils.c ft_swap.c ft_push.c ft_rotate.c ft_set_stack.c \
	   get_next_line.c

SRCS_C = ft_checker.c

SRCS_P = ft_push_swap.c

OBJS = $(SRCS:.c=.o)

OBJS_C = $(SRCS_C:.c=.o)

OBJS_P = $(SRCS_P:.c=.o)

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS) $(OBJS_C) $(OBJS_P)
			make -C ./libft bonus
			$(CC) $(CFLAGS) $(LFLAGS) $(LIBS) $(OBJS) $(OBJS_C) -o $(NAME_C)
			$(CC) $(CFLAGS) $(LFLAGS) $(LIBS) $(OBJS) $(OBJS_P) -o $(NAME)

clean:
	rm -f $(OBJS) $(OBJS_C) $(OBJS_P)
	make -C ./libft clean

fclean:	clean
		rm -f $(NAME) $(NAME_C)
		make -C ./libft fclean

re:	fclean all

.PHONY: all clean fclean re
