/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmakhf <ielmakhf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:49:06 by ielmakhf          #+#    #+#             */
/*   Updated: 2021/11/13 03:33:01 by ielmakhf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ds;
	t_list	*p;

	ds = *lst;
	if (!*lst || !del)
		return ;
	while (ds->next != NULL)
	{
		p = ds->next;
		del(ds->content);
		free(ds);
		ds = p;
	}
	del(ds->content);
	free(ds);
	*lst = NULL;
}
