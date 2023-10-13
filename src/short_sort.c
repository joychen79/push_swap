/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingchen <jingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:18:29 by jingchen          #+#    #+#             */
/*   Updated: 2023/10/13 15:25:09 by jingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static int	find_highest_index(t_stack *stack)
{
	int		max;

	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

void	short_sort(t_stack **stack)
{
	int		highest;

	while (!(is_sorted(*stack)))
	{
		highest = find_highest_index(*stack);
		if ((*stack)->index == highest)
			ra(stack);
		else if ((*stack)->next->index == highest)
			rra(stack);
		if ((*stack)->index > (*stack)->next->index)
			sa(stack);
	}
}
