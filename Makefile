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
			src/make_move.c\
			src/calcu_cost.c\
			src/sort.c

OBJS	= $(SRCS:.c=.o)

NAME_BONUS			=	checker
BONUS_SRC			=	src/mov_push.c\
						src/mov_rev_rotate.c\
						src/mov_rotate.c\
						src/mov_swap.c\
						src/utils.c\
						src/create_stack.c\
						src/short_sort.c\
						src/checker_bonus.c

OBJSBNS			= $(BONUS_SRC:.c=.o)

LIBFT				=	libft.a
LIBFT_SRC			=	./libft/

CC					=	gcc
RM					=	rm -f
CFLAGS				=	-Wall -Werror -Wextra -g3 -fsanitize=address


all:		$(LIBFT) $(NAME)

$(LIBFT):
			@make -C libft bonus

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_SRC)$(LIBFT) -o $(NAME)

bonus:		$(LIBFT) $(OBJSBNS)
			@$(CC) $(CFLAGS) $(OBJSBNS) $(LIBFT_SRC)$(LIBFT) -o $(NAME_BONUS)

clean:
			@$(RM) $(OBJS) $(OBJSBNS)

fclean:		clean
			@$(RM) $(NAME) $(NAME_BONUS)
			@make -C libft fclean

re:			fclean all

.PHONY:		all clean fclean bonus re