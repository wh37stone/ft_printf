/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 01:12:08 by joandre-          #+#    #+#             */
/*   Updated: 2024/01/03 02:59:40 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	size;

	if (!(*s2))
		return ((char *)s1);
	if (!n)
		return (NULL);
	size = ft_strlen(s2);
	while (*s1 && n >= size)
	{
		if (*s1 == *s2 && ft_strncmp(s1, s2, size) == 0)
			return ((char *)s1);
		s1++;
		n--;
	}
	return (NULL);
}
