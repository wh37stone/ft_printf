/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 01:30:34 by joandre-          #+#    #+#             */
/*   Updated: 2024/01/03 02:53:03 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*adb;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	adb = *lst;
	while (adb->next)
		adb = adb->next;
	adb->next = new;
}
