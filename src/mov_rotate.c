/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingchen <jingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:12:04 by jingchen          #+#    #+#             */
/*   Updated: 2023/09/09 16:47:05 by jingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*aux;
	t_stack	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	aux = *stack;
	*stack = (*stack)->next;
	ft_lstadd_back(stack, aux);
	aux->next = NULL;
}

void	ra(t_stack **stack_a)
{
	rotate (stack_a);
	ft_printf ("ra\n");
}

void	rb(t_stack **stack_b)
{
	rotate (stack_b);
	ft_printf ("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate (stack_a);
	rotate (stack_b);
	ft_printf ("rr\n");
}
