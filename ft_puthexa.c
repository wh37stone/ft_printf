/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:58:33 by joandre-          #+#    #+#             */
/*   Updated: 2023/11/17 17:58:54 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	ft_hexalloc(char c, char *hexa)
{
	while (*hexa)
		hexa++;
	*hexa = c;
	*(++hexa) = '\0';
}

static void	ft_hextoa(unsigned int n, char *hexa, const char specifier)
{
	if (n >= 16)
	{
		ft_hextoa(n / 16, hexa, specifier);
		ft_hextoa(n % 16, hexa, specifier);
	}
	if (n <= 9)
		ft_hexalloc(n + '0', hexa);
	else if (n < 16)
	{
		if (specifier == 'X')
			ft_hexalloc(n - 10 + 'A', hexa);
		else if (specifier == 'x')
			ft_hexalloc(n - 10 + 'a', hexa);
	}
}

static void	ft_long_hextoa(unsigned long long n, char *hexa)
{
	if (n >= 16)
	{
		ft_long_hextoa(n / 16, hexa);
		ft_long_hextoa(n % 16, hexa);
	}
	if (n <= 9)
		ft_hexalloc(n + '0', hexa);
	else if (n < 16)
		ft_hexalloc(n - 10 + 'a', hexa);
}

size_t	ft_puthexa(unsigned long long n, size_t len, const char specifier)
{
	size_t	nsize;
	char	*hexa;

	nsize = 0;
	hexa = malloc(16 + 1);
	if (!hexa)
		return (nsize);
	if (specifier == 'x' || specifier == 'X')
		ft_hextoa(n, hexa, specifier);
	else if (specifier == 'p')
	{
		ft_long_hextoa(n, hexa);
		ft_putstr_fd("0x", 1);
	}
	nsize += ft_strlen(hexa);
	if (len > nsize)
		nsize += ft_print_zero(nsize, len);
	ft_putstr_fd(hexa, 1);
	free(hexa);
	if (specifier == 'p')
		return (nsize + 2);
	return (nsize);
}
