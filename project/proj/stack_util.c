/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:53:20 by isilva-t          #+#    #+#             */
/*   Updated: 2024/06/20 15:09:45 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	have_syntax_error(char	*str)
{
	if (!str)
		return (1);
	if (!(*str == '-' || *str == '+' || ft_isdigit(*str)))
		return (1);
	if ((*str == '+' || *str == '-') && !(ft_isdigit(*(str + 1))))
		return (1);
	str++;
	while (*str)
	{
		if (!(ft_isdigit(*str)))
			return (1);
		str++;
	}
	return (0);
}

void	init_stack_a(t_stack_node **a, char	**array)
{
	int	i;
	long	n;

printf("entrou\n");
	a = NULL; //FOR TESTING
	i = 0;
	while(array[i])
	{
		if (have_syntax_error(array[i]))
			write(1, "Error\n", 6);
		n = atol(array[i]);
		i++;
	}
}
