/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:00:06 by arebelo           #+#    #+#             */
/*   Updated: 2023/02/21 17:25:45 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned long	size;
	char			*ptr;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
		size = 0;
	else if (ft_strlen(s + start) >= len)
		size = len;
	else
		size = ft_strlen(s + start);
	ptr = malloc(size + 1);
	if (!ptr)
		return (0);
	ptr[size] = '\0';
	if (size > 0)
		ft_memcpy(ptr, &s[start], size);
	return (ptr);
}
