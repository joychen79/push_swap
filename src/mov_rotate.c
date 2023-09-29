/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingchen <jingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:12:04 by jingchen          #+#    #+#             */
/*   Updated: 2023/09/29 19:31:06 by jingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	addstack_back(t_stack **stack, t_stack *new)
{
	t_stack	*aux;

	if (!stack)
		return ;
	if (*stack)
	{
			aux = *stack;
		while (aux->next)
				aux = aux->next;
			aux->next = new;
	}
	else
		*stack = new;
}

static void	rotate(t_stack **stack)
{
	t_stack	*aux;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	aux = *stack;
	*stack = (*stack)->next;
	addstack_back(stack, aux);
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
