/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_iterate_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 02:32:48 by joandre-          #+#    #+#             */
/*   Updated: 2023/11/25 20:41:47 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"

size_t	ft_check_iterate_bonus(const char *format)
{
	size_t	i;

	i = 0;
	if (format[i++] == '.')
	{
		while (format[i] == 's' || format[i] == 'd' || format[i] == 'i'
			|| format[i] == 'u' || format[i] == 'x' || format[i] == 'X'
			|| format[i] == 'p' || (format[i] >= '0' && format[i] <= '9'))
			i++;
	}
	return (i);
}
