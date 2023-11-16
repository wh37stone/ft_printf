/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:23:16 by joandre-          #+#    #+#             */
/*   Updated: 2023/11/14 19:41:28 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "Libft/libft.h"
# include <stdarg.h>
# include <limits.h>

int		ft_printf(const char *format, ...);
void	ft_specifier(va_list fsrc, const char specifier);
void	ft_putunbr_fd(unsigned int n, int fd);
void	ft_puthex_fd(unsigned int n, const char specifier, int fd);
void	ft_putaddr_fd(unsigned long long n, int fd);

#endif
