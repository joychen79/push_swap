/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mov.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingchen <jingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:14:02 by jingchen          #+#    #+#             */
/*   Updated: 2023/09/29 19:27:22 by jingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*t_stack	*last_stack(t_stack *stack)
{
	t_stack	*aux;

	aux = stack;
	while (stack)
	{
		aux = stack->next;
	}
	return (aux);
}*/

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

/*void	addstack_front(t_stack **stack, t_stack *new)
{
	if (stack && new)
	{
		new -> next = *stack;
		*stack = new;
	}
}*/
