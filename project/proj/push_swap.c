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

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		n_words;
	int		have_error;
	int		slt;
	int		tests;

	slt = 1;
	tests = 2;
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
			ft_printf("\nTHERE IS SOME ANOTHER ERROR MY FRIEND!!!\n");
		ft_printf("STACK CREATED:\n");
		print_stack(&a, &b, NULL, NULL);		
		ft_printf("___________________________________________\n");
		test_moves(&a, &b, tests, slt);	
		while (b)
			pa(&a, &b);
		ft_printf("\nfinal result:\n");
		print_stack(&a, &b, NULL, NULL);		
		free_stack(&a);
	}
	else if (have_error)
		free_stack(&a);

	if (ac == 2)
		free_mem(n_words, av);
	ft_printf("\n_________________________________________________________end\n");
	return (0);
}
