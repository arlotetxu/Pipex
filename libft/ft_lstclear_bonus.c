/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:06:28 by jflorido          #+#    #+#             */
/*   Updated: 2022/10/01 16:38:42 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aux;

	while (*lst != NULL)
	{
		aux = (*lst)->next;
		(del)((*lst)->content);
		free(*lst);
		*lst = NULL;
		*lst = aux;
	}
	*lst = NULL;
}
