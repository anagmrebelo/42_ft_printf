/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:48:46 by arebelo           #+#    #+#             */
/*   Updated: 2023/02/21 19:19:13 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	int		num;
	int		counter;
	t_print	*specs;

	specs = (t_print *)malloc(sizeof(t_print));
	if (!specs)
		return (0);
	initialize_struct(specs);
	num = 0;
	counter = -1;
	va_start(specs->ap, format);
	while (format[++counter])
	{
		if (format[counter] != '%')
			specs->len += write(1, &format[counter], 1);
		else
			counter += conversion(&format[counter + 1], specs);
	}
	va_end(specs->ap);
	num = specs->len;
	free(specs);
	return (num);
}
