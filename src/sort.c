/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingchen <jingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:37:57 by jingchen          #+#    #+#             */
/*   Updated: 2023/10/13 17:40:19 by jingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	pb_keep_three(t_stack **stack_a, t_stack **stack_b)
{
	int	pushb;
	int	i;
	int	size;

	size = stack_size(*stack_a);
	pushb = 0;
	i = 0;
	while (size > 3 && i < size && pushb < size / 2)
	{
		if ((*stack_a)->index <= size / 2)
		{
			pb(stack_a, stack_b);
			pushb++;
		}
		else
			ra(stack_a);
		i++;
	}
	while ((size - pushb) > 3)
	{
		pb(stack_a, stack_b);
		pushb++;
	}
}

static void	switch_stack(t_stack **stack_a)
{
	int	least_pos;
	int	size;

	size = stack_size(*stack_a);
	least_pos = find_min_position(stack_a);
	if (least_pos > size / 2)
	{
		while (least_pos < size)
		{
			rra(stack_a);
			least_pos++;
		}
	}
	else
	{
		while (least_pos > 0)
		{
			ra(stack_a);
			least_pos--;
		}
	}
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	pb_keep_three(stack_a, stack_b);
	short_sort(stack_a);
	while (*stack_b)
	{
		find_target_position(stack_a, stack_b);
		find_cost(stack_a, stack_b);
		make_cheapest_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		switch_stack(stack_a);
}
