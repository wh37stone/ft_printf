/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 02:22:33 by joandre-          #+#    #+#             */
/*   Updated: 2023/11/10 02:38:07 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putunbr_fd(unsigned int n, int fd)
{
	if (n / 10)
	{
		ft_putunbr_fd(n / 10, fd);
		ft_putunbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}
/*
int	main(void)
{
  unsigned int	nbr[] = {UINT_MAX, 0, 12938127};
  
  for (int i = 0; i < 3; i++)
  {
	ft_putchar_fd('[', 1);
	ft_putunbr_fd(nbr[i], 1);
	ft_putstr_fd("]\t", 1);
  }
  ft_putchar_fd('\n', 1);
  return (0);
}*/
