/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:52:26 by arebelo           #+#    #+#             */
/*   Updated: 2023/02/21 17:54:11 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long	aux_count(char const *s1, char const *set);
static int				aux_match(const char s, const char *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned long	counter;
	char			*ptr;

	if (!s1)
		return (0);
	counter = 0;
	ptr = malloc(aux_count(s1, set) + 1);
	if (!ptr)
		return (0);
	ptr[aux_count(s1, set)] = '\0';
	while (aux_match(s1[counter], set) == 1 && counter < ft_strlen(s1))
		counter++;
	ft_memcpy(ptr, &s1[counter], aux_count(s1, set));
	return (ptr);
}

static unsigned long	aux_count(char const *s1, char const *set)
{
	unsigned long	counter;
	const char		*start;

	counter = -1;
	start = 0;
	while (++counter < ft_strlen(s1))
	{
		if (aux_match(s1[counter], set) == 0)
		{
			start = &s1[counter];
			break ;
		}
	}
	counter = ft_strlen(s1);
	while (--counter < ft_strlen(s1))
	{
		if (aux_match(s1[counter], set) == 0)
			return (&s1[counter] - start + 1);
	}
	return (0);
}

static int	aux_match(const char s, const char *set)
{
	size_t	counter;
	size_t	result;

	result = 0;
	counter = 0;
	while (counter < ft_strlen(set))
	{
		if (ft_strncmp(&s, &set[counter], 1) == 0)
		{
			result = 1;
			break ;
		}
		counter++;
	}
	return (result);
}
