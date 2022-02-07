/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmakhf <ielmakhf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:32:09 by ielmakhf          #+#    #+#             */
/*   Updated: 2021/11/08 16:43:14 by ielmakhf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int value, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n)
	{
		*p = (unsigned char)value;
		p++;
		n--;
	}
	return (s);
}
