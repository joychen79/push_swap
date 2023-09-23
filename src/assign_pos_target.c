/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_pos_target.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingchen <jingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 12:59:00 by jingchen          #+#    #+#             */
/*   Updated: 2023/09/23 16:59:14 by jingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//在stack_a的数值按位置排序
void	assign_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

//找到最小数值的位置序号

int	find_min_position(t_stack **stack)
{
	t_stack	*temp;
	int		min_index;
	int		min_pos;

	temp = *stack;
	min_index = INT_MAX;
	assign_position(stack);
	min_pos = temp->pos;
	while (temp)
	{
		if (temp->index < min_index)
		{
			min_index = temp->index;
			min_pos = temp->pos;
		}
		temp = temp->next;
	}
	return (min_pos);
}
//从 stack_a 往 stack_b 里发送数值时，找每个数值的应该所在的位置

static int	target_position(t_stack **stack_a, int index_b,
											int target_idx, int target_pos)
{
	t_stack	*a;

	a = *stack_a;
	while (a)
	{
		if (a->index > index_b && a->index < target_idx)
		{
			target_idx = a->index;
			target_pos = a->pos;
		}
		a = a->next;
	}
	if (target_idx != INT_MAX)
		return (target_pos);
	a = *stack_a;
	while (a)
	{
		if (a->index < target_idx)
		{
			target_idx = a->index;
			target_pos = a->pos;
		}
		a = a->next;
	}
	return (target_pos);
}

//在stack_b里位置排序

void	find_target_position(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*b;
	int		target_pos;

	b = *stack_b;
	assign_position(stack_a);
	assign_position(stack_b);
	target_pos = 0;
	while (b)
	{
		target_pos = target_position(stack_a, b->index, INT_MAX, target_pos);
		b->target_pos = target_pos;
		b = b->next;
	}
}
