/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingchen <jingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:04:41 by jingchen          #+#    #+#             */
/*   Updated: 2023/09/23 16:15:34 by jingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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
		while (tmp[j])
		{
			s_tmp = stack_new_element(ft_atoi(tmp[j]));
			valid_stack(stack_a);
			ft_lstadd_back(&stack_a, s_tmp);
			j++;
		}
		free_str(tmp);
		free(tmp);
		i++;
	}
	return (stack_a);
}

