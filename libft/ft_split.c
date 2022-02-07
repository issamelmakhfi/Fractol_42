/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmakhf <ielmakhf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 15:00:56 by ielmakhf          #+#    #+#             */
/*   Updated: 2021/11/13 17:10:58 by ielmakhf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_w(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	if ((s[0] == c))
		count = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			count++;
		i++;
	}
	if (s[i - 1] == c)
		count--;
	return (count);
}

static char	**free_tab(char **tab, int block)
{
	while (block--)
		free(tab[block]);
	return (NULL);
}

static char	**alloc(char **tab, char const *s, char c, int size)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (*s)
	{
		while (s[i] != c && s[i] != '\0')
			i++;
		if (i != 0 && k < size)
		{
			tab[k] = (char *) malloc((i + 1) * sizeof(char));
			if (!tab)
				return (free_tab(tab, size));
			ft_memcpy(tab[k], s, i);
			tab[k][i] = '\0';
			k++;
			s = s + i ;
			i = 0;
		}
		else
			s++;
	}
	tab[k] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	int		size;
	char	**tab;

	tab = NULL;
	if (!s)
		return (NULL);
	size = count_w(s, c);
	tab = (char **) malloc((size + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	tab = alloc(tab, s, c, size);
	return (tab);
}
