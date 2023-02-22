/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarebelo <anarebelo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:01:21 by arebelo           #+#    #+#             */
/*   Updated: 2023/02/21 22:01:41 by anarebelo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*ptr;
	unsigned long	size;

	if (!s1 || !s2)
		return (0);
	size = ft_strlen(s1) + ft_strlen(s2);
	ptr = malloc(size + 1);
	if (!ptr)
		return (0);
	ft_memcpy(ptr, s1, ft_strlen(s1));
	ft_memcpy(&ptr[ft_strlen(s1)], s2, ft_strlen(s2));
	ptr[size] = '\0';
	return (ptr);
}
