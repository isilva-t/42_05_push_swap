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
	int	i;

	i = 0;
	if (a)
	{
		if (*a)
			cur_a = *a;
	}
	if (b)
	{
		if (*b)
			cur_b = *b;
	}
	while(cur_a || cur_b)
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
		i++;	
	}
	ft_printf("\n\n");
}

void print_rev_stack(t_list **a, t_list **b, t_list *cur_a, t_list *cur_b)
{
	int	i;

	i = 0;
	if (a)
	{
		if (*a)
		{
			cur_a = find_last_node(*a);
			while (cur_a->prev)
				cur_a = cur_a->prev;
		}
	}
	if (b)
	{
		if (*b)
		{
			cur_b = find_last_node(*b);
			while (cur_b->prev)
				cur_b = cur_b->prev;
		}
	}
	ft_printf("PRINT_REV___________________\n");
	while(cur_a || cur_b)
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
		i++;	
	}
	ft_printf("\n\n");
}

static int random_move(t_list **a, t_list **b, int nbr)
{
	if (nbr > 5)
		pb(a, b);
	if (nbr == 2)
		ss(a, b);
	if (nbr == 3)
		sa(a);
	if (nbr == 4)
		sb(b);
	if (nbr == 5)
	{
		rrr(a, b);
		ra(a);
		rb(b);
	}
	if (nbr == 8)
	{
		rr(a, b);
		rra(a);
		rrb(b);
	}
	if (nbr < 6)
		pa(a, b);
	return (--nbr);
}

void test_moves(t_list **a, t_list **b, int n_tests, int slt)
{
	int	test;

	test = 12;
	print_stack(a, b, NULL, NULL);
	ft_printf("\n______________TEST_MOVES______________%d\n", n_tests);
	while (test != 0)
	{
	test = random_move(a, b, test);
	}
	print_stack(a, b, NULL, NULL);
	ft_printf("test before repeat \n");
	pb(a, b);
	pa(a, b);
	ss(a, b);
	sa(a);
	sb(b);
	rrr(a, b);
	ra(a);
	rb(b);
	rr(a, b);
	rra(a);
	rrb(b);
	sleep(slt);
	ft_printf("___________________________\n");
}
