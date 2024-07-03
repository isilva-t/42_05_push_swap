/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_section.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:01:26 by isilva-t          #+#    #+#             */
/*   Updated: 2024/07/02 13:13:08 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	t_list	*print_line(t_list *node, char s)
{
	printf("  %s %c  %d", node->arraybit, s, node->index);
	printf("   __%d      ", node->nbr);

//	node->index,
//	node->push_cost,
//	node->above_median,
//	node->cheapest,
//	node->target_nbr);
	node = node->next;
	return (node);
}

static	void	print_nodes(t_list *cur_a, t_list *cur_b,
						t_list *cur_prev_a, t_list *cur_prev_b)
{
	auto int i = 0, print_rev = 0;
//	ft_printf("                only w/\"->next\"  |  \"->next->prev->next\"");
	while (cur_a || cur_b)
	{
		printf("\nnd%d", i);
		if (cur_a)
			cur_a = print_line(cur_a, 'a');
		else
			printf("                                                    ");
		if (cur_b)
			cur_b = print_line(cur_b, 'b');
		else
			printf("                   ");
		if (cur_prev_a && print_rev)
			cur_prev_a = print_line(cur_prev_a, 'a');
		else if (print_rev)
			printf("                   ");
		if (cur_prev_b && print_rev)
			cur_prev_b = print_line(cur_prev_b, 'b');
		i++;
	}
	printf("\n\n");
}

void	print_stack(t_list **a, t_list **b, t_list *cur_a, t_list *cur_b)
{
	auto t_list * cur_prev_a = NULL, *cur_prev_b = NULL;
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
		print_stack(a, b, NULL, NULL);
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
		print_stack(a, b, NULL, NULL);
		free_stack(a);
		ft_printf("________________________________________________\n");
	}
}
