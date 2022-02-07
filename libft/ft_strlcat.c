/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmakhf <ielmakhf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:37:58 by ielmakhf          #+#    #+#             */
/*   Updated: 2021/11/13 03:29:11 by ielmakhf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	char	*s;
	size_t	slen;
	size_t	dlen;

	s = (char *)src;
	slen = ft_strlen(s);
	dlen = ft_strlen(dest);
	if (n < dlen)
		return (slen + n);
	else
	{
		dest = dest + dlen;
		ft_strlcpy(dest, s, n - dlen);
		return (slen + dlen);
	}
}
