/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:52:27 by isilva-t          #+#    #+#             */
/*   Updated: 2024/06/25 12:48:36 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void print_stack(t_list **a, t_list **b, t_list *cur_a, t_list *cur_b)
{
	int	i;

	i = 0;
	if (*a)
		cur_a = *a;
	if (*b)
		cur_b = *b;
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
		sleep(0);
		i++;	
	}
	ft_printf("\n\n");
}

static void test_moves(t_list *a, t_list *b, int n_tests, int slt)
{
	ft_printf("\n______________TEST_MOVES______________%d\n", n_tests);
	pb(&a, &b);
	pb(&a, &b);
	pb(&a, &b);
				rb(&b);
	pb(&a, &b);
	print_stack(&a, &b, NULL, NULL);
sleep(slt);
	pa(&a, &b);
	pa(&a, &b);
	pa(&a, &b);
	pa(&a, &b);
				ra(&a);
	pa(&a, &b);
	print_stack(&a, &b, NULL, NULL);
sleep(slt);
	pb(&a, &b);
	pb(&a, &b);
	print_stack(&a, &b, NULL, NULL);
sleep(slt);
	pa(&a, &b);
	pa(&a, &b);
							sa(&a);
							sa(&a);
											rrr(&a, &b);
	pa(&a, &b);
	
							sa(&a);
	pa(&a, &b);

	print_stack(&a, &b, NULL, NULL);
sleep(slt);
	pb(&a, &b);
	
											rra(&a);
							sa(&a);
							sa(&a);
				ra(&a);
				rb(&b);
				rr(&a, &b);

	pb(&a, &b);
	pb(&a, &b);
											rrb(&b);
	pb(&a, &b);
	print_stack(&a, &b, NULL, NULL);
sleep(slt);
	pa(&a, &b);
	pa(&a, &b);
	print_stack(&a, &b, NULL, NULL);

	free_stack(a);
	free_stack(b);

}


int	main(int ac, char **av)
{
	int		n_words;
	t_list	*a;
	t_list	*b;
	int		have_error;
	int		slt;

	slt = 0;
	have_error = 0;
	a = NULL;
	b = NULL;
	if (ac < 2 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
	{	
		n_words = count_words(av[1], ' ');
		av = ft_split(av[1], ' ', n_words);
		have_error = init_stack_a(&a, av);
	}
	else if (ac > 2)
		have_error = init_stack_a(&a, av + 1);

//////////////////////////////////// VISUALISE SECTION
	if (have_error == 0)
	{
		if(is_not_sorted(a) && a)
			ft_printf("\nNOT sorted....\n");
		else if (is_not_sorted(a) == 0 && a)
			ft_printf("\nSORTED!!!\n");
		else if (is_not_sorted(a) == -1 && a)
			ft_printf("\nTHERE IS A ERROR MY FRIEND!!!\n");

		print_stack(&a, &b, NULL, NULL);
		test_moves(a, b, 3, slt);
}

	if (have_error)
		free_stack(a);

	if (ac == 2)
		free_mem(n_words, av);
	ft_printf("\n_________________________________________________________end\n");
	return (0);
}
