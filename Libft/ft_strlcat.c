/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 01:07:57 by joandre-          #+#    #+#             */
/*   Updated: 2024/01/03 02:58:36 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	len;
	size_t	i;

	len = 0;
	while (len < n && dst[len])
		len++;
	if (len == n)
		return (len + ft_strlen(src));
	dst += len;
	i = 0;
	while (src[i])
	{
		if ((n - len - 1) > i)
			*dst++ = src[i];
		i++;
	}
	*dst++ = '\0';
	return (len + i);
}
