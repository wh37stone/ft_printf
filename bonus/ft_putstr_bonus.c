/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 22:30:40 by joandre-          #+#    #+#             */
/*   Updated: 2023/11/25 22:13:43 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"

size_t	ft_putstr_bonus(const char *format, size_t len)
{
	char	*str;
	size_t	size;

	if (!format)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	size = ft_strlen(format);
	if (len == 0)
		len = size;
	str = malloc(len + 1);
	if (!str)
		return (0);
	ft_strlcpy(str, format, len + 1);
	size = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (size);
}
