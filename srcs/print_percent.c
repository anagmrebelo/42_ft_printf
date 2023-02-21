/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:11:51 by arebelo           #+#    #+#             */
/*   Updated: 2023/02/21 19:19:13 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_percent(t_print *specs)
{
	if (specs->r_ident == 0 && specs->mfw != 0)
		print_mfw(specs, 1);
	specs->len += write(1, "%", 1);
	if (specs->r_ident == 1 && specs->mfw != 0)
		print_mfw(specs, 1);
	clean_struct(specs);
}
