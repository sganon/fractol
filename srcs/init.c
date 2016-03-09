/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:04:15 by sganon            #+#    #+#             */
/*   Updated: 2016/03/09 16:12:53 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		init_env_for_mandel(t_env *e)
{
	if (!(e->mlx = mlx_init()))
		return (0);
	if (!(e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "Mandelbrot")))
		return (0);
	e->min_x = -2.1;
	e->max_x = 0.6;
	e->min_y = -1.2;
	e->max_y = 1.2;
	e->img_x = WIN_X;
	e->img_y = WIN_Y;
	e->i_max = 42;
	e->zoom_x = e->img_x / (e->max_x - e->min_x);
	e->zoom_y = e->img_y / (e->max_y - e->min_y);
	e->img_ptr = NULL;
	e->img = NULL;
	return (1);
}

int		init_env_for_julia(t_env *e)
{
	if (!(e->jwin = mlx_new_window(e->mlx, WIN_X, WIN_Y, "Julia")))
		return (0);
	e->jmin_x = -2.1;
	e->jmax_x = 2.1;
	e->jmin_y = -1.2;
	e->jmax_y = 1.2;
	e->j_c_r = 0.285;
	e->j_c_i = 0.01;
	e->jzoom_x = e->img_x / (e->jmax_x - e->jmin_x);
	e->jzoom_y = e->img_y / (e->jmax_y - e->jmin_y);
	e->jimg_ptr = NULL;
	e->jimg = NULL;
	return (1);
}

void	create_image(t_env *e)
{
	e->end = 0;
	e->bpp = 8;
	e->sl = WIN_X;
	e->img_ptr = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	e->img = mlx_get_data_addr(e->img_ptr, &(e->bpp), &(e->sl), &(e->end));
	e->jimg_ptr = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	e->jimg = mlx_get_data_addr(e->jimg_ptr, &(e->bpp), &(e->sl), &(e->end));
}
