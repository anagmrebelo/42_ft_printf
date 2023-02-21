/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mfw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:55:51 by arebelo           #+#    #+#             */
/*   Updated: 2023/02/21 19:19:13 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_mfw(t_print *specs, unsigned int i)
{
	if (specs->percent == 2)
		specs->filler = '0';
	while (specs->mfw > i)
	{
		specs->len += write(1, &specs->filler, 1);
		specs->mfw--;
	}
}
