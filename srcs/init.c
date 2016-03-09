/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:04:15 by sganon            #+#    #+#             */
/*   Updated: 2016/03/09 17:41:15 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		init_mandel(t_man *m, t_env *e)
{
	if (!(m->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "Mandelbrot")))
		return (0);
	m->min_x = -2.1;
	m->max_x = 0.6;
	m->min_y = -1.2;
	m->max_y = 1.2;
	m->zoom_x = e->img_x / (m->max_x - m->min_x);
	m->zoom_y = e->img_y / (m->max_y - m->min_y);
	m->img_ptr = NULL;
	m->img = NULL;
	return (1);
}

int		init_julia(t_jul *j, t_env *e)
{
	if (!(j->jwin = mlx_new_window(e->mlx, WIN_X, WIN_Y, "Julia")))
		return (0);
	j->jmin_x = -2.1;
	j->jmax_x = 2.1;
	j->jmin_y = -1.2;
	j->jmax_y = 1.2;
	j->j_c_r = 0.285;
	j->j_c_i = 0.01;
	j->jzoom_x = e->img_x / (e->j->jmax_x - e->j->jmin_x);
	j->jzoom_y = e->img_y / (e->j->jmax_y - e->j->jmin_y);
	j->jimg_ptr = NULL;
	j->jimg = NULL;
	return (1);
}

void	create_image(t_env *e)
{
	e->end = 0;
	e->bpp = 8;
	e->sl = WIN_X;
	e->m->img_ptr = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	e->m->img = mlx_get_data_addr(e->m->img_ptr, &(e->bpp), &(e->sl), &(e->end));
	e->j->jimg_ptr = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	e->j->jimg = mlx_get_data_addr(e->j->jimg_ptr, &(e->bpp), &(e->sl), &(e->end));
}

int		init_env(t_env *e)
{
	if (!(e->mlx = mlx_init()))
		return (0);
	e->i_max = 42;
	e->img_x = WIN_X;
	e->img_y = WIN_Y;
	e->m = (t_man *)malloc(sizeof(t_man));
	e->j = (t_jul *)malloc(sizeof(t_jul));
	init_mandel(e->m , e);
	init_julia(e->j, e);
	return (1);
}
