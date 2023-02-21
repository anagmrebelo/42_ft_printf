/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_limited.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 22:40:42 by arebelo           #+#    #+#             */
/*   Updated: 2023/02/21 19:19:13 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	putstr_limited(char *s, t_print *specs)
{
	unsigned long	len;
	unsigned long	counter;

	if (!s)
		return ;
	len = ft_strlen(s);
	counter = 0;
	while (counter < len && specs->str > 0)
	{
		ft_putchar_fd(s[counter], 1);
		counter++;
		specs->str--;
	}
}
