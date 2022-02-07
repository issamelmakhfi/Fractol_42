/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmakhf <ielmakhf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:12:23 by ielmakhf          #+#    #+#             */
/*   Updated: 2022/02/05 19:18:15 by ielmakhf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include <math.h>
# include <mlx.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>

# define A 				0
# define B 				11
# define C 				8
# define D 				2
# define E				4
# define F 				3
# define G 				5
# define H 				4
# define I 				34
# define J 				38
# define K 				40
# define L 				37
# define M 				46
# define N 				45
# define O 				31
# define P 				35
# define Q 				12
# define R 				15
# define S 				1
# define T 				17
# define U 				32
# define V 				9
# define W 				13
# define X 				7
# define Y 				16
# define Z 				6
# define ESC 			53
# define ONE_NUM_PAD	83
# define TWO_NUM_PAD	84
# define THREE_NUM_PAD	85
# define FOUR_NUM_PAD	86
# define FIVE_NUM_PAD	87
# define SIX_NUM_PAD	88
# define SEVEN_NUM_PAD	89
# define EIGHT_NUM_PAD	91
# define NINE_NUM_PAD	92
# define MORE			69
# define LESS			78
# define LEFT_ARROW		123
# define RIGHT_ARROW	124
# define DOWN_ARROW		125
# define UP_ARROW		126
# define KEYPRESS		2
# define BUTTONPRESS	4
# define MOTIONNOTIFY	6
# define DESTRYNOTIFY	17
# define SHIFTMAASK_0	0
# define SHIFTMAASK_1	1

typedef struct s_cord
{
	double				x;
	double				y;
}						t_cord;

typedef struct s_fr
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	int					*mlx_addr;
	int					bpp;
	int					sl;
	int					e;
	int					id_set;
	int					color;
	int					itr;
	t_cord				convert;
	t_cord				zoom;
	t_cord				min;
	t_cord				max;
	double				mov;
}						t_fr;

void					julia(t_fr *fr);
void					julia1(t_fr *fr);
void					julia2(t_fr *fr);
void					julia3(t_fr *fr);
int						ft_julia(t_fr *fr);
int						exit_hook(t_fr *fr);
int						ft_issam(t_fr *fr);
void					draw_julia(t_fr *fr);
void					draw_issam(t_fr *fr);
int						ft_mandelbrot(t_fr *fr);
void					clear_and_draw(t_fr *fr);
void					draw_mandelbrot(t_fr *fr);
int						keys_hook(int keycode, t_fr	*fr);
int						mouse_move(int x, int y, t_fr *fr);
void					zoom(int x, int y, t_fr *fr, double z);
int						mouse_hook(int m, int x, int y, t_fr *fr);

#endif