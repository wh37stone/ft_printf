/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:58:33 by joandre-          #+#    #+#             */
/*   Updated: 2023/11/17 17:58:54 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	ft_output(unsigned int n)
{
	if (n / 10)
	{
		ft_output(n / 10);
		ft_output(n % 10);
	}
	else if (n < 10)
		ft_putchar_fd(n + '0', 1);
}

size_t	ft_putunbr(unsigned int n, size_t len)
{
	size_t			nsize;
	unsigned int	num;

	nsize = 0;
	num = n;
	while (n)
	{
		n /= 10;
		nsize++;
	}
	if (len > nsize)
		nsize += ft_print_zero(nsize, len);
	ft_output(num);
	return (nsize);
}
