/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmakhf <ielmakhf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 08:43:30 by ielmakhf          #+#    #+#             */
/*   Updated: 2021/11/08 20:45:27 by ielmakhf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	size;
	char	*ptr;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr((char *)set, *s1))
		s1++;
	size = ft_strlen((char *)s1);
	while (size && ft_strchr((char *)set, s1[size - 1]))
		size--;
	ptr = malloc(size + 1);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s1, size);
	ptr[size] = '\0';
	return (ptr);
}
