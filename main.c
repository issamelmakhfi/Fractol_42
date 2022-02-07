/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmakhf <ielmakhf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:13:31 by ielmakhf          #+#    #+#             */
/*   Updated: 2022/02/05 19:40:11 by ielmakhf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(void)
{
	ft_putendl_fd("\033[0;31m***************************************\033[0m", 1);
	ft_putendl_fd("\033[0;31m*   Usage---> ./fractol <fractal.c>   *\033[0m", 1);
	ft_putendl_fd("\033[0;31m***************************************\033[0m", 1);
	ft_putendl_fd("\033[0;31m*     -----> : mandelbrot.c           *\033[0m", 1);
	ft_putendl_fd("\033[0;31m*     -----> : julia.c                *\033[0m", 1);
	ft_putendl_fd("\033[0;31m*     -----> : issam.c                *\033[0m", 1);
	ft_putendl_fd("\033[0;31m***************************************\033[0m", 1);
	exit(0);
}

int	fractol(int id)
{
	t_fr	fr;

	fr.id_set = id;
	fr.color = 0xFFFFFF;
	fr.mlx_ptr = mlx_init();
	fr.win_ptr = mlx_new_window(fr.mlx_ptr, 500, 500, "Fractol");
	fr.img_ptr = mlx_new_image(fr.mlx_ptr, 500, 500);
	fr.mlx_addr = (int *)mlx_get_data_addr(fr.img_ptr, &fr.bpp, &fr.sl, &fr.e);
	if (id == 0)
		ft_julia(&fr);
	if (id == 1)
		ft_mandelbrot(&fr);
	if (id == 2)
		ft_issam(&fr);
	mlx_put_image_to_window(fr.img_ptr, fr.win_ptr, fr.img_ptr, 0, 0);
	mlx_key_hook(fr.win_ptr, keys_hook, &fr);
	mlx_mouse_hook(fr.win_ptr, mouse_hook, &fr);
	mlx_hook(fr.win_ptr, DESTRYNOTIFY, SHIFTMAASK_0, exit_hook, &fr);
	mlx_hook(fr.win_ptr, MOTIONNOTIFY, SHIFTMAASK_0, mouse_move, &fr);
	mlx_loop(fr.mlx_ptr);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		if (!ft_strcmp(av[1], "julia.c"))
			return (fractol(0));
		if (!ft_strcmp(av[1], "mandelbrot.c"))
			return (fractol(1));
		if (!ft_strcmp(av[1], "issam.c"))
			return (fractol(2));
	}
	ft_error();
	return (0);
}
