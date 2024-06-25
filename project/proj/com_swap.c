/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:24:03 by isilva-t          #+#    #+#             */
/*   Updated: 2024/06/25 12:28:24 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	swap(t_list **stack)
{
	t_list	*node_to_first;
	t_list	*node_to_second;
	t_list	*third_node;

	node_to_first = NULL;
	node_to_second = NULL;
	third_node = NULL;
	if (!*stack && !(*stack)->next)
		return (0);
	node_to_first = (*stack)->next;
	node_to_second = *stack;
	if ((*stack)->next->next)
	{
		third_node = (*stack)->next->next;
		third_node->prev = node_to_second;
	}
	node_to_second->prev = node_to_first;
	node_to_second->next = third_node;
	node_to_first->next = node_to_second;
	node_to_first->prev = NULL;
	*stack = node_to_first;
	return (1);
}

void	sa(t_list **stack)
{
	if (swap(stack))
		ft_printf("sa\n");
}

void	sb(t_list **stack)
{
	if (swap(stack))
		ft_printf("sb\n");
}

void	ss(t_list **a, t_list **b)
{
	if (swap(a) && swap(b))
		ft_printf("ss\n");
}
