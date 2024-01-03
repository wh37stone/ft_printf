/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 01:02:45 by joandre-          #+#    #+#             */
/*   Updated: 2024/01/03 02:55:33 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*mch;

	mch = (unsigned char *)s;
	while (n && *mch != (unsigned char)c)
	{
		mch++;
		n--;
	}
	if (!n)
		return (NULL);
	return ((void *)mch);
}
