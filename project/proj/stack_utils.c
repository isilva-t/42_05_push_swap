/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:33:04 by isilva-t          #+#    #+#             */
/*   Updated: 2024/06/20 16:39:19 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*find_last_node(t_list *stack)
{
	if (!stack)
		return NULL;
	while (stack->next)
		stack = stack->next;
	return (stack);
}
