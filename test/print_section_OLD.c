/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_section.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:01:26 by isilva-t          #+#    #+#             */
/*   Updated: 2024/07/06 11:00:00 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// used before in print_line
//printf("   %c  %d", node->arraybit, s, node->index);
//printf("   __%d      ", node->nbr);
static	t_list	*print_line(t_list *node, char s)
{
	ft_printf("   %s ", node->arraybit);
	s = s + 1 - 1;
	node = node->next;
	return (node);
}

// used befor in print_nodes
//	ft_printf("                only w/\"->next\"  |  \"->next->prev->next\"");
static	void	print_nodes(t_list *cur_a, t_list *cur_b,
						t_list *cur_prev_a, t_list *cur_prev_b)
{
	auto int i = 0, print_rev = 0, print = 0;
	if (print == 1)
		return ;
	while (cur_a || cur_b)
	{
		ft_printf("\n");
		if (cur_a)
			cur_a = print_line(cur_a, 'a');
		else
			ft_printf("                                   ");
		if (cur_b)
			cur_b = print_line(cur_b, 'b');
		else
			ft_printf("                   ");
		if (cur_prev_a && print_rev)
			cur_prev_a = print_line(cur_prev_a, 'a');
		else if (print_rev)
			ft_printf("                   ");
		if (cur_prev_b && print_rev)
			cur_prev_b = print_line(cur_prev_b, 'b');
		i++;
	}
	ft_printf("\n\n");
}

void	print_stack(t_list **a, t_list **b)
{
	auto t_list * cur_prev_a = NULL, *cur_prev_b = NULL;
	auto t_list * cur_a = NULL, *cur_b = NULL;
	if (a && *a)
	{
		cur_a = *a;
		cur_prev_a = *a;
		cur_prev_a = ft_lstlast(cur_prev_a);
		while (cur_prev_a->prev)
			cur_prev_a = cur_prev_a->prev;
	}
	if (b && *b)
	{
		cur_b = *b;
		cur_prev_b = *b;
		cur_prev_b = ft_lstlast(cur_prev_b);
		while (cur_prev_b->prev)
			cur_prev_b = cur_prev_b->prev;
	}
	print_nodes(cur_a, cur_b, cur_prev_a, cur_prev_b);
}

// in function "view_tests"
// last two vars in "test_moves" are: 
// - number of test_moves to run (recursively). 0 or 1, runs once
// sleep time between function run (at end of function
void	view_tests(t_list **a, t_list **b, char c)
{
	if (c == 'i')
	{
		print_stack(a, b);
		if (is_not_sorted(*a) && *a)
			ft_printf("\nNOT sorted....\n");
		else if (is_not_sorted(*a) == 0 && *a)
			ft_printf("\nSORTED!!!\n");
		else if (is_not_sorted(*a) == -1 && *a)
			ft_printf("\nTHERE IS SOME ANOTHER ERROR MY FRIEND!!!\n");
	}
	else if (c == 't')
	{
		test_moves(a, b, 0, 0);
		ft_printf("\nMOVE ALL TO \"a\":\n");
		while (*b)
			pa(a, b);
	}
	else
	{
		ft_printf("\nfinal result:\n");
		print_stack(a, b);
		ft_printf("________________________________________________\n");
	}
}
