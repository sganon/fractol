/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:04:15 by sganon            #+#    #+#             */
/*   Updated: 2016/03/14 12:57:57 by sganon           ###   ########.fr       */
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
	m->i_max = 70;
	m->x_complex = 420;
	m->y_complex = 420;
	return (1);
}

int		init_julia(t_jul *j, t_env *e)
{
	if (!(j->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "Julia")))
		return (0);
	j->min_x = -2.1;
	j->max_x = 2.1;
	j->min_y = -1.2;
	j->max_y = 1.2;
	j->c_r = 0.285;
	j->c_i = 0.01;
	j->zoom_x = e->img_x / (e->j->max_x - e->j->min_x);
	j->zoom_y = e->img_y / (e->j->max_y - e->j->min_y);
	j->img_ptr = NULL;
	j->img = NULL;
	j->i_max = 70;
	return (1);
}

int		init_sierp(t_sierp *s, t_env *e)
{
	if (!(s->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "Sierpinski")))
		return (0);
	s->x = WIN_X / 2 - 400;
	s->y = WIN_Y - 100;
	s->a = 800;
	s->i = 3;
	return (1);
}

void	create_image(t_env *e)
{
	e->end = 0;
	e->bpp = 8;
e->sl = WIN_X;
	e->m->img_ptr = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	e->m->img = mlx_get_data_addr(e->m->img_ptr, &(e->bpp), &(e->sl), &(e->end));
	e->j->img_ptr = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	e->j->img = mlx_get_data_addr(e->j->img_ptr, &(e->bpp), &(e->sl), &(e->end));
	e->s->img_ptr = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	e->s->img = mlx_get_data_addr(e->s->img_ptr, &(e->bpp), &(e->sl), &(e->end));
}

int		init_env(t_env *e)
{
	if (!(e->mlx = mlx_init()))
		return (0);
	e->img_x = WIN_X;
	e->img_y = WIN_Y;
	e->m = (t_man *)malloc(sizeof(t_man));
	e->j = (t_jul *)malloc(sizeof(t_jul));
	e->s = (t_sierp *)malloc(sizeof(t_sierp));
	e->c = 0;
	if (e->mandel)
		init_mandel(e->m , e);
	if (e->jul)
		init_julia(e->j, e);
	if (e->sierp)
		init_sierp(e->s, e);
	return (1);
}
