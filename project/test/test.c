/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:29:16 by isilva-t          #+#    #+#             */
/*   Updated: 2024/06/27 12:30:35 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void print_stack(t_list **a, t_list **b, t_list *cur_a, t_list *cur_b)
{
	auto int i = 0; 
	auto t_list	*cur_prev_a = NULL, *cur_prev_b = NULL;
	if (a)
	{
		if (*a)
		{
			cur_a = *a;
			cur_prev_a = *a;
			cur_prev_a = find_last_node(cur_prev_a);
			while (cur_prev_a->prev)
				cur_prev_a = cur_prev_a->prev;
		}
	}
	if (b)
	{
		if (*b)
		{
			cur_b = *b;
			cur_prev_b = *b;
			cur_prev_b = find_last_node(cur_prev_b);
			while (cur_prev_b->prev)
				cur_prev_b = cur_prev_b->prev;
		}
	}
	ft_printf("                only w/\"->next\"  |  \"->next->prev->next\"");
	while(cur_a || cur_b || cur_prev_a || cur_prev_b)
	{
		ft_printf("\nnode_%d->nbr", i); 
		if (cur_a)
		{
			ft_printf("     a_  %d", cur_a->nbr);
			cur_a = cur_a->next;
		}
		else
			ft_printf("          ");
		if (cur_b)
		{
			ft_printf("     b_  %d", cur_b->nbr);
			cur_b = cur_b->next;
		}
		else
			ft_printf("          ");
		if (cur_prev_a)
		{
			ft_printf("     a_  %d", cur_prev_a->nbr);
			cur_prev_a = cur_prev_a->next;
		}
		else
			ft_printf("          ");
		if (cur_prev_b)
		{
			ft_printf("     b_  %d", cur_prev_b->nbr);
			cur_prev_b = cur_prev_b->next;
		}
		i++;	
	}
	ft_printf("\n\n");
}

static void certify_moves(t_list **a, t_list **b)
{
	ft_printf("CERTIFY MOVES:\n");
	print_stack(a, b, NULL, NULL);
	ft_printf("____________________________________________________\n");
	pb(a, b);
	print_stack(a, b, NULL, NULL);
	ss(a, b);
	print_stack(a, b, NULL, NULL);
	sa(a);
	print_stack(a, b, NULL, NULL);
	sb(b);
	print_stack(a, b, NULL, NULL);
	rrr(a, b);
	print_stack(a, b, NULL, NULL);
	ra(a);
	print_stack(a, b, NULL, NULL);
	rb(b);
	print_stack(a, b, NULL, NULL);
	rr(a, b);
	print_stack(a, b, NULL, NULL);
	rra(a);
	print_stack(a, b, NULL, NULL);
	rrb(b);
	print_stack(a, b, NULL, NULL);
	pa(a, b);
	print_stack(a, b, NULL, NULL);
}

static int random_move(t_list **a, t_list **b, int nbr, int all)
{
	if (nbr > 5 || all == 1)
		pb(a, b);
	if (nbr == 2 || all == 1)
		ss(a, b);
	if (nbr == 3 || all == 1)
		sa(a);
	if (nbr == 4 || all == 1)
		sb(b);
	if (nbr == 5 || all == 1)
	{
		rrr(a, b);
		ra(a);
		rb(b);
	}
	if (nbr == 8 || all == 1)
	{
		rr(a, b);
		rra(a);
		rrb(b);
	}
	if (nbr < 6 || all == 1)
		pa(a, b);
	return (--nbr);
}

void test_moves(t_list **a, t_list **b, int n_tests, int slt)
{
	int test;
	int	all;

	all = 0;
	test = 12;
	ft_printf("\n________###############______TEST_MOVES_____###############_____%d\n", n_tests);
	while (test != 0)
	{
		ft_printf("random_moves\n");
		test = random_move(a, b, test, all++);
		if (all == 2)
			all = 0;
	}
	certify_moves(a, b);
	print_stack(a, b, NULL, NULL);
	sleep(slt);
	ft_printf("####################################################\n");
	while (--n_tests > 0)
		test_moves(a, b, -1, slt);
}
