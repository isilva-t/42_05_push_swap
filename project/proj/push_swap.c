/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:52:27 by isilva-t          #+#    #+#             */
/*   Updated: 2024/06/21 11:36:03 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char **av)
{
	int		n_words;
	t_list	*a;
	t_list	*b;
	
	t_list	*current; //FOR TESTING
	int		i;	//for testing
	
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
printf("\nNOT sorted....");
	}
	else if (is_not_sorted(a) == 0 && a)
printf("\nSORTED!!!");
	else if (is_not_sorted(a) == -1 && a)
printf("\nTHERE IS A ERROR MY FRIEND!!!");

		current = a;
		i = 0;
		while(current)
		{		
			printf("\nnode_%d->nbr  %d", i, current->nbr);
			current = current->next;
			i++;
		}
	}
/////////////////////////
// free section	
	if (ac == 2)
		free_mem(n_words, av);
	free_stack(a);
////////////////////////
	

	printf("\n_________________________________________________________end\n");
	return (0);
}
