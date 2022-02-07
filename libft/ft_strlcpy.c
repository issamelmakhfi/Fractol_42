/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmakhf <ielmakhf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:07:25 by ielmakhf          #+#    #+#             */
/*   Updated: 2021/11/13 03:29:25 by ielmakhf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char	*s;
	size_t	t;
	size_t	i;

	t = ft_strlen((char *)src);
	s = (char *)src;
	i = 0;
	if (t + 1 < size)
		ft_memcpy(dst, s, t + 1);
	else if (size != 0)
	{
		ft_memcpy(dst, s, size - 1);
		dst[size - 1] = '\0';
	}
	return (t);
}
