/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:34:58 by joandre-          #+#    #+#             */
/*   Updated: 2023/11/25 22:07:10 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"

static int	ft_to_specifier(va_list fsrc, const char *format, size_t *iterate)
{
	size_t	i;
	int		out;

	out = 0;
	i = 0;
	if (format[++i] == '.')
		out += ft_specifier_bonus(fsrc, &format[i], &i);
	else
		out += ft_specifier(fsrc, format[i]);
	i += ft_check_iterate_bonus(&format[i]);
	*iterate += i;
	return (out);
}

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
			out += ft_to_specifier(fsrc, &format[i], &i);
		else if (format[i] != '%')
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
	cp = printf("[%%%%]\t[%%.]\n[%%s]\t[%.8s]\n[%%c]\t[%c]\n",
			s, c);
	printf("[CHARACTERS PRINTED]\t[%zu]\n\n", cp);
	cp = printf("[%%i]\t[%.15i]\n[%%d]\t[%.20d]\n[%%u]\t[%.25u]\n",
			i, d, u);
	printf("[CHARACTERS PRINTED]\t[%zu]\n\n", cp);
	cp = printf("[%%x]\t[%.30x]\n[%%X]\t[%.35X]\n[%%p]\t[%.35p]\n",
			x, X, p);
	printf("[CHARACTERS PRINTED]\t[%zu]\n", cp);
	ft_printf("\n\n\t***\tFT_PRINTF\t***\n\n");
	cp = ft_printf("[%%%%]\t[%%.]\n[%%s]\t[%.8s]\n[%%c]\t[%c]\n",
			s, c);
	printf("[CHARACTERS PRINTED]\t[%zu]\n\n", cp);
	cp = ft_printf("[%%i]\t[%.15i]\n[%%d]\t[%.20d]\n[%%u]\t[%.25u]\n",
			i, d, u);
	printf("[CHARACTERS PRINTED]\t[%zu]\n\n", cp);
	cp = ft_printf("[%%x]\t[%.30x]\n[%%X]\t[%.35X]\n[%%p]\t[%.35p]\n",
			x, X, p);
	printf("[CHARACTERS PRINTED]\t[%zu]\n", cp);
	free(p);
	return (0);
}*/
