/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmakhf <ielmakhf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:12:00 by ielmakhf          #+#    #+#             */
/*   Updated: 2022/02/05 17:34:52 by ielmakhf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	check_iteration(int itr, float x, float y, t_cord cord)
{
	int		i;
	t_cord	z;
	double	old_real_nbr;

	i = 0;
	z.x = x;
	z.y = y;
	while ((i < itr) && ((z.x * z.x + z.y * z.y) < 4))
	{
		old_real_nbr = z.x;
		z.x = (z.x * z.x) - (z.y * z.y) + cord.x;
		z.y = (2 * old_real_nbr * z.y) + cord.y;
		i = i + 2;
	}
	return (i);
}

void	draw_julia(t_fr *fr)
{
	int			i;
	int			j;
	int			res;
	t_cord		cord;

	j = 0;
	while (j <= 500)
	{
		i = 0;
		cord.y = fr->min.y + (j * (fr->max.y - fr->min.y)) / 500;
		while (i <= 500)
		{
			cord.x = fr->min.x + (i * (fr->max.x - fr->min.x)) / 500;
			res = check_iteration(fr->itr, cord.x, cord.y, fr->zoom);
			if (res != fr->itr)
				fr->mlx_addr[(j * 500) + i] = res * fr->color;
			else
				fr->mlx_addr[(j * 500) + i] = 0x000000;
			i++;
		}
		j++;
	}
}

int	ft_julia(t_fr *fr)
{
	fr->zoom.x = 0.285;
	fr->zoom.y = 0.01;
	fr->max.x = 2;
	fr->min.x = -2;
	fr->max.y = 2;
	fr->min.y = -2;
	fr->itr = 250;
	fr->bpp = 1;
	draw_julia(fr);
	return (1);
}
