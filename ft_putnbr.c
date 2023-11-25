/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 22:39:54 by joandre-          #+#    #+#             */
/*   Updated: 2023/11/16 23:08:40 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

size_t	ft_putnbr(int n, size_t len)
{
	size_t	nsize;

	nsize = ft_strlen(ft_itoa(n));
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		nsize -= 1;
		if (n == -2147483648)
		{
			if (len > nsize)
				nsize += ft_print_zero(nsize, len);
			ft_putstr_fd("2147483648", 1);
			return (nsize + 1);
		}
		n = -n;
		nsize++;
	}
	if (len > nsize)
		nsize += ft_print_zero(nsize, len);
	ft_putnbr_fd(n, 1);
	return (nsize);
}
