/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:52:27 by isilva-t          #+#    #+#             */
/*   Updated: 2024/06/24 17:05:38 by isilva-t         ###   ########.fr       */
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
		i++;	
	}
	ft_printf("\n\n\n");
}

int	main(int ac, char **av)
{
	int		n_words;
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac < 2 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
	{	
		n_words = count_words(av[1], ' ');
		av = ft_split(av[1], ' ', n_words);
		init_stack_a(&a, av);
	}
	else if (ac > 2)
		init_stack_a(&a, av + 1);

// VISUALISE SECTION
	if (a)
	{
		if(is_not_sorted(a) && a)
		{
			ft_printf("\nNOT sorted....\n");
		}
		else if (is_not_sorted(a) == 0 && a)
			ft_printf("\nSORTED!!!\n");
		else if (is_not_sorted(a) == -1 && a)
			ft_printf("\nTHERE IS A ERROR MY FRIEND!!!\n");

		print_stack(&a, &b, NULL, NULL);

		pb(&a, &b);
		pb(&a, &b);
		pb(&a, &b);
		pb(&a, &b);

		print_stack(&a, &b, NULL, NULL);

		sa(&a);
		print_stack(&a, &b, NULL, NULL);

		pa(&a, &b);
		print_stack(&a, &b, NULL, NULL);

		sa(&a);
		sb(&b);
		print_stack(&a, &b, NULL, NULL);

		ss(&a, &b);
		print_stack(&a, &b, NULL, NULL);

		ra(&a);
		print_stack(&a, &b, NULL, NULL);
		rb(&b);
		print_stack(&a, &b, NULL, NULL);
		rr(&a, &b);
		print_stack(&a, &b, NULL, NULL);




	}

/////////////////////////
// free section	
	if (ac == 2)
		free_mem(n_words, av);
	free_stack(a);
	free_stack(b);

//	free_stack(b);
////////////////////////
	

	ft_printf("\n_________________________________________________________end\n");
	return (0);
}
