/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:31:35 by isilva-t          #+#    #+#             */
/*   Updated: 2024/07/02 10:31:56 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	order_three(t_list **stack)
{
	t_list	*biggest_node;
	
	if (!stack || !*stack)
		return ;
	if (ft_lstsize(*stack) != 3)
		return ;
	biggest_node = find_biggest_node(*stack);
	if (biggest_node->nbr == (*stack)->nbr)
		ra(stack);
	if (biggest_node->nbr == (*stack)->next->nbr)
		rra(stack);
	if ((*stack)->nbr > (*stack)->next->nbr)
		sa(stack);
}
