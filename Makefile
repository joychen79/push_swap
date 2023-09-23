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

CC					=	gcc
RM					=	rm -f
CFLAGS				=	-Wall -Werror -Wextra


$(LIBFT):
			@make -C libft bonus

all:	$(LIBFT) $(NAME)

$(LIBFT):
			@make -C libft

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT_SRC)$(LIBFT) -o $(NAME)

clean:
			@$(RM) $(NAME) $(OBJS)


fclean:		clean
			@make -C libft fclean

re:			fclean all

.PHONY: all clean fclean re