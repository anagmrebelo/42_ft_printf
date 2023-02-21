/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:02:56 by arebelo           #+#    #+#             */
/*   Updated: 2023/02/21 19:19:13 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	aux_one(t_print *specs);
static void	aux_two(t_print *specs, const char *str);
static void	aux_three(char c, t_print *specs);

int	conversion(const char *c, t_print *specs)
{
	int	counter;

	counter = 0;
	if (c[counter] == 'c')
		print_char(specs);
	else if (c[counter] == 's')
		print_str(specs);
	else if (c[counter] == 'p')
		print_pointer(specs);
	else if (c[counter] == 'i' || c[counter] == 'd')
		print_int(specs);
	else if (c[counter] == 'u')
		print_unsign(specs);
	else if (c[counter] == 'x')
		print_hex_lower(specs);
	else if (c[counter] == 'X')
		print_hex_upper(specs);
	else if (c[counter] == '%')
		print_percent(specs);
	return (counter + 1);
}

int	format(const char *c, t_print *specs)
{
	int	counter;

	counter = 0;
	while (!is_id(c[counter]) && c[counter])
	{	
		aux_three(c[counter], specs);
		if (c[counter] == '-')
			aux_one(specs);
		else if (ft_isdigit(c[counter]) && c[counter] != 0)
		{
			specs->mfw = ft_atoi(&c[counter]);
			while (ft_isdigit(c[counter]))
				counter++;
			continue ;
		}
		else if (c[counter] == '.')
		{	
			aux_two(specs, &c[++counter]);
			while (ft_isdigit(c[counter]))
				counter++;
			continue ;
		}
		counter++;
	}
	return (counter);
}

static void	aux_one(t_print *specs)
{	
	specs->filler = ' ';
	specs->r_ident = 1;
}	

static void	aux_two(t_print *specs, const char *str)
{
	specs->str = ft_atoi(str);
	specs->dot = 1;
	specs->filler = ' ';
}

static void	aux_three(char c, t_print *specs)
{
	if (c == '0' && specs->r_ident == 0)
	{
		specs->filler = '0';
		specs->percent = 1;
	}
	if (c == '#')
		specs->hex = 1;
	if (c == ' ' || c == '+')
	{
		specs->sign = 1;
		if (c == '+')
			specs->sign_filler = '+';
	}
}
