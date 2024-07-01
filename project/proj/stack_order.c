/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:53:41 by isilva-t          #+#    #+#             */
/*   Updated: 2024/07/01 17:19:06 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	three_order(t_list **stack)
{
	t_list	*biggest_node;
	
	if (!stack || !*stack)
		return ;
	if (ft_lstsize(*stack) != 3)
		return ;
	biggest_node = find_biggest_node(*stack);
	if (biggest_node->nbr == (*stack)->nbr)
		ra(stack);
	if (biggest_node->nbr == (*stack)->next->nbr)
		rra(stack);
	if ((*stack)->nbr > (*stack)->next->nbr)
		sa(stack);
}

static void	current_index(t_list **stack)
{
	int	above_median;
	int	stack_index;
	t_list	*cur;

ft_printf("current_index\n");
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
		}
		else
		{
			cur_a->target_node = find_biggest_node(*b);
		}
		cur_a = cur_a->next;
	}
}

static void	cost_analysis(t_list **a, t_list**b)
{
	int	len_a;
	int	len_b;
	t_list	*cur_a;

	cur_a = NULL;
ft_printf("cost_analysis\n");
	len_a = ft_lstsize(*a);
	len_b = ft_lstsize(*b);
	ft_printf("len_a == %d, len_b == %d\n", len_a, len_b);
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

ft_printf("set_cheapest\n");
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
ft_printf("init_a_node0\n");

print_stack(a, b, NULL, NULL);
	current_index(a);
print_stack(a, b, NULL, NULL);
ft_printf("init_a_node1\n");
	current_index(b);
print_stack(a, b, NULL, NULL);
ft_printf("init_a_node2\n");
	set_target_a(a, b, NULL, NULL);
print_stack(a, b, NULL, NULL);
ft_printf("init_a_node3\n");
print_stack(a, b, NULL, NULL);
	cost_analysis(a, b);
print_stack(a, b, NULL, NULL);
ft_printf("init_a_node4\n");
	set_cheapest(a);
print_stack(a, b, NULL, NULL);
}

static t_list	*get_cheapest(t_list **stack)
{
ft_printf("get_cheapest\n");
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
ft_printf("rotate_both\n");
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b);
	current_index(a);
	current_index(b);
}

static void rev_rotate_both(t_list **a, t_list**b, t_list *cheapest_node)
{
ft_printf("rev_rotate_both\n");
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b);
	current_index(a);
	current_index(b);
}

static void	get_ready_to_push(t_list **stack, t_list *top_node, char st_name)
{
ft_printf("get_ready_to_push\n");	
	if (st_name == 'a')
	{
		if (top_node->above_median)
			ra(stack);
		else
			rra(stack);
	}
	if (st_name == 'b')
	{
		if (top_node->above_median)
			rb(stack);
		else
			rrb(stack);
	}
}

static void	move_a_to_b(t_list **a, t_list **b, t_list *cheapest_node)
{
ft_printf("move_a_to_b\n");
	cheapest_node = get_cheapest(a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!cheapest_node->above_median && !cheapest_node->target_node->above_median)
		rev_rotate_both(a, b, cheapest_node);
	get_ready_to_push(a, cheapest_node, 'a');
	get_ready_to_push(b, cheapest_node, 'b');
	pb(a, b);

}

void	order_big_stack(t_list **a, t_list **b)
{
	int		stack_len;

	stack_len = ft_lstsize(*a);
	ft_printf("order_big_stack\n");
	if (stack_len-- > 3)
		pb (a, b);
	if (stack_len-- > 3)
		pb (a, b);
	while (stack_len-- != 2)
	{
		init_a_nodes(a, b);
		move_a_to_b(a, b, NULL);
	}
}
