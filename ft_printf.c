/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:11:49 by joandre-          #+#    #+#             */
/*   Updated: 2023/11/08 17:14:22 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	fsrc;
	size_t	i;

	if (!format)
		return (1);
	va_start(fsrc, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ft_specifier(fsrc, format[i]);
			i++;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			i++;
		}
	}
	va_end(fsrc);
	return (0);
}
/*
int	main(void)
{
	void	*ptr;

	ptr = malloc(sizeof(void *));
	printf("\t***\tORIGINAL\t***\n\n");
	printf("[%%%%]\t[%%]\n[%%s]\t[%s]\n[%%c]\t[%c]\n",
		"Suspendisse potenti.", '*');
	printf("[%%i]\t[%i]\n[%%d]\t[%d]\n[%%u]\t[%u]\n",
		INT_MIN, 10, UINT_MAX);
	printf("[%%x]\t[%x]\n[%%X]\t[%X]\n[%%p]\t[%p]\n",
		LLONG_MAX, UINT_MAX / 26, ptr);
	ft_printf("\n\n\t***\tFT_PRINTF\t***\n\n");
	ft_printf("[%%%%]\t[%%]\n[%%s]\t[%s]\n[%%c]\t[%c]\n",
		"Suspendisse potenti.", '*');
	ft_printf("[%%i]\t[%i]\n[%%d]\t[%d]\n[%%u]\t[%u]\n",
		INT_MIN, 10, UINT_MAX);
	ft_printf("[%%x]\t[%x]\n[%%X]\t[%X]\n[%%p]\t[%p]\n",
		LLONG_MAX, UINT_MAX / 26, ptr);
	free(ptr);
	return (0);
}*/
