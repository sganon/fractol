/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 16:48:08 by sganon            #+#    #+#             */
/*   Updated: 2016/03/14 11:59:28 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

	if (button == 1 && x <= WIN_X && y > 30)
	{
		x_complex = x / e->j->zoom_x + e->j->min_x;
		y_complex = y / e->j->zoom_y + e->j->min_y;
		e->j->min_x = x_complex - k;
		e->j->min_y = y_complex - k;
		e->j->max_x = x_complex + k;
		e->j->max_y = y_complex + k;
		k = k * 0.5;
		e->j->i_max += 10;
	}
	e->j->zoom_x = e->img_x / (e->j->max_x - e->j->min_x);
	e->j->zoom_y = e->img_y / (e->j->max_y - e->j->min_y);
	expose_hook(e);
	return (0);
}

int		mouse_events(int button, int x, int y, t_env *e)
{
	double	x_complex;
	double	y_complex;
	static double k = 0.78;

	x_complex = x / e->m->zoom_x + e->m->min_x;
	y_complex = y / e->m->zoom_y + e->m->min_y;
	if (button == 1)
	{
		e->m->max_x = x_complex + k;
		e->m->min_x = x_complex - k;
		e->m->max_y = y_complex + k;
		e->m->min_y = y_complex - k;
		e->m->i_max += 15;
		k *= 0.5;
	}
	e->m->zoom_x = e->img_x / (e->m->max_x - e->m->min_x);
	e->m->zoom_y = e->img_y / (e->m->max_y - e->m->min_y);
	expose_hook(e);
	return (0);
}
