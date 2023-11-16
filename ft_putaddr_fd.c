/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 23:24:31 by joandre-          #+#    #+#             */
/*   Updated: 2023/11/13 23:32:46 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	ft_printhex(unsigned long long n, int fd)
{
	if (n >= 16)
	{
		ft_printhex(n / 16, fd);
		ft_printhex(n % 16, fd);
	}
	if (n <= 9)
		ft_putchar_fd(n + '0', fd);
	else if (n < 16)
		ft_putchar_fd(n - 10 + 'a', fd);
}

void	ft_putaddr_fd(unsigned long long n, int fd)
{
	ft_putstr_fd("0x", fd);
	ft_printhex(n, fd);
}
