/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier.c                                    :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 22:38:30 by joandre-          #+#    #+#             */
/*   Updated: 2023/11/09 02:09:45 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

size_t	ft_specifier(va_list fsrc, const char *specifier)
{
	size_t	out;

	out = 1;
	if (*specifier == '%')
		ft_putchar_fd('%', 1);
	else if (*specifier == 'c')
		ft_putchar_fd(va_arg(fsrc, int), 1);
	else if (*specifier == 's')
		out = ft_putstr(va_arg(fsrc, char *), 0);
	else if (*specifier == 'i' || *specifier == 'd')
		out = ft_putnbr(va_arg(fsrc, int), 0);
	else if (*specifier == 'u')
		out = ft_putunbr(va_arg(fsrc, unsigned int), 0);
	else if (*specifier == 'x' || *specifier == 'X' || *specifier == 'p')
		out = ft_puthexa(va_arg(fsrc, unsigned long long), 0, *specifier);
	else if (*(--specifier) == '%')
	{
		write(1, &(*(specifier)), 2);
		out = 2;
	}
	return (out);
}
