/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:56:11 by arebelo           #+#    #+#             */
/*   Updated: 2023/02/21 17:25:45 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned long	counter;

	if (c > 255)
	{
		while (c > 256)
			c -= 256;
	}
	if (c < 0)
	{
		while (c < -1)
			c += 256;
	}
	counter = ft_strlen(s);
	if (c == 0)
		return ((char *)&s[counter]);
	while (counter != 0)
	{
		if (s[counter - 1] == c)
			return ((char *)&s[counter - 1]);
		counter--;
	}
	return (0);
}
