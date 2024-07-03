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
/*
static void	current_index(t_list **stack)
{
	int	above_median;
	int	stack_index;
	t_list	*cur;

	stack_index = 0;
	if (!stack || !*stack)
		return ;
	cur = *stack;
	above_median = ft_lstsize(cur) / 2;
	while (cur)
	{
		cur->index = stack_index++;
		cur->cheapest = 0;
		if (cur->index < above_median)
			cur->above_median = 1;
		else
			cur->above_median = 0;
		cur = cur->next;
	}
}

static void set_target_a(t_list **a, t_list **b, t_list *cur_b, t_list *target_node)
{
	long	best_choice_nbr;
	t_list	*cur_a;

	if (!*a || !*b)
		return ;
	cur_a = *a;
	while (cur_a)
	{
		best_choice_nbr = LONG_MIN;
		cur_b = *b;
		while (cur_b)
		{
			if (cur_b->nbr > best_choice_nbr)
			{
				best_choice_nbr = cur_b->nbr;
				target_node = cur_b;
			}
			cur_b = cur_b->next;
		}
		if (best_choice_nbr != LONG_MIN)
		{
			cur_a->target_node = target_node;
			cur_a->target_nbr = cur_a->target_node->nbr;
		}
		else
		{
			cur_a->target_node = find_biggest_node(*b);
			cur_a->target_nbr = cur_a->target_node->nbr;
		}
		cur_a = cur_a->next;
	}
}

static void	cost_analysis(t_list **a, t_list**b)
{
	int		len_a;
	int		len_b;
	t_list	*cur_a;

	cur_a = NULL;
	len_a = ft_lstsize(*a);
	len_b = ft_lstsize(*b);
	if (*a)
		cur_a = *a;
	while (cur_a)
	{
		cur_a->push_cost = cur_a->index;
		if (cur_a->above_median ==0)
			cur_a->push_cost = len_a - cur_a->index;
		if (cur_a->target_node->above_median ==1)
			cur_a->push_cost += cur_a->target_node->index;
		else
			cur_a->push_cost += len_b - cur_a->target_node->index;
		cur_a = cur_a->next;
	}
}

static void	set_cheapest(t_list **stack)
{
	t_list	*current;
	t_list	*cheapest_node;
	long	temp_value;

	cheapest_node = NULL;
	current = *stack;
	temp_value = LONG_MAX;
	while (current)
	{
		if (current->push_cost < temp_value)
		{
			temp_value = current->push_cost;
			cheapest_node = current;
		}
		current = current->next;
	}
	cheapest_node->cheapest = 1;
}

static void	init_a_nodes(t_list **a, t_list **b)
{
ft_printf("init_a_nodes\n");
	current_index(a);
	current_index(b);
	set_target_a(a, b, NULL, NULL);
	cost_analysis(a, b);
	set_cheapest(a);
print_stack(a, b, NULL, NULL);
ft_printf("init_a_nodes DONE\n");
}

static t_list	*get_cheapest(t_list **stack)
{
	while (*stack)
	{
		if ((*stack)->cheapest == 1)
			return *stack;
		*stack = (*stack)->next;
	}
	return NULL;
}

static void	rotate_both(t_list	**a, t_list **b, t_list *cheapest_node)
{
ft_printf("PRE rev_rotate_both\n");
print_stack(a, b, NULL, NULL);
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b);
	current_index(a);
	current_index(b);
ft_printf("rotate_both DONE\n");
print_stack(a, b, NULL, NULL);
}

static void rev_rotate_both(t_list **a, t_list**b, t_list *cheapest_node)
{
ft_printf("PRE rev_rotate_both\n");
print_stack(a, b, NULL, NULL);
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b);
	current_index(a);
	current_index(b);
ft_printf("REV_rotate_both DONE\n");
print_stack(a, b, NULL, NULL);
}

static void	get_ready_to_push(t_list **stack, t_list *wanted_node, char st_name)
{
	if (st_name == 'a')
	{
		if (wanted_node->above_median)
			ra(stack);
		else
			rra(stack);
	}
	if (st_name == 'b')
	{
		if (wanted_node->above_median)
			rb(stack);
		else
			rrb(stack);
	}
}

static void	move_a_to_b(t_list **a, t_list **b, t_list *cheapest_node)
{
ft_printf("move_a_to_b\n");
print_stack(a, b, NULL, NULL);
	cheapest_node = get_cheapest(a);
print_stack(a, b, NULL, NULL);
	if (cheapest_node->above_median == 1 && cheapest_node->target_node->above_median == 1)
		rotate_both(a, b, cheapest_node);
	else if (cheapest_node->above_median == 0 && cheapest_node->target_node->above_median == 0)
		rev_rotate_both(a, b, cheapest_node);
print_stack(a, b, NULL, NULL);
	get_ready_to_push(a, cheapest_node, 'a');
	get_ready_to_push(b, cheapest_node, 'b');
	pb(a, b);
ft_printf("move_a_to_b DONE______________________________\n\n\n\n");
print_stack(a, b, NULL, NULL);
}
////////////////////////////////////////////////////////////////////////////////
void	order_big_stack(t_list **a, t_list **b)
{
	int		stack_len;

	stack_len = ft_lstsize(*a);
	if (stack_len-- > 3)
		pb (a, b);
	if (stack_len-- > 3)
		pb (a, b);
	while (stack_len-- != 3)
	{
		init_a_nodes(a, b);
		move_a_to_b(a, b, NULL);
	}
}*/

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

static void	radix_b(t_list **a, t_list **b, int i)
{
	int	j;
	int	bit;
	
	bit = '1';
	j = 1;
	if (!a || !b || !*b)
		return ;
	while (j > 0)
	{
	if (how_much_bit(*b, i - j, '1') == ft_lstsize(*b) ||
		how_much_bit(*b, i - j, '0') == ft_lstsize(*b))
		return ;
	while (bit == '1')
	{
		if (*b && (*b)->arraybit[i - j] == '1')
			pa(a, b);
		else if (how_much_bit(*b, i - j, '0') < ft_lstsize(*b))
			rb(b);
		else
			bit = '0';
	}
print_stack(a, b, NULL, NULL);
	if (how_much_bit(*b, i - j, '1') == ft_lstsize(*b) ||
		how_much_bit(*b, i - j, '0') == ft_lstsize(*b))
		return ;
	j--;
	}
}

static void	order_radix(t_list **a, t_list **b)
{
	int	i;
	int	bit;

	if (!a || !b || !*a)
		return ;
	i = 32;
	while (--i >= 0)
	{
		bit = '0';
		if (how_much_bit(*a, i, '1') == ft_lstsize(*a) ||
			how_much_bit(*a, i, '0') == ft_lstsize(*a))
			continue ;
		while (bit == '0')
		{
			if (*a && (*a)->arraybit[i] == '0')
				pb(a, b);
			else if (how_much_bit(*a, i, '1') < ft_lstsize(*a))
				ra(a);
			else
				bit = '1';
		}
		print_stack(a, b, NULL, NULL);
		//while (*b)
		//	pa(a, b);
		if (i - 1 >= 0)
			radix_b(a, b, i);
	}
	while (*b)
		pa(a, b);
	print_stack(a, b, NULL, NULL);

}

void	order_big_stack(t_list **a, t_list **b)
{
//	long	stack_len;

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
