/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingchen <jingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:57:53 by jingchen          #+#    #+#             */
/*   Updated: 2023/10/04 18:30:50 by jingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_stack(t_stack **s)
{
	t_stack	*tmp;

	if (s)
	{
		while (*s)
		{
			tmp = (*s)->next;
			printf("hola%p %d\n", *s, (*s)->value);
			free(*s);
			*s = tmp;
		}
		free(s);
	}
}

void	free_str(char **lst)
{
	int	i;

	i = 0;
	while (lst[i])
	{
		free(lst[i]);
		i++;
	}
	lst = NULL;
}

void	error_message(void)
{
	ft_printf("Error\n");
	exit (1);
}

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}
