/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingchen <jingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 13:23:56 by jingchen          #+#    #+#             */
/*   Updated: 2023/09/15 20:04:06 by jingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <string.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				pos;
	int				target;
	int				cost_a;
	int				cost_b;
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	free_stack(t_stack **s);
void	free_str(char **lst);
void	error_message(void);
void	valid_stack(t_stack **stack);
t_stack	*create_stack(int ac, char **argv);

#endif