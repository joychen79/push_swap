/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingchen <jingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:04:41 by jingchen          #+#    #+#             */
/*   Updated: 2023/09/27 20:43:47 by jingchen         ###   ########.fr       */
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
	new->pos = -1;
	new->target_pos = -1;
	new->cost_a = -1;
	new->cost_b = -1;
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
			check_digital(tmp[j]);
			s_tmp = stack_new_element(ft_atoi(tmp[j]));
			addstack_back(&stack_a, s_tmp);
			valid_stack(&stack_a);
			j++;
		}
		free_str(tmp);
		free(tmp);
		i++;
	}
	return (stack_a);
}

/*static t_stack	*read_num(char *argv)
{
	t_stack	*s_tmp;
	char	**num;
	int		i;

	i = 0;
	s_tmp = NULL;
	check_digital(argv);
	num = ft_split(argv, ' ');
	while (num[i])
	{
		s_tmp = stack_new_element(ft_atoi(num[i]));
		return (s_tmp);
		i++;
	}
	free_str(num);
	free(num);
	return (s_tmp);
}	

t_stack	*create_stack(int ac, char **argv)
{
	t_stack	*stack_a;
	int		i;
	t_stack	*s_tmp;

	stack_a = NULL;
	i = 1;
	while (ac > i)
	{
		s_tmp = read_num(argv[i]);
		addstack_back(&stack_a, s_tmp);
		valid_stack(&stack_a);
		i++;
	}
	return (stack_a);
}
*/