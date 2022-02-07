/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmakhf <ielmakhf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:13:09 by ielmakhf          #+#    #+#             */
/*   Updated: 2021/11/12 23:07:23 by ielmakhf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s;
	char	*d;
	char	*buffd;
	char	*buffs;

	d = (char *)dst ;
	s = (char *)src;
	if (!d && !s)
		return (NULL);
	if (d < s)
		while (len--)
			*d++ = *s++;
	else
	{
		buffs = s + (len - 1);
		buffd = d + (len - 1);
		while (len--)
			*buffd-- = *buffs--;
	}
	return (dst);
}
