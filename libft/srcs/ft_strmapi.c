/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:16:13 by arebelo           #+#    #+#             */
/*   Updated: 2023/02/21 17:25:45 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	counter;
	unsigned int	len;
	char			*ptr;

	if (!s)
		return (0);
	counter = 0;
	len = ft_strlen(s);
	ptr = malloc(len + 1);
	if (!ptr)
		return (0);
	while (counter < len)
	{
		ptr[counter] = f(counter, s[counter]);
		counter++;
	}
	ptr[len] = '\0';
	return (ptr);
}
