/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julias.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmakhf <ielmakhf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:12:15 by ielmakhf          #+#    #+#             */
/*   Updated: 2022/02/05 18:00:40 by ielmakhf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_fr *fractol)
{
	fractol->zoom.x = 0.285;
	fractol->zoom.y = 0.01;
	fractol->max.x = 2;
	fractol->min.x = -2;
	fractol->max.y = 2;
	fractol->min.y = -2;
	fractol->itr = 250;
	fractol->id_set = 0;
}

void	julia1(t_fr *fractol)
{
	fractol->zoom.x = 0.3;
	fractol->zoom.y = 0.5;
	fractol->max.x = 2;
	fractol->min.x = -2;
	fractol->max.y = 2;
	fractol->min.y = -2;
	fractol->itr = 250;
	fractol->id_set = 0;
}

void	julia2(t_fr *fractol)
{
	fractol->zoom.x = -0.038088;
	fractol->zoom.y = 0.9754633;
	fractol->max.x = 2;
	fractol->min.x = -2;
	fractol->max.y = 2;
	fractol->min.y = -2;
	fractol->itr = 250;
	fractol->id_set = 0;
}

void	julia3(t_fr *fractol)
{
	fractol->zoom.x = -0.4;
	fractol->zoom.y = 0.6;
	fractol->max.x = 2;
	fractol->min.x = -2;
	fractol->max.y = 2;
	fractol->min.y = -2;
	fractol->itr = 250;
	fractol->id_set = 0;
}
