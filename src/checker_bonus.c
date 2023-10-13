/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingchen <jingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:03:37 by jingchen          #+#    #+#             */
/*   Updated: 2023/10/13 16:13:51 by jingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	check_move(char *move, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strncmp(move, "sa\n", 3) == 0)
		sa(stack_a);
	else if (ft_strncmp(move, "sb\n", 3) == 0)
		sb(stack_a);
	else if (ft_strncmp(move, "ss\n", 3) == 0)
		ss(stack_a, stack_b);
	else if (ft_strncmp(move, "pa\n", 3) == 0)
		pa(stack_a, stack_b);
	else if (ft_strncmp(move, "pb\n", 3) == 0)
		pb(stack_a, stack_b);
	else if (ft_strncmp(move, "ra\n", 3) == 0)
		ra(stack_a);
	else if (ft_strncmp(move, "rb\n", 3) == 0)
		rb(stack_a);
	else if (ft_strncmp(move, "rr\n", 3) == 0)
		rr(stack_a, stack_b);
	else if (ft_strncmp(move, "rra\n", 3) == 0)
		rra(stack_a);
	else if (ft_strncmp(move, "rrb\n", 3) == 0)
		rrb(stack_a);
	else if (ft_strncmp(move, "rrr\n", 3) == 0)
		rrr(stack_a, stack_b);
	else
		(ft_printf("Error\n"), exit(-1));
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*move;

	stack_a = creat_stack(ac, av);
	stack_b = NULL;
	move = get_next_line(0);
	while (move != NULL)
	{
		check_move(move, &stack_a, &stack_b);
		free(move);
		move = get_next_line(0);
	}
	free(move);
	if (ft_issorted(stack_a, stack_b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
