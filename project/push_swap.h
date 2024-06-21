/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:54:49 by isilva-t          #+#    #+#             */
/*   Updated: 2024/06/21 11:35:45 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# include <stdio.h> //DELETE THIS BEFORE SUBMIT!!!!!!

typedef struct s_list
{
	int	nbr;
	int	index;
	int	push_cost;
	int	above_median;
	int	cheapest;
	struct s_list *target_node;
	struct s_list *next;
	struct s_list *prev;
}	t_list;

// stack init
void	init_stack_a(t_list **a, char	**array);

// stack utils
t_list	*find_last_node(t_list *stack);
int		is_not_sorted(t_list *stack);

// free error
void	free_stack(t_list *stack);
void	free_mem(int in_word, char **array);

//utils libft
int	ft_atoi(const char *nptr);
//split
char	**ft_split(char const *s, char c, int n_words);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
int	count_words(const char *s, char c);
void	free_mem(int in_word, char **array);


#endif
