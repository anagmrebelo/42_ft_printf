/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_xu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:15:29 by arebelo           #+#    #+#             */
/*   Updated: 2023/02/21 19:19:13 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_xu(unsigned int n, int fd, t_print *specs, unsigned int temp)
{
	if (n >= 10)
	{
		ft_putnbr_xu(n / 10, fd, specs, temp);
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
