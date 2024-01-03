/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 01:14:28 by joandre-          #+#    #+#             */
/*   Updated: 2024/01/03 02:59:51 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	size_t	size;

	size = ft_strlen(s);
	str = (char *)s;
	if (c == 0)
		return (str + size);
	while (size)
	{
		if (str[size - 1] == (unsigned char)c)
			return (str + size - 1);
		size--;
	}
	return (NULL);
}
