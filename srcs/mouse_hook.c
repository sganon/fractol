/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 16:48:08 by sganon            #+#    #+#             */
/*   Updated: 2016/03/17 18:05:09 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		sierp_mouse_events(int button, int x, int y, t_env *e)
{
	(void)y;
	if (button == 1 || button == WHEEL_UP)
	{
		e->s->a += 80;
		e->s->x = x - e->s->a / 2;
	}
	expose_hook(e);
	return (1);
}

int		move_c(int x, int y, t_env *e)
{
	double		x_complex;
	double		y_complex;

	if (x <= WIN_X && y <= WIN_Y)
	{
		if (e->mandel)
		{
			x_complex = x / e->m->zoom_x + e->m->min_x;
			y_complex = y / e->m->zoom_y + e->m->min_y;
		}
		else
		{
			x_complex = x / e->j->zoom_x + e->j->min_x;
			y_complex = y / e->j->zoom_y + e->j->min_y;
		}
		e->j->c_r = x_complex;
		e->j->c_i = y_complex;
		expose_hook(e);
		return (1);
	}
	return (0);
}

int		julia_mouse_events(int button, int x, int y, t_env *e)
{
	static double	k = 0.78;
	double			x_complex;
	double			y_complex;

	x_complex = x / e->j->zoom_x + e->j->min_x;
	y_complex = y / e->j->zoom_y + e->j->min_y;
	if (button == 2 || button == WHEEL_DOWN)
		k /= 0.5;
	e->j->min_x = x_complex - k;
	e->j->min_y = y_complex - k;
	e->j->max_x = x_complex + k;
	e->j->max_y = y_complex + k;
	e->j->i_max += 4;
	if (button == 1 || button == WHEEL_UP)
		k *= 0.5;
	e->j->zoom_x = e->img_x / (e->j->max_x - e->j->min_x);
	e->j->zoom_y = e->img_y / (e->j->max_y - e->j->min_y);
	expose_hook(e);
	return (0);
}

int		ship_mouse_events(int button, int x, int y, t_env *e)
{
	double			x_complex;
	double			y_complex;
	static double	k = 0.78;

	x_complex = x / e->sh->zoom_x + e->sh->min_x;
	y_complex = y / e->sh->zoom_y + e->sh->min_y;
	if (button == 2 || button == WHEEL_DOWN)
		k /= 0.5;
	e->sh->max_x = x_complex + k;
	e->sh->min_x = x_complex - k;
	e->sh->max_y = y_complex + k;
	e->sh->min_y = y_complex - k;
	e->sh->i_max += 4;
	if (button == 1 || button == WHEEL_UP)
		k *= 0.5;
	e->sh->zoom_x = e->img_x / (e->sh->max_x - e->sh->min_x);
	e->sh->zoom_y = e->img_y / (e->sh->max_y - e->sh->min_y);
	expose_hook(e);
	return (0);
}

int		mouse_events(int button, int x, int y, t_env *e)
{
	double			x_complex;
	double			y_complex;
	static double	k = 0.78;

	x_complex = x / e->m->zoom_x + e->m->min_x;
	y_complex = y / e->m->zoom_y + e->m->min_y;
	if (button == 2 || button == WHEEL_DOWN)
		k /= 0.5;
	e->m->max_x = x_complex + k;
	e->m->min_x = x_complex - k;
	e->m->max_y = y_complex + k;
	e->m->min_y = y_complex - k;
	e->m->i_max += 4;
	if (button == 1 || button == WHEEL_UP)
		k *= 0.5;
	e->m->zoom_x = WIN_X / (e->m->max_x - e->m->min_x);
	e->m->zoom_y = WIN_Y / (e->m->max_y - e->m->min_y);
	expose_hook(e);
	return (0);
}
