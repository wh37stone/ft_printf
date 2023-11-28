/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:03:55 by joandre-          #+#    #+#             */
/*   Updated: 2023/11/25 22:02:34 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"

static size_t	ft_modot_printer(size_t modot)
{
	size_t	out;

	out = 0;
	while (modot--)
	{
		ft_putstr_fd("%.", 1);
		out += 2;
	}
	return (out);
}

static size_t	ft_modot(const char *format, size_t *iterate)
{
	size_t	modot;
	size_t	out;
	size_t	i;

	modot = 0;
	out = 0;
	i = 0;
	while (format[i++] == '%')
	{
		if (format[i] == '.')
			modot++;
		else if (format[i] == '%')
		{
			ft_putchar_fd(format[i], 1);
			return (++out);
		}
		else
			break ;
	}
	out += ft_modot_printer(modot);
	ft_putchar_fd(format[i--], 1);
	*iterate += i;
	return (++out);
}

size_t	ft_specifier_bonus(va_list fsrc, const char *specifier, size_t *iterate)
{
	size_t	len;
	size_t	out;

	len = atoi(++specifier);
	if (len == 0)
		--specifier;
	while (*specifier != 'p' && *specifier != 'x' && *specifier != 'X'
		&& *specifier != 'i' && *specifier != 'd' && *specifier != 'u'
		&& *specifier != 's' && *specifier != '.' && *specifier != '%')
		specifier++;
	if (*specifier == '.')
		out = ft_modot(--specifier, iterate);
	if (*specifier == 's')
		out = ft_putstr_bonus(va_arg(fsrc, char *), len);
	else if (*specifier == 'i' || *specifier == 'd')
		out = ft_putnbr_bonus(va_arg(fsrc, int), len);
	else if (*specifier == 'u')
		out = ft_putunbr_bonus(va_arg(fsrc, unsigned int), len);
	else if (*specifier == 'x' || *specifier == 'X' || *specifier == 'p')
		out = ft_puthexa_bonus(va_arg(fsrc, unsigned long long),
				len, *specifier);
	return (out);
}
