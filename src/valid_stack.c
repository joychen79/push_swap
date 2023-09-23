/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingchen <jingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:04:41 by jingchen          #+#    #+#             */
/*   Updated: 2023/09/23 16:25:03 by jingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	check_repeat(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		while (tmp)
		{
			if ((*stack)->value == tmp->value)
			{
				return (0);
			}
				tmp = tmp->next;
		}
		*stack = (*stack)->next;
	}
	return (1);
}

static int	check_min_max(t_stack **stack)
{
	int			i;
	long int	aux;

	i = 0;
	while (*stack)
	{
		aux = (*stack)->value;
		if (aux > INT_MAX || aux < INT_MIN)
			return (0);
	}
	return (1);
}

static int	check_digital(t_stack **stack)
{
	int		i;
	char	*number;

	i = 0;
	number = ft_itoa((*stack)->value);
	while (number[i])
	{
		if (number[0] == '-' || number[0] == '+' && ft_strlen(number) > 1)
			i++;
		if (!ft_isdigit(number[i]))
			return (0);
	i++;
	}
	return (1);
}

void	valid_stack(t_stack **stack)
{
	if (stack == NULL || *stack == NULL)
	{
		free_stack (stack);
		error_message();
	}
	if (!check_repeat(stack) || !check_min_max(stack) || !check_digital(stack))
	{
		free_stack (stack);
		error_message();
	}
}
