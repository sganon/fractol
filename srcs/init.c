/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:04:15 by sganon            #+#    #+#             */
/*   Updated: 2016/03/18 16:39:45 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		init_mandel(t_man *m, t_env *e)
{
	if (m->win == NULL)
	{
		if (!(e->m->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "Mandelbrot")))
			return (0);
	}
	m->min_x = -2.1;
	m->max_x = 0.6;
	m->min_y = -1.2;
	m->max_y = 1.2;
	m->zoom_x = e->img_x / (m->max_x - m->min_x);
	m->zoom_y = e->img_y / (m->max_y - m->min_y);
	m->i_max = 70;
	m->z_r = 0;
	m->z_i = 0;
	m->img_ptr = NULL;
	m->img = NULL;
	return (1);
}

int		init_ship(t_ship *sh, t_env *e)
{
	if (sh->win == NULL)
	{
		if (!(sh->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "Burning Ship")))
			return (0);
	}
	sh->min_x = -2.1;
	sh->max_x = 0.39;
	sh->min_y = -2.5;
	sh->max_y = 0.5;
	sh->zoom_x = e->img_x / (sh->max_x - sh->min_x);
	sh->zoom_y = e->img_y / (sh->max_y - sh->min_y);
	sh->i_max = 70;
	sh->img_ptr = NULL;
	sh->img = NULL;
	return (1);
}

int		init_julia(t_jul *j, t_env *e)
{
	if (j->win == NULL)
	{
		if (!(j->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "Julia")))
			return (0);
	}
	j->min_x = -2.1;
	j->max_x = 2.1;
	j->min_y = -1.2;
	j->max_y = 1.2;
	j->c_r = 0.285;
	j->c_i = 0.01;
	j->zoom_x = e->img_x / (e->j->max_x - e->j->min_x);
	j->zoom_y = e->img_y / (e->j->max_y - e->j->min_y);
	j->i_max = 70;
	j->img_ptr = NULL;
	j->img = NULL;
	return (1);
}

int		init_sierp(t_sierp *s, t_env *e)
{
	if (s->win == NULL)
	{
		if (!(s->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "Sierpinski")))
			return (0);
	}
	s->x = WIN_X / 2 - 400;
	s->y = WIN_Y - 100;
	s->a = 800;
	s->i = 3;
	s->img_ptr = NULL;
	s->img = NULL;
	return (1);
}

int		create_image(t_env *e)
{
	e->end = 0;
	e->bpp = 8;
	e->sl = WIN_X;
	e->m->img_ptr = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	e->j->img_ptr = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	e->s->img_ptr = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	e->sh->img_ptr = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	if (!e->m->img_ptr || !e->j->img_ptr || !e->s->img_ptr || !e->sh->img_ptr)
		ft_error(-1);
	EM(img) = mlx_get_data_addr(EM(img_ptr), &(e->bpp), &(e->sl), &(e->end));
	EJ(img) = mlx_get_data_addr(EJ(img_ptr), &(e->bpp), &(e->sl), &(e->end));
	ES(img) = mlx_get_data_addr(ES(img_ptr), &(e->bpp), &(e->sl), &(e->end));
	ESH(img) = mlx_get_data_addr(ESH(img_ptr), &(e->bpp), &(e->sl), &(e->end));
	return (1);
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
	e->sh = (t_ship *)malloc(sizeof(t_ship));
	e->m->win = NULL;
	e->j->win = NULL;
	e->sh->win = NULL;
	e->s->win = NULL;
	if (!e->sh || !e->m || !e->j || !e->s)
		return (0);
	e->c = 0;
	if (e->mandel && init_mandel(e->m, e) == 0)
		return (0);
	if (e->jul && init_julia(e->j, e) == 0)
		return (0);
	if (e->sierp && init_sierp(e->s, e) == 0)
		return (0);
	if (e->ship && init_ship(e->sh, e) == 0)
		return (0);
	return (1);
}
