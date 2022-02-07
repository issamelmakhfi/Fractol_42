/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmakhf <ielmakhf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:16:18 by ielmakhf          #+#    #+#             */
/*   Updated: 2022/02/05 17:38:02 by ielmakhf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	help_keys_move(int num, t_fr *fr)
{
	fr->mov = 2 * fabs(fr->max.x - fr->min.x) / 100;
	if (num == 1)
	{
		fr->min.y -= fr->mov;
		fr->max.y -= fr->mov;
	}
	if (num == 2)
	{
		fr->min.y += fr->mov;
		fr->max.y += fr->mov;
	}
	if (num == 3)
	{
		fr->min.x -= fr->mov;
		fr->max.x -= fr->mov;
	}
	if (num == 4)
	{
		fr->min.x += fr->mov;
		fr->max.x += fr->mov;
	}
}

int	keys_move(int keycode, t_fr *fr)
{
	if (keycode >= LEFT_ARROW && keycode <= UP_ARROW)
	{
		if (keycode == DOWN_ARROW || keycode == UP_ARROW)
		{
			if (keycode == DOWN_ARROW)
				help_keys_move(1, fr);
			else
				help_keys_move(2, fr);
		}
		else
		{
			if (keycode == RIGHT_ARROW)
				help_keys_move(3, fr);
			else
				help_keys_move(4, fr);
		}
		clear_and_draw(fr);
	}
	return (0);
}

void	keys(int keycode, t_fr *fr)
{
	if (keycode == M)
		fr->id_set = 1;
	if (keycode == V)
		fr->bpp = 1;
	if (keycode == B)
		fr->bpp = 0;
	if (keycode == J)
		julia(fr);
	if (keycode == T)
		julia1(fr);
	if (keycode == Y)
		julia2(fr);
	if (keycode == U)
		julia3(fr);
	clear_and_draw(fr);
}

int	keys_hook(int keycode, t_fr *fr)
{
	keys(keycode, fr);
	if (keycode == Q)
		fr->color = 0x2211FF;
	if (keycode == W)
		fr->color = 0xFFFFFF;
	if (keycode == ESC)
		exit_hook(fr);
	if (keycode == C)
	{
		fr->max.x = 2;
		fr->min.x = -2;
		fr->max.y = 2;
		fr->min.y = -2;
		fr->itr = 250;
		fr->color = 0xFFFFFF;
		clear_and_draw(fr);
	}
	return (keys_move(keycode, fr));
}
