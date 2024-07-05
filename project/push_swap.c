/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:52:27 by isilva-t          #+#    #+#             */
/*   Updated: 2024/07/01 16:12:09 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_nbr(t_list *a, int to_find)
{
	int	i;

	i = -1;
	if (!a)
		return (i);
	while (a)
	{
		i++;
		if (a->index_a == to_find)
			return (i);
		a = a->next;
	}
	return (i);
}

static void	order_three(t_list **stack, char do_index)
{
	t_list	*biggest_node;
	
	if (!stack || !*stack)
		return ;
	if (ft_lstsize(*stack) != 3)
		return ;
	if (do_index == 'y')
		index_stack(*stack);
	biggest_node = find_biggest_node(*stack);
	if (biggest_node->index_a == (*stack)->index_a)
		ra(stack);
	if (biggest_node->index_a == (*stack)->next->index_a)
		rra(stack);
	if ((*stack)->index_a > (*stack)->next->index_a)
		sa(stack);
}

static void	order_four_or_five(t_list **a, t_list **b)
{
	if (!a || !*a)
		return ;
	index_stack(*a);
	make_index_again(*a);
	while (ft_lstsize(*b) < 2)
	{
		if ((*a)->index_a == 0 || (*a)->index_a == 1)
			pb(a, b);
		else if ((*a)->next->index_a == 0 || (*a)->next->index_a == 1)
			sa(a);
		else if (find_nbr(*a, 0) >= ft_lstsize(*a) - 1 
			|| find_nbr(*a, 1) >= ft_lstsize(*a) - 1)
			rra(a);	
		else
			ra(a);
	}
	if ((*b)->index_a == 0)
		sb(b);
	if (ft_lstsize(*a) == 3)
		order_three(a, 'n');
	else if (ft_lstsize(*a) == 2)
		if ((*a)->index_a > (*a)->next->index_a)
			sa(a);
	pa(a, b);
	pa(a, b);
}

static	void	order_stack(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) == 2)
		sa(a);
	else if (ft_lstsize(*a) == 3)
		order_three(a, 'y');
	else if (ft_lstsize(*a) == 4 || ft_lstsize(*a) == 5)
		order_four_or_five(a, b);
	else
		order_radix(a, b, NULL, 32);
	free_stack(a);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		n_words;
	int		have_error;

	a = NULL;
	b = NULL;
	have_error = 0;
	if (ac < 2 || (ac == 2 && !av[1][0]))
		return (1);
	if (ac == 2)
	{
		n_words = count_words(av[1], ' ');
		av = ft_split(av[1], ' ', n_words);
		have_error = init_stack_a(&a, av, 0, 0);
		free_mem(n_words, av);
	}
	else if (ac > 2)
		have_error = init_stack_a(&a, av + 1, 0, 0);
	if (have_error == 0 && is_not_sorted(a))
		order_stack(&a, &b);
	else
		free_stack(&a);
	return (0);
}
