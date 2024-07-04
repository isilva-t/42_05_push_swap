/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraybit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:14:22 by isilva-t          #+#    #+#             */
/*   Updated: 2024/07/03 10:38:43 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_utoabit(long nbr, long n)
{
	long	i;
	char array_bits[size];
	long rest;
	
	i = 0;
	while (i < size) //size 32 in this case
		array_bits[i++] = '0';
	while (--i >= 0 && nbr != 0)
	{
		rest = nbr;
		nbr = nbr / 2;
		array_bits[i] = rest % 2 + '0';
	}
	array_bits[size] = 0;
	return (array_bits);
}
