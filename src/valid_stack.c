/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingchen <jingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:04:41 by jingchen          #+#    #+#             */
/*   Updated: 2023/09/29 15:06:16 by jingchen         ###   ########.fr       */
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
	ft_printf("no repeat\n");
	return (1);
}

/*static int	check_min_max(t_stack **stack)
{
	long int	aux;

	while (*stack)
	{
		aux = (*stack)->value;
		if (aux > 214748367 || aux < -214748368)
			{
				ft_printf("no entre min - max\n");
				return (0);
			}
		else
			ft_printf("entre min - max\n");
	}
	return (1);
}
*/

static int	check_min_max(char **numbers)
{
	int			i;
	long int	aux;

	i = 0;
	while (numbers[i] != NULL)
	{
		aux = ft_atoi(numbers[i]);
		if (ft_strlen(numbers[i++]) > 9
			|| aux > 214748367 || aux < -214748368)
		{
			ft_printf ("out of min-max\n");
			free_str(numbers);
			return (0);
		}
	}
	ft_printf ("entre min-max\n");
	return (1);
}

//DELETE THIS!!!
static void	visualize_list(t_stack *stack)
{
	while (stack)
	{
		ft_printf("%i\n", (stack->value));
		stack = stack->next;
	}
	ft_printf("\n");
}

void	check_digital(char *value)
{
	int		i;

	i = 0;
	while (value[i])
	{
		if ((value[0] == '-' || value[0] == '+') && ft_strlen(value) > 1)
			i++;
		while (value[i])
		{
			if (!ft_isdigit(value[i]))
				error_message();
		i++;
		}
		ft_printf ("all digital\n");
	}
	//return (1);
}

void	valid_stack(t_stack **stack)
{
	visualize_list(*stack);
	if (stack == NULL)
	{
		ft_printf("no stack created\n");
		free_stack (stack);
		error_message();
	}
	if (!check_repeat(stack) || !check_min_max(stack))
	{
		free_stack (stack);
		error_message();
	}
}
