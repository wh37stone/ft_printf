/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:23:16 by joandre-          #+#    #+#             */
/*   Updated: 2023/11/25 19:43:32 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "Libft/libft.h"
# include <stdarg.h>
# include <limits.h>

int		ft_printf(const char *format, ...);
size_t	ft_putstr(const char *format);
size_t	ft_putnbr(int n);
size_t	ft_putunbr(unsigned int n);
size_t	ft_puthexa(unsigned long long n, const char specifier);
size_t	ft_specifier(va_list fsrc, const char specifier);

#endif
