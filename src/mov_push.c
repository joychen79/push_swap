/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingchen <jingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:44:21 by jingchen          #+#    #+#             */
/*   Updated: 2023/10/07 17:43:47 by jingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	push(t_stack **src, t_stack **dest)
{
	t_stack	*aux;

	if (*src == NULL || src == NULL || dest == NULL)
		return ;
	aux = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = aux;
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	ft_printf ("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_printf ("pb\n");
}
