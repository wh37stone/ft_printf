/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 21:21:38 by joandre-          #+#    #+#             */
/*   Updated: 2024/01/03 02:53:30 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*clear;
	t_list	*linx;

	if (!lst || !del)
		return ;
	clear = *lst;
	while (clear)
	{
		linx = clear->next;
		(*del)(clear->content);
		free(clear);
		clear = linx;
	}
	*lst = NULL;
}
