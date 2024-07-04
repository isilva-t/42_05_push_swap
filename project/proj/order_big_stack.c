/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_big_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:31:20 by isilva-t          #+#    #+#             */
/*   Updated: 2024/07/02 17:50:48 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	index_stack(t_list *stack)
{
	unsigned int	i;
	t_list	*lowest_node;
	
	i = 0;
	if (!stack && !stack->nbr_to_index)
		return ;
	lowest_node = find_lowest_node(stack);
	while (lowest_node->nbr_to_index != (long)2147483647 + 1)
	{
		lowest_node->index = i++;
		lowest_node->nbr_to_index = (long)2147483647 + 1;
		lowest_node = find_lowest_node(stack);
	}
}

static void    ft_utoabit_stack(t_list *stack)
{
	long	i;
	long	rest;
	long	nbr;

	if (!stack)
		return;
	while (stack)
	{
		nbr = stack->index;
		i = 0;  
    	while (i < 32)
			stack->arraybit[i++] = '0';
    	while (--i >= 0 && nbr != 0)
    	{
			rest = nbr;
			nbr = nbr / 2;
			stack->arraybit[i] = rest % 2 + '0';
		}
		stack->arraybit[32] = 0;
		stack = stack->next;
	}
}

static int	how_much_bit(t_list *stack, int position, char bit)
{
	int	n_bits;

	n_bits = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->arraybit[position] == bit)
			n_bits++;
		stack = stack->next;
	}
	return (n_bits);
}

static int bit_groups_ok(t_list *stack, int i, char stack_name)
{
	if (!stack)
		return (1);
	while (stack && stack->next)
	{
		if (stack_name == 'a')
		{
			if (stack->arraybit[i] == '1' &&
				stack->next->arraybit[i] == '0')
				return (0);
		}
		if (stack_name == 'b')
		{
			if (stack->arraybit[i] == '0' &&
			stack->next->arraybit[i] == '1')
				return (0);
		}
		stack = stack->next;
	}
	return (1);
}

static t_list	*find_last_wanted(t_list *stack, int i, int bit)
{
	t_list	*last_node;

	if (!stack)
		return (NULL);
	last_node = ft_lstlast(stack);
	while (last_node)
	{
		if (last_node->arraybit[i] == bit)
			return (last_node);
		last_node = last_node->prev;
	}
	return (last_node);
}

static void	make_index(t_list *stack)
{
	int	index;
	int	lstsize;

	index = 0;
	if (!stack)
		return ;
	lstsize = ft_lstsize(stack);
	while (stack)
	{
		stack->index = index++;
		if (stack->index < lstsize / 2)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
	}
}

static void	radix_b(t_list **a, t_list **b, int i)
{
	t_list	*last_wanted;
	
	if (!a || !b || !*b)
		return ;
	if (how_much_bit(*b, i, '0') == ft_lstsize(*b))
		return ;
	last_wanted = find_last_wanted(*b, i, '0');
	while (how_much_bit(*b, i, '1') > 0)
	{
		if (*b && (*b)->arraybit[i] == '1')
			pa(a, b);
		else
			rb(b);
	}
	if (i < 30 && ft_lstsize(*b) > 1)
	{
		while (ft_lstlast(*b) != last_wanted)
		{
			make_index(*b);
			if (last_wanted->above_median == 0)
				rrb(b);
			if (last_wanted->above_median == 1)
				rb(b);
		}
	}
	print_stack(a, b, NULL, NULL);
}

static void	order_radix(t_list **a, t_list **b)
{
	int	i;
	t_list	*last_wanted;

	if (!a || !b || !*a)
		return ;
	i = 32;
	while (--i >= 0)
	{
		if (how_much_bit(*a, i, '1') == ft_lstsize(*a) ||
			how_much_bit(*a, i, '0') == ft_lstsize(*a))
			continue ;
		last_wanted = find_last_wanted(*a, i, '1');
		while (how_much_bit(*a, i, '0') > 0)
		{
			if (bit_groups_ok(*a, i, 'a') && ft_lstlast(*a) == last_wanted)
				break ;
			if (*a && (*a)->arraybit[i] == '0' && how_much_bit(*a, i, '1') > 0)
				pb(a, b);
			else
				ra(a);
		}
		if (i < 31 && ft_lstsize(*a) > 1)
		{

			while (ft_lstlast(*a) != last_wanted)
			{
				make_index(*a);
				if (last_wanted->above_median == 0)
					rra(a);
				if (last_wanted->above_median == 1)
					ra(a);
			}
		}
		print_stack(a, b, NULL, NULL);
		radix_b(a, b, i - 1);
	}
	while (*b)
	{
		pa(a, b);
	}
	print_stack(a, b, NULL, NULL);
}

void	order_big_stack(t_list **a, t_list **b)
{
/*	int		stack_len;

	stack_len = ft_lstsize(*a);
	if (stack_len-- > 3)
		pb (a, b);
	if (stack_len-- > 3)
		pb (a, b);
	long	stack_len;
*/
	index_stack(*a);
	ft_utoabit_stack(*a);
print_stack(a, b, NULL, NULL);
		order_radix(a, b);
//	stack_len = ft_lstsize(*a);


//	if (stack_len-- > 3)
//		pb (a, b);
//	if (stack_len-- > 3)
//		pb (a, b);

//	while (stack_len-- != 3)
//	{
//	}
}
