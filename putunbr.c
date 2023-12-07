/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putunbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:58:33 by joandre-          #+#    #+#             */
/*   Updated: 2023/11/25 19:37:00 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	print_unbr(unsigned int n)
{
	if (n / 10)
	{
		print_unbr(n / 10);
		print_unbr(n % 10);
	}
	else if (n < 10)
		ft_putchar_fd(n + '0', 1);
}

size_t	putunbr(unsigned int n)
{
	size_t			size;
	unsigned int	nbr;

	size = 0;
	nbr = n;
	if (n == 0)
		size = 1;
	while (n)
	{
		n /= 10;
		size++;
	}
	print_unbr(nbr);
	return (size);
}
