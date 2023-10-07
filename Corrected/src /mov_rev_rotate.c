/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingchen <jingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:12:04 by jingchen          #+#    #+#             */
/*   Updated: 2023/10/07 18:14:46 by jingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*static void	rev_rotate(t_stack **stack)
{
	t_stack	*aux;
	t_stack	*last;
	int		i;

	i = 0;
	last = *stack;
	while (i++ < stack_size(*stack) - 1)
		last = last->next;
	aux = *stack;
	while (i++ < stack_size(*stack) - 2)
		aux = aux->next;
	last->next = *stack;
	*stack = last;
	aux->next = NULL;
}*/

static void	rev_rotate(t_stack **stack)
{
	t_stack	*aux;
	t_stack	*last;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	aux = *stack;
	while (aux->next->next)
		aux = aux->next;
	last = aux->next;
	last->next = *stack;
	*stack = last;
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
