/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:54:49 by isilva-t          #+#    #+#             */
/*   Updated: 2024/07/02 17:29:40 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "./utils/ft_printf/ft_printf.h"

#include <stdio.h> //REMOVE THIS

typedef struct s_list
{
	int				nbr;
	long			nbr_to_index;
	char			arraybit[33];
	int				moves;
	int				index;
	int				last_wanted;
	int				push_cost;
	int				above_median;
	int				cheapest;
	int				target_nbr;
	struct s_list	*target_node;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

// stack init
int		init_stack_a(t_list **a, char	**array, int i);

// stack utils
t_list	*ft_lstlast(t_list *lst);
int		is_not_sorted(t_list *stack);
int		ft_lstsize(t_list *lst);
t_list	*find_biggest_node(t_list *stack);
t_list	*find_lowest_node(t_list *stack);

// order stack
void	order_three(t_list **stack);
void	order_big_stack(t_list **a, t_list **b);

//commands
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	sa(t_list **stack);
void	sb(t_list **stack);
void	ss(t_list **a, t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

// error tools
void	free_stack(t_list **stack);
void	free_mem(int in_word, char **array);
void	print_err(char *str);

//tests
void	print_stack(t_list **a, t_list **b, t_list *cur_a, t_list *cur_b);
void	test_moves(t_list **a, t_list **b, int n_tests, int slt);
void	view_tests(t_list **a, t_list **b, char c);

//utils
int		ft_atoi(const char *nptr);
char	**ft_split(char const *s, char c, int n_words);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
int		count_words(const char *s, char c);
int		ft_isdigit(int c);
t_list	*ft_lstlast(t_list *lst);

#endif
