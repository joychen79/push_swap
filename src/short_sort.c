/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingchen <jingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:18:29 by jingchen          #+#    #+#             */
/*   Updated: 2023/09/23 16:59:45 by jingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	short_sort(t_stack **stack)
{
	int	min_idx_pos;

	min_idx_pos = find_min_position(stack);
	if (is_sorted(stack) == 1)
		return ;
	if (min_idx_pos > stack_size(stack) / 2)
	{
		while (min_idx_pos < stack_size(stack))
		{
			rra(stack);
			min_idx_pos++;
		}
	}
	else
	{
		while (min_idx_pos > 0)
		{
			ra(stack);
			min_idx_pos--;
		}
	}
}


