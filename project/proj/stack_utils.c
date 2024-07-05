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

void	index_stack(t_list *stack)
{
	unsigned int	i;
	t_list			*lowest_node;

	i = 0;
	if (!stack && !stack->nbr_to_index)
		return ;
	lowest_node = find_lowest_node(stack);
	while (lowest_node->nbr_to_index != (long)2147483647 + 1)
	{
		lowest_node->index_a = i++;
		lowest_node->nbr_to_index = (long)2147483647 + 1;
		lowest_node = find_lowest_node(stack);
	}
}

void	make_index_again(t_list *stack)
{
	int	index;
	int	lstsize;

	index = 0;
	if (!stack)
		return ;
	lstsize = ft_lstsize(stack);
	while (stack)
	{
		stack->index = index++;
		if (stack->index < lstsize / 2)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
	}
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
		if (stack->nbr_to_index < lowest_node->nbr_to_index)
			lowest_node = stack;
	}
	return (lowest_node);
}
