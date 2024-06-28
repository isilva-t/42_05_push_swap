/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:52:27 by isilva-t          #+#    #+#             */
/*   Updated: 2024/06/28 17:33:40 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	else if (ac == 2)
	{
		n_words = count_words(av[1], ' ');
		av = ft_split(av[1], ' ', n_words);
		have_error = init_stack_a(&a, av, 0);
	}
	else if (ac > 2)
		have_error = init_stack_a(&a, av + 1, 0);
//////////////////////////////////// VISUALISE SECTION
	if (have_error == 0)
		view_tests(&a, &b);
	else if (have_error)
		free_stack(&a);
	if (ac == 2)
		free_mem(n_words, av);
	return (0);
}
