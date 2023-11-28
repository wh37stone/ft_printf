/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_zero_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 03:02:13 by joandre-          #+#    #+#             */
/*   Updated: 2023/11/25 20:42:55 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"

size_t	ft_print_zero_bonus(size_t nsize, size_t len)
{
	size_t	z;
	size_t	nzero;

	z = len - nsize;
	nzero = z;
	while (z--)
		ft_putchar_fd('0', 1);
	return (nzero);
}
