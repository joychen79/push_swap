/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingchen <jingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 13:23:56 by jingchen          #+#    #+#             */
/*   Updated: 2023/09/09 13:35:03 by jingchen         ###   ########.fr       */
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

#endif