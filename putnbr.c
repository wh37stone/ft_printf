/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 22:39:54 by joandre-          #+#    #+#             */
/*   Updated: 2023/11/25 19:36:37 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

size_t	putnbr(int n)
{
	size_t	nsize;

	nsize = ft_strlen(ft_itoa(n));
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		nsize -= 1;
		if (n == -2147483648)
		{
			ft_putstr_fd("2147483648", 1);
			return (nsize + 1);
		}
		n = -n;
		nsize++;
	}
	ft_putnbr_fd(n, 1);
	return (nsize);
}
