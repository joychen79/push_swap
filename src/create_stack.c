/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingchen <jingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:04:41 by jingchen          #+#    #+#             */
/*   Updated: 2023/10/24 16:19:25 by jingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	check_digital(char *value)
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
	}
}

static void	check_min_max(char **numbers)
{
	int			i;
	long int	aux;

	i = 0;
	while (numbers[i] != NULL)
	{
		aux = ft_atoi(numbers[i]);
		if (ft_strlen(numbers[i++]) > 10
			|| aux > 2147483647 || aux < -2147483648)
			error_message();
	}
}

int	check_repeat(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (stack->value == tmp->value)
			{
				return (1);
			}
				tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (0);
}

static t_stack	*stack_new_element(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->pos = 0;
	new->target_pos = 0;
	new->cost_a = 0;
	new->cost_b = 0;
	new->next = NULL;
	return (new);
}

t_stack	*create_stack(int ac, char **argv)
{
	t_stack	*stack_a;
	int		i;
	int		j;
	char	**tmp;
	t_stack	*s_tmp;

	i = 1;
	stack_a = NULL;
	while (ac > i)
	{
		j = 0;
		tmp = ft_split(argv[i], ' ');
		check_min_max(tmp);
		while (tmp[j])
		{
			check_digital(tmp[j]);
			s_tmp = stack_new_element(ft_atoi(tmp[j]));
			addstack_back(&stack_a, s_tmp);
			j++;
		}
		free_str(tmp);
		free(tmp);
		i++;
	}
	return (stack_a);
}
