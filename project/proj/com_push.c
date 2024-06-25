/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:05:14 by isilva-t          #+#    #+#             */
/*   Updated: 2024/06/25 12:53:40 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	push(t_list **src, t_list **dst)
{
	t_list	*node_to_push;

	if (!(*src))
		return (0);
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
	return (1);
}

void	pb(t_list **a, t_list **b)
{
	if(push(a, b))
		ft_printf("pb\n");
}

void	pa(t_list **a, t_list **b)
{
	if(push(b, a))
		ft_printf("pa\n");
}
