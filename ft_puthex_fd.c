/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 19:12:42 by joandre-          #+#    #+#             */
/*   Updated: 2023/11/12 19:14:08 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_puthex_fd(unsigned int n, const char specifier, int fd)
{
	if (n >= 16)
	{
		ft_puthex_fd(n / 16, specifier, fd);
		ft_puthex_fd(n % 16, specifier, fd);
	}
	if (n <= 9)
		ft_putchar_fd(n + '0', fd);
	else if (n < 16)
	{
		if (specifier == 'x')
			ft_putchar_fd(n - 10 + 'a', fd);
		if (specifier == 'X')
			ft_putchar_fd(n - 10 + 'A', fd);
	}
}
