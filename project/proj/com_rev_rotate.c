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

static int	rev_rotate(t_list **stack)
{
	t_list	*last_node;
	t_list	*second_last_node;
	t_list	*cur;

	if (!*stack)
		return(0);
	if (!(*stack)->next)
		return(0);
	cur = *stack;
	last_node = find_last_node(cur);
ft_printf("3\n");
	second_last_node = last_node->prev;
	ft_printf("second_last_node->nbr-> %d\n", last_node->prev->nbr);
	ft_printf("last_node->nbr-> %d\n", second_last_node->next->nbr);
ft_printf("X\n");
	second_last_node->next = NULL;
	//last_node->prev->next = NULL;
ft_printf("4\n");
	last_node->next = *stack;
	last_node->prev = NULL;
	*stack = last_node;
	return (1);
}

void	rra(t_list **a)
{
	ft_printf("testing rra\n");
	print_stack(a, NULL, NULL, NULL);
	if(rev_rotate(a))
		ft_printf("rra\n");
	else
		print_err("______NO REV_rotate___a\n");
}

void	rrb(t_list **b)
{	
	ft_printf("testing rrb\n");
	print_stack(NULL, b, NULL, NULL);
	if(rev_rotate(b))
		ft_printf("rrb\n");
	else
		print_err("______NO REV_rotate___b\n");
}

void	rrr(t_list **a, t_list **b)
{
	print_stack(a, b, NULL, NULL);
	if (!*a || !*b)
		return (print_err("______NO REV_rotate_both\n"));
	if (!(*a)->next || !(*b)->next)
		return (print_err("______NO REV_rotate_both\n"));
	if (rev_rotate(a) && rev_rotate(b))
		ft_printf("rrr\n");
	else
		return (print_err("______NO REV_rotate_both____WTF?!?!?!\n"));
}
