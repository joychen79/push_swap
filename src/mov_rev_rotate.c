/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingchen <jingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:12:04 by jingchen          #+#    #+#             */
/*   Updated: 2023/09/23 16:24:24 by jingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	rev_rotate(t_stack **stack)
{
	t_stack	*aux;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	aux = ft_lstlast(*stack);
	*stack = (*stack)->next;
	ft_lstadd_front(stack, aux);
	aux->next = NULL;
}

void	rra(t_stack **stack_a)
{
	rev_rotate (stack_a);
	ft_printf ("rra\n");
}

void	rrb(t_stack **stack_b)
{
	rev_rotate (stack_b);
	ft_printf ("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate (stack_a);
	rev_rotate (stack_b);
	ft_printf ("rrr\n");
}
