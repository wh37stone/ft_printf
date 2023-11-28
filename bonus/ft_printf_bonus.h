/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:23:16 by joandre-          #+#    #+#             */
/*   Updated: 2023/11/25 21:28:05 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "../Libft/libft.h"
# include <stdarg.h>
# include <limits.h>

int		ft_printf(const char *format, ...);
size_t	ft_specifier(va_list fsrc, const char specifier);
size_t	ft_specifier_bonus(va_list fsrc, const char *specifier,
			size_t *iterate);
size_t	ft_putstr_bonus(const char *format, size_t len);
size_t	ft_putnbr_bonus(int n, size_t len);
size_t	ft_putunbr_bonus(unsigned int n, size_t len);
size_t	ft_puthexa_bonus(unsigned long long n, size_t len,
			const char specifier);
size_t	ft_print_zero_bonus(size_t nsize, size_t len);
size_t	ft_check_iterate_bonus(const char *format);

#endif
