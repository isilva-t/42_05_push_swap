/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:33:04 by isilva-t          #+#    #+#             */
/*   Updated: 2024/07/02 17:50:48 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_not_sorted(t_list *stack)
{
	if (!stack->next && !stack)
		return (-1);
	while (stack->next)
	{
		stack = stack->next;
		if (stack->nbr < stack->prev->nbr)
			return (1);
	}
	return (0);
}

t_list	*find_biggest_node(t_list *stack)
{
	t_list	*biggest_node;
	if (!stack)
		return (NULL);
	biggest_node = stack;
	while (stack->next)
	{
		stack = stack->next;
		if (stack->nbr > biggest_node->nbr)
			biggest_node = stack;
	}
	return (biggest_node);
}

t_list	*find_lowest_node(t_list *stack)
{
	t_list	*lowest_node;
	if (!stack)
		return (NULL);
	lowest_node = stack;
	while (stack->next)
	{
		stack = stack->next;
		if (stack->nbr < lowest_node->nbr)
			lowest_node = stack;
	}
	return (lowest_node);
}
