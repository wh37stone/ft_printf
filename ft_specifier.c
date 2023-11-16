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

void	ft_specifier(va_list fsrc, const char specifier)
{
	if (specifier == '%')
		ft_putchar_fd('%', 1);
	else if (specifier == 's')
		ft_putstr_fd(va_arg(fsrc, char *), 1);
	else if (specifier == 'c')
		ft_putchar_fd(va_arg(fsrc, int), 1);
	else if (specifier == 'i' || specifier == 'd')
		ft_putnbr_fd(va_arg(fsrc, int), 1);
	else if (specifier == 'u')
		ft_putunbr_fd(va_arg(fsrc, unsigned int), 1);
	else if (specifier == 'x' || specifier == 'X')
		ft_puthex_fd(va_arg(fsrc, unsigned long long), specifier, 1);
	else if (specifier == 'p')
		ft_putaddr_fd(va_arg(fsrc, unsigned long long), 1);
}
