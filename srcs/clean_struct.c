/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:52:06 by arebelo           #+#    #+#             */
/*   Updated: 2023/02/21 19:19:13 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	initialize_struct(t_print *specs)
{	
	specs->mfw = 0;
	specs->len = 0;
	specs->size = 0;
	specs->dot = 0;
	specs->str = 0;
	specs->hex = 0;
	specs->r_ident = 0;
	specs->filler = ' ';
	specs->percent = 0;
	specs->sign = 0;
	specs->sign_filler = ' ';
}

void	clean_struct(t_print *specs)
{
	specs->mfw = 0;
	specs->size = 0;
	specs->dot = 0;
	specs->str = 0;
	specs->r_ident = 0;
	specs->hex = 0;
	specs->filler = ' ';
	specs->percent = 0;
	specs->sign = 0;
	specs->sign_filler = ' ';
}
