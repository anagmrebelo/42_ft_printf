/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_x.c	                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:15:29 by arebelo           #+#    #+#             */
/*   Updated: 2022/01/31 13:50:55 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	aux_one(t_print	*specs, int fd, unsigned int temp);

void	ft_putnbr_x(int n, int fd, t_print *specs, unsigned int temp)
{
	if (n == -2147483648)
	{
		aux_one(specs, fd, temp);
		return ;
	}
	if (n < 0)
	{
		n *= (-1);
		specs->len += write(fd, "-", 1);
	}
	if (n >= 10)
	{
		ft_putnbr_x(n / 10, fd, specs, temp);
		n = n % 10;
	}	
	if (n < 10)
	{
		if (specs->r_ident == 0 && specs->filler == '0')
			print_mfw(specs, temp);
		precision_putnbr(specs);
		n += 48;
		specs->len += write (fd, &n, 1);
	}
}

void	precision_putnbr(t_print *specs)
{
	while (specs->str > specs->size)
	{
		specs->len += write(1, "0", 1);
		specs->str--;
	}
}

static void	aux_one(t_print	*specs, int fd, unsigned int temp)
{
	specs->len += write(fd, "-", 1);
	if (specs->r_ident == 0 && specs->filler == '0')
		print_mfw(specs, temp);
	precision_putnbr(specs);
	specs->len += write (fd, "2147483648", 10);
}
