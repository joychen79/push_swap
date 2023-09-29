NAME	= push_swap

SRCS	=	src/push_swap.c\
			src/mov_push.c\
			src/mov_rev_rotate.c\
			src/mov_rotate.c\
			src/mov_swap.c\
			src/utils.c\
			src/create_stack.c\
			src/assign_pos_target_index.c\
			src/short_sort.c\
			src/utils_mov.c\
			src/make_move.c\
			src/calcu_cost.c\
			src/sort.c

OBJS	= $(SRCS:.c=.o)

LIBFT				=	libft.a
LIBFT_SRC			=	./libft/

CC					=	gcc
RM					=	rm -f
CFLAGS				=	-Wall -Werror -Wextra


all:		$(LIBFT) $(NAME)

$(LIBFT):
			@make -C libft bonus

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_SRC)$(LIBFT) -o $(NAME)

bonus:		$(LIBFT) $(OBJSBNS)
			@$(CC) $(CFLAGS) $(OBJSBNS) $(LIBFT_SRC)$(LIBFT) -o $(NAME_BONUS)

clean:
			@$(RM) $(NAME) $(OBJS) $(OBJSBNS) $(NAME_BONUS)

fclean:		clean
			@make -C libft fclean

re:			fclean all

.PHONY:		all clean fclean bonus re