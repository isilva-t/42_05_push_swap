/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:53:20 by isilva-t          #+#    #+#             */
/*   Updated: 2024/06/20 17:00:12 by isilva-t         ###   ########.fr       */
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

static void append_node(t_list **stack, int n)
{
	t_list	*node;
	t_list	*last_node;
	
	if (!stack)
		return ;
	node = malloc(sizeof(t_list) + 1);
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;

	if (!(*stack))
	{
		node->prev = NULL;
		*stack = node;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

static int	have_duplicated(t_list *stack, int n)
{
	while (stack)
	{
		if (stack->nbr == n)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	init_stack_a(t_list **a, char **array)
{
	int	i;
	long	n;

printf("___________________________________________ENTROU init_stack_a\n");
	
	i = 0;
	while(array[i])
	{
		if (have_syntax_error(array[i]))
		{
			write(1, "ErSYN\n", 6); // DELETE SYNTAX
			return ;
		}
		n = atol(array[i]);
		if (n > INT_MAX || n < INT_MIN)
		{	
			write(1, "ErINT\n", 6); //DELETE INT
			return ;
		}
		if (have_duplicated(*a, n))
		{
			write(1, "ErDUP\n", 6);
			return ;
		}
		append_node(a, (int)n);
		i++;
	}
}
