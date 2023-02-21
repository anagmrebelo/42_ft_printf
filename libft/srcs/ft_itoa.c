/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:54:16 by arebelo           #+#    #+#             */
/*   Updated: 2023/02/21 17:25:45 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		aux_len(int n);
static void				aux_fill(char *ptr, int n);
static int				aux_module(int n);

char	*ft_itoa(int n)
{
	char	*ptr;

	ptr = (char *)ft_calloc((aux_len(n) + 1), 1);
	if (!ptr)
		return (0);
	aux_fill(ptr, n);
	return (ptr);
}

static unsigned int	aux_len(int n)
{
	unsigned int	counter;

	counter = 1;
	if (n < 0)
		counter++;
	while (n / 10 != 0)
	{
		counter++;
		n /= 10;
	}
	return (counter);
}

static void	aux_fill(char *ptr, int n)
{
	int	counter;
	int	len;
	int	sign;

	sign = 0;
	len = aux_len(n);
	counter = aux_len(n);
	if (n < 0)
	{
		ptr[0] = '-';
		sign = 1;
	}
	if (aux_module(n % 10) == 0 && counter == 1)
		ptr[counter - 1] = 48;
	while (counter > (0 + sign))
	{
		ptr[counter - 1] = aux_module(n % 10) + 48;
		counter--;
		n /= 10;
	}
	ptr[len] = '\0';
}

static	int	aux_module(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}
