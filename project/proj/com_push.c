/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:05:14 by isilva-t          #+#    #+#             */
/*   Updated: 2024/06/24 11:07:51 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_list **src, t_list **dst)
{
	t_list	*node_to_push;

	if (!(*src))
		return ;
	node_to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_push->prev = NULL;
	if (!*dst)
	{
		*dst = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *dst;
		node_to_push->next->prev = node_to_push;
		*dst = node_to_push;
	}
}

void	pb(t_list **a, t_list **b)
{
	push(a, b);
	ft_printf("pb\n");
}

void	pa(t_list **a, t_list **b)
{
	push(b, a);
	ft_printf("pa\n");
}
