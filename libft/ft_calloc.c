/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmakhf <ielmakhf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:37:24 by ielmakhf          #+#    #+#             */
/*   Updated: 2021/11/12 16:44:52 by ielmakhf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	k;
	char	*buffer;

	k = count * size;
	buffer = (char *)malloc(k);
	if (!buffer)
		return (NULL);
	ft_bzero(buffer, k);
	return (buffer);
}
