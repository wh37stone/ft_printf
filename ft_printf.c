/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:11:49 by joandre-          #+#    #+#             */
/*   Updated: 2023/11/25 20:31:11 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	fsrc;
	size_t	i;
	int		out;

	if (!format)
		return (-1);
	va_start(fsrc, format);
	out = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			out += ft_specifier(fsrc, format[i]);
			i++;
		}
		else
		{
			ft_putchar_fd(format[i++], 1);
			out++;
		}
	}
	va_end(fsrc);
	return (out);
}
/*
int	main(void)
{
	int					c = 'L';
	int					i = INT_MAX;
	int					d = INT_MIN;
	unsigned int		u = 0;
	unsigned int		x = 4242424242;
	unsigned int		X = UINT_MAX;
	char				*s = "Suspendisse potenti.";
	void				*p = malloc(sizeof(void *));
	size_t				cp;

	printf("\t***\tORIGINAL\t***\n\n");
	cp = printf("[%%%%]\t[%%]\n[%%s]\t[%s]\n[%%c]\t[%c]\n",
			s, c);
	printf("[CHARACTERS PRINTED]\t[%zu]\n\n", cp);
	cp = printf("[%%i]\t[%i]\n[%%d]\t[%d]\n[%%u]\t[%u]\n",
			i, d, u);
	printf("[CHARACTERS PRINTED]\t[%zu]\n\n", cp);
	cp = printf("[%%x]\t[%x]\n[%%X]\t[%X]\n[%%p]\t[%p]\n",
			x, X, p);
	printf("[CHARACTERS PRINTED]\t[%zu]\n", cp);
	ft_printf("\n\n\t***\tFT_PRINTF\t***\n\n");
	cp = ft_printf("[%%%%]\t[%%]\n[%%s]\t[%s]\n[%%c]\t[%c]\n",
			s, c);
	printf("[CHARACTERS PRINTED]\t[%zu]\n\n", cp);
	cp = ft_printf("[%%i]\t[%i]\n[%%d]\t[%d]\n[%%u]\t[%u]\n",
			i, d, u);
	printf("[CHARACTERS PRINTED]\t[%zu]\n\n", cp);
	cp = ft_printf("[%%x]\t[%x]\n[%%X]\t[%X]\n[%%p]\t[%p]\n",
			x, X, p);
	printf("[CHARACTERS PRINTED]\t[%zu]\n", cp);
	free(p);
	return (0);
}*/
