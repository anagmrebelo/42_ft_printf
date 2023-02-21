/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_last.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:47:53 by arebelo           #+#    #+#             */
/*   Updated: 2023/02/21 19:19:13 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_unsign(t_print *specs)
{
	unsigned int	u;
	unsigned int	temp;

	u = va_arg(specs->ap, unsigned int);
	counter_ul_base(u, "0123456789", specs);
	if (specs->dot == 1 && u == 0 && specs->str == 0)
		specs->size = 0;
	if (specs->str < specs->size)
		temp = specs->size;
	else
		temp = specs->str;
	if (specs->r_ident == 0 && specs->mfw != 0)
		print_mfw(specs, temp);
	if (specs->dot != 1 || u != 0 || specs->str != 0)
		ft_putnbr_xu(u, 1, specs, temp);
	if (specs->r_ident == 1 && specs->mfw != 0)
		print_mfw(specs, temp);
	clean_struct(specs);
}

static void	aux_one(t_print *specs, unsigned int u, unsigned int temp)
{
	if (specs->hex == 1 && u != 0 && specs->filler == ' ')
		specs->len += write(1, "0x", 2);
	ft_putnbr_base_x(u, "0123456789abcdef", specs, temp);
}

void	print_hex_lower(t_print *specs)
{
	unsigned int	u;
	unsigned int	temp;

	u = va_arg(specs->ap, unsigned int);
	counter_ul_base(u, "0123456789abcdef", specs);
	if (specs->hex == 1 && specs->mfw > 0 && u != 0)
		specs->mfw -= 2;
	if (specs->dot == 1 && u == 0 && specs->str == 0)
		specs->size = 0;
	if (specs->str < specs->size)
		temp = specs->size;
	else
		temp = specs->str;
	if (specs->hex == 1 && u != 0 && specs->filler == '0')
		specs->len += write(1, "0x", 2);
	if (specs->r_ident == 0 && specs->mfw != 0)
		print_mfw(specs, temp);
	if (specs->dot != 1 || u != 0 || specs->str != 0)
		aux_one(specs, u, temp);
	if (specs->r_ident == 1 && specs->mfw != 0)
		print_mfw(specs, temp);
	clean_struct(specs);
}

static void	aux_two(t_print *specs, unsigned int u, unsigned int temp)
{
	if (specs->hex == 1 && u != 0 && specs->filler == ' ')
		specs->len += write(1, "0X", 2);
	ft_putnbr_base_x(u, "0123456789ABCDEF", specs, temp);
}

void	print_hex_upper(t_print *specs)
{
	unsigned int	u;
	unsigned int	temp;

	u = va_arg(specs->ap, unsigned int);
	counter_ul_base(u, "0123456789abcdef", specs);
	if (specs->hex == 1 && specs->mfw > 0 && u != 0)
		specs->mfw -= 2;
	if (specs->dot == 1 && u == 0 && specs->str == 0)
		specs->size = 0;
	if (specs->str < specs->size)
		temp = specs->size;
	else
		temp = specs->str;
	if (specs->hex == 1 && u != 0 && specs->filler == '0')
		specs->len += write(1, "0X", 2);
	if (specs->r_ident == 0 && specs->mfw != 0)
		print_mfw(specs, temp);
	if (specs->dot != 1 || u != 0 || specs->str != 0)
		aux_two(specs, u, temp);
	if (specs->r_ident == 1 && specs->mfw != 0)
		print_mfw(specs, temp);
	clean_struct(specs);
}
