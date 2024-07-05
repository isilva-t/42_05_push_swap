/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:29:16 by isilva-t          #+#    #+#             */
/*   Updated: 2024/06/28 17:27:19 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	certify_moves(t_list **a, t_list **b)
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

static int	random_move(t_list **a, t_list **b, int nbr, int all)
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

void	test_moves(t_list **a, t_list **b, int n_tests, int slt)
{
	int	test;
	int	all;

	all = 0;
	test = 12;
	ft_printf("\n__######____TEST_MOVES____#######__%d\n", n_tests);
	while (test != 0)
	{
		ft_printf("random_moves\n");
		test = random_move(a, b, test, all++);
		if (all == 2)
			all = 0;
	}
	certify_moves(a, b);
	sleep(slt);
	ft_printf("####################################################\n");
	while (--n_tests > 0)
		test_moves(a, b, -1, slt);
}

void	print_err(char *str)
{
	ft_printf(str);
}
