/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:47:54 by arebelo           #+#    #+#             */
/*   Updated: 2023/02/21 19:19:13 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	counter_int(int n, t_print *specs)
{
	if (n == -2147483648)
	{
		specs->size = 11;
		return ;
	}
	if (n < 0)
	{
		n *= (-1);
		specs->size++;
	}
	if (n >= 10)
	{
		counter_int(n / 10, specs);
		n = n % 10;
	}	
	if (n < 10)
	{
		n += 48;
		specs->size++;
	}
}

void	counter_ul_base(unsigned long nbr, char *base, t_print *specs)
{
	unsigned long	i;

	i = ft_strlen(base);
	if (nbr >= i)
	{
		counter_ul_base(nbr / i, base, specs);
		nbr = nbr % i;
	}	
	if (nbr < i)
	{
		specs->size++;
	}
}
