/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_first.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:41:04 by arebelo           #+#    #+#             */
/*   Updated: 2023/02/21 19:19:13 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_char(t_print *specs)
{
	char	c;

	c = (char)va_arg(specs->ap, int);
	specs->size = 1;
	if (specs->r_ident == 0 && specs->mfw != 0)
		print_mfw(specs, specs->size);
	specs->len += write(1, &c, 1);
	if (specs->r_ident == 1 && specs->mfw != 0)
		print_mfw(specs, specs->size);
	clean_struct(specs);
}

void	print_str(t_print *specs)
{
	char	*str;

	str = va_arg(specs->ap, char *);
	if (!str)
		str = "(null)";
	if (specs->dot == 1 && ft_strlen(str) > specs->str)
		specs->size = specs->str;
	else
		specs->size = ft_strlen(str);
	specs->len += specs->size;
	if (specs->r_ident == 0 && specs->mfw != 0)
		print_mfw(specs, specs->size);
	if (specs->dot == 0)
		ft_putstr_fd(str, 1);
	if (specs->dot == 1)
		putstr_limited(str, specs);
	if (specs->r_ident == 1 && specs->mfw != 0)
		print_mfw(specs, specs->size);
	clean_struct(specs);
}

static void	aux_one(t_print *specs)
{
	specs->mfw--;
	if (specs->mfw > 0)
		specs->mfw--;
}

void	print_pointer(t_print *specs)
{
	unsigned long	ptr;
	unsigned int	temp;

	ptr = (unsigned long)va_arg(specs->ap, void *);
	specs->size += 2;
	counter_ul_base(ptr, "0123456789abcdef", specs);
	if (specs->dot == 1 && ptr == 0 && specs->str == 0)
		specs->size = 0;
	if (!ptr && specs->mfw > 0 && specs->dot == 1)
		aux_one(specs);
	if (specs->str < specs->size)
		temp = specs->size;
	else
		temp = specs->str;
	if (specs->r_ident == 0 && specs->mfw != 0)
		print_mfw(specs, temp);
	specs->len += write(1, "0x", 2);
	if (specs->dot != 1 || ptr != 0 || specs->str != 0)
		ft_putnbr_base_x(ptr, "0123456789abcdef", specs, temp);
	if (specs->r_ident == 1 && specs->mfw != 0)
		print_mfw(specs, temp);
	clean_struct(specs);
}

void	print_int(t_print *specs)
{
	int				i;
	unsigned int	temp;

	i = va_arg(specs->ap, int);
	counter_int(i, specs);
	if (specs->dot == 1 && i == 0 && specs->str == 0)
		specs->size = 0;
	if (i < 0)
		specs->str++;
	if (specs->sign == 1 && i >= 0)
		if (specs->mfw > 0)
			specs->mfw--;
	if (specs->str < specs->size)
		temp = specs->size;
	else
		temp = specs->str;
	if (specs->r_ident == 0 && specs->filler == ' ' && specs->mfw != 0)
		print_mfw(specs, temp);
	if (specs->sign == 1 && i >= 0)
		specs->len += write(1, &specs->sign_filler, 1);
	if (specs->dot != 1 || i != 0 || specs->str != 0)
		ft_putnbr_x(i, 1, specs, temp);
	if (specs->r_ident == 1 && specs->mfw != 0)
		print_mfw(specs, temp);
	clean_struct(specs);
}
