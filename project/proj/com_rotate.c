/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 09:45:24 by isilva-t          #+#    #+#             */
/*   Updated: 2024/06/25 10:01:01 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	rotate(t_list **stack)
{
	t_list	*new_bottom;
	t_list	*last_node;

	if (!stack && !(*stack)->next)
		return (0);

	last_node = find_last_node(*stack);
	
	new_bottom = *stack;
	last_node->next = new_bottom;

	(*stack)->prev = NULL;
	*stack = (*stack)->next;

	new_bottom->prev = last_node;
	new_bottom->next = NULL;

	return (1);
}

void	ra(t_list **a)
{
	if (rotate(a))
		ft_printf("ra\n");
}

void	rb(t_list **b)
{
	if (rotate(b))
		ft_printf("rb\n");
}

void	rr(t_list **a, t_list **b)
{
	if (rotate(a) && rotate(b))
		ft_printf("rr\n");
}
