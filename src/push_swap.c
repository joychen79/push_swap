/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingchen <jingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 13:36:25 by jingchen          #+#    #+#             */
/*   Updated: 2023/09/29 17:42:17 by jingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (!is_sorted(*stack_a) && stack_size == 2)
		sa(stack_a);
	else if (!is_sorted(*stack_a) && stack_size == 3)
		short_sort(stack_a);
	else if (!is_sorted(*stack_a) && stack_size > 3)
		sort(stack_a, stack_b);
}

/*static void	visualize_list(t_stack *stack)
{
	while (stack)
	{
		ft_printf("%i ", (stack->value));
		stack = stack->next;
	}
	ft_printf("\n");
}*/

/*void	ft_leaks()
{
	system("leaks push_swap");
	atexit(ft_leaks);
}*/

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		len;

	if (argc < 2)
		return (0);
	stack_b = NULL;
	stack_a = create_stack(argc, argv);
	//visualize_list(stack_a);
	len = stack_size(stack_a);
	ft_printf("%d\n", len);
	if (!stack_a)
		error_message();
	assign_index(stack_a, len + 1);
	push_swap(&stack_a, &stack_b, len);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
