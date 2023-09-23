NAME	= push_swap

SRCS	=	src/push_swap.c\
			src/mov_push.c\
			src/mov_rev_rotate.c\
			src/mov_rotate.c\
			src/mov_swap.c\
			src/utils.c\
			src/create_stack.c\
			src/valid_stack.c\
			src/assign_index.c\
			src/assign_pos_target.c\
			src/short_sort.c

OBJS	= $(SRCS:.c = .o)

AR			=	ar -rcs
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra

RM			= 	rm -rf

LIBFT				=	libft.a
LIBFT_SRC			=	./libft/

all:	$(LIBFT) $(NAME)

$(LIBFT):
			@make -C libft

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT_SRC)$(LIBFT) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)
			@make -C libft fclean

re:			fclean all

.PHONY: all bonus clean fclean re