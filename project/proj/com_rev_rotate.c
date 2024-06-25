/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 10:35:07 by isilva-t          #+#    #+#             */
/*   Updated: 2024/06/25 12:31:34 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	rotate(t_list **stack)
{
	t_list	*last_node;
	if (!*stack && !(*stack)->next)
		return(0);
	last_node = find_last_node(*stack);
	last_node->prev->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	*stack = last_node;
	return (1);
}

void	rra(t_list **a)
{
	if(rotate(a))
		ft_printf("rra\n");
}

void	rrb(t_list **b)
{
	if(rotate(b))
		ft_printf("rrb\n");
}

void	rrr(t_list **a, t_list **b)
{
	if (rotate(a) && rotate(b))
		ft_printf("rrr\n");
}
