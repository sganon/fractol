/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_mouse_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 18:08:25 by sganon            #+#    #+#             */
/*   Updated: 2016/03/09 19:28:51 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	julia_get_complex_x(int x, t_env *e)
{
	double	c_x;
	
	if (e->mandel)
	{
		if (x > (WIN_X / 2))
			c_x = (x - (WIN_X / 2)) * (e->m->max_x / (WIN_X / 2));
		else
			c_x = (x - (WIN_X / 2)) * ((-e->m->min_x / 2) / (WIN_X / 4));
	}
	else
	{
		if (x > (WIN_X / 2))
			c_x = (x - (WIN_X / 2)) * (e->j->max_x / (WIN_X / 2));
		else
			c_x = (x - (WIN_X / 2)) * ((-e->j->min_x / 2) / (WIN_X / 4));
	}
	return (c_x);
}

double	julia_get_complex_y(int y, t_env *e)
{
	double	c_y;

	if (e->mandel)
	{
		if (y > (WIN_Y / 2))
			c_y = ((WIN_Y / 2) - y) * (-e->m->min_y / (WIN_Y / 2));
		else
			c_y = ((WIN_Y / 2) - y) * ((e->m->max_y / 2) / (WIN_Y / 4));
	}
	else
	{
		if (y > (WIN_Y / 2))
			c_y = ((WIN_Y / 2) - y) * (-e->j->min_y / (WIN_Y / 2));
		else
			c_y = ((WIN_Y / 2) - y) * ((e->j->max_y / 2) / (WIN_Y / 4));
	}
	return (c_y);
}

int		move_c(int x, int y, t_env *e)
{
	double		x_complex;
	double		y_complex;

	if (x <= WIN_X && y <= WIN_Y)
	{
		x_complex = julia_get_complex_x(x, e);
		y_complex = julia_get_complex_y(y, e);
		e->j->c_r = x_complex;
		e->j->c_i = y_complex;
		expose_hook(e);
		return (1);
	}
	return (0);
}

int		julia_mouse_events(int button, int x, int y, t_env *e)
{
	static double	k = 0.9;
	double			x_complex;
	double			y_complex;

	if (button == 1 && x <= WIN_X && y <= WIN_Y)
	{
		x_complex = julia_get_complex_x(x, e);
		y_complex = julia_get_complex_y(y, e);
		e->j->min_x = x_complex - k;
		e->j->min_y = y_complex - k;
		e->j->max_x = x_complex + k;
		e->j->max_y = y_complex + k;
		k = k * 0.9;
		e->j->i_max += 10;
		expose_hook(e);
		return (1);
	}
	return (0);
}
