/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_and_draw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmakhf <ielmakhf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:16:45 by ielmakhf          #+#    #+#             */
/*   Updated: 2022/02/05 18:23:50 by ielmakhf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	exit_hook(t_fr *fr)
{
	mlx_destroy_image(fr->mlx_ptr, fr->img_ptr);
	mlx_clear_window(fr->mlx_ptr, fr->win_ptr);
	mlx_destroy_window(fr->mlx_ptr, fr->win_ptr);
	exit(1);
	return (0);
}

void	clear_and_draw(t_fr *fr)
{
	mlx_destroy_image(fr->mlx_ptr, fr->img_ptr);
	fr->img_ptr = mlx_new_image(fr->mlx_ptr, 500, 500);
	mlx_clear_window(fr->mlx_ptr, fr->win_ptr);
	if (fr->id_set == 0)
		draw_julia(fr);
	if (fr->id_set == 1)
		draw_mandelbrot(fr);
	if (fr->id_set == 2)
		draw_issam(fr);
	mlx_put_image_to_window(fr->mlx_ptr, fr->win_ptr, fr->img_ptr, 0, 0);
}

int	mouse_move(int x, int y, t_fr *fr)
{
	if (fr->id_set == 0)
	{
		fr->zoom.x = fr->min.x + ((double)x * (fr->max.x - fr->min.x)) / 500;
		fr->zoom.y = fr->min.y + ((double)y * (fr->max.y - fr->min.y)) / 500;
		clear_and_draw(fr);
	}
	return (0);
}

void	zoom(int x, int y, t_fr *fr, double z)
{
	t_cord	m;

	m.x = fr->min.x + ((double)x * (fr->max.x - fr->min.x)) / 500;
	m.y = fr->min.y + ((double)y * (fr->max.y - fr->min.y)) / 500;
	fr->min.x = m.x + (fr->min.x - m.x) * z;
	fr->max.x = m.x + (fr->max.x - m.x) * z;
	fr->min.y = m.y + (fr->min.y - m.y) * z;
	fr->max.y = m.y + (fr->max.y - m.y) * z;
}

int	mouse_hook(int m, int x, int y, t_fr *fr)
{
	if (m == 4)
	{
		fr->itr += 2;
		zoom(x, y, fr, 0.90);
	}
	if (m == 5 && fabs(fr->max.x - fr->min.x) <= 5)
	{
		fr->itr -= 2;
		zoom(x, y, fr, 1.10);
	}
	clear_and_draw(fr);
	return (0);
}
