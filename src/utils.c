/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingchen <jingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:57:53 by jingchen          #+#    #+#             */
/*   Updated: 2023/09/15 19:11:50 by jingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **s)
{
	t_stack	*tmp;

	if (s)
	{
		while (*s)
		{
			tmp = (*s)->next;
			free(*s);
			(*s) = tmp;
		}
	}
}

void	free_str(char **lst)
{
	char	*n1;

	if (!lst)
		return ;
	while (*lst)
	{
		n1 = *lst;
		lst++;
		free(n1);
	}
	*lst = NULL;
}

void	error_message(void)
{
	ft_printf("Error\n");
	exit (1);
}
