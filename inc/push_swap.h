/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingchen <jingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 13:23:56 by jingchen          #+#    #+#             */
/*   Updated: 2023/09/27 20:19:49 by jingchen         ###   ########.fr       */
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
	int				target_pos;
	int				cost_a;
	int				cost_b;
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

t_stack	*last_stack(t_stack **stack);
void	addstack_back(t_stack **stack, t_stack *new);
void	addstack_front(t_stack **stack, t_stack *new);
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
int		is_sorted(t_stack **stack);
int		stack_size(t_stack **stack);
t_stack	*create_stack(int ac, char **argv);
void	valid_stack(t_stack **stack);
void	assign_index(t_stack **stack, int stack_size);
int		find_highest_index(t_stack **stack);
void	assign_position(t_stack **stack);
int		find_min_position(t_stack **stack);
void	find_target_position(t_stack **stack_a, t_stack **stack_b);
void	short_sort(t_stack **stack);
void	check_digital(char *value);

#endif