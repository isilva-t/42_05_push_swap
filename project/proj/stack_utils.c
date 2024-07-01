/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:33:04 by isilva-t          #+#    #+#             */
/*   Updated: 2024/07/01 13:33:17 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*find_last_node(t_list *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

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

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*counter;

	size = 0;
	counter = (t_list *)lst;
	while (counter)
	{
		size++;
		counter = counter->next;
	}
	return (size);
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
