/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingchen <jingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:03:37 by jingchen          #+#    #+#             */
/*   Updated: 2023/10/13 17:53:43 by jingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	check_move(char *move, t_stack **stack_a, t_stack **stack_b, int l)
{
	if (ft_strncmp(move, "sa\n", l) == 0)
		sa(stack_a);
	else if (ft_strncmp(move, "sb\n", l) == 0)
		sb(stack_b);
	else if (ft_strncmp(move, "ss\n", l) == 0)
		ss(stack_a, stack_b);
	else if (ft_strncmp(move, "pa\n", l) == 0)
		pa(stack_a, stack_b);
	else if (ft_strncmp(move, "pb\n", l) == 0)
		pb(stack_a, stack_b);
	else if (ft_strncmp(move, "ra\n", l) == 0)
		ra(stack_a);
	else if (ft_strncmp(move, "rb\n", l) == 0)
		rb(stack_b);
	else if (ft_strncmp(move, "rr\n", l) == 0)
		rr(stack_a, stack_b);
	else if (ft_strncmp(move, "rra\n", l) == 0)
		rra(stack_a);
	else if (ft_strncmp(move, "rrb\n", l) == 0)
		rrb(stack_b);
	else if (ft_strncmp(move, "rrr\n", l) == 0)
		rrr(stack_a, stack_b);
	else
		(ft_printf("Error\n"), exit(-1));
}

int	main(int ac, char **av)
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	char			*move;
	unsigned int	len;

	stack_a = create_stack(ac, av);
	stack_b = NULL;
	move = get_next_line(0);
	while (move != NULL)
	{
		len = ft_strlen(move);
		check_move(move, &stack_a, &stack_b, len);
		free(move);
		move = get_next_line(0);
	}
	free(move);
	if (is_sorted(stack_a) && stack_b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
