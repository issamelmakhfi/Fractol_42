/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmakhf <ielmakhf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:34:47 by ielmakhf          #+#    #+#             */
/*   Updated: 2021/11/13 18:08:37 by ielmakhf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	spaces(const char *str)
{
	char	*s;
	int		i;

	i = 0;
	s = (char *)str;
	while ((s[i] >= 9 && s[i] <= 13) || (s[i] == 32))
	{
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	char	*s;
	int		i;
	int		sign;
	int		num;

	s = (char *)str;
	i = spaces(str);
	sign = 1;
	num = 0;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
		{
			sign *= -1;
		}
		i++;
	}
	while (s[i] >= 48 && s[i] <= 57)
	{
		num = num * 10 + (s[i] - 48);
		i++;
	}
	return (num * sign);
}
