/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 16:48:08 by sganon            #+#    #+#             */
/*   Updated: 2016/03/09 17:44:59 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
//
//
//
#include <stdio.h>


double	get_complex_x(int x, t_env *e)
{
	double	c_x;

	if (x > (WIN_X / 2))
		c_x = (x - (WIN_X / 2)) * (e->m->max_x / (WIN_X / 2));
	else
		c_x = (x - (WIN_X / 2)) * ((-e->m->min_x / 2) / (WIN_X / 4));
	return (c_x);
}
double	get_complex_y(int y, t_env *e)
{
	double	c_y;

	if (y > (WIN_Y / 2))
		c_y = ((WIN_Y / 2) - y) * (-e->m->min_y / (WIN_Y / 2));
	else
		c_y = ((WIN_Y / 2) - y) * ((e->m->max_y / 2) / (WIN_Y / 4));
	return (c_y);
}

int		mouse_events(int button, int x, int y, t_env *e)
{
	double			tmp;
	static double	k = 0.25;
	double			x_complex;
	double			y_complex;

	x_complex = get_complex_x(x, e);
	y_complex = get_complex_y(y, e);
	if (button == 1)
	{
		e->m->min_x = x_complex + 3 * k;//fabs((e->min_x + x_complex) / 2);
		e->m->max_x = x_complex - k;//fabs((e->max_x + x_complex) / 2);
		e->m->min_y = y_complex + k;//fabs((e->min_y + y_complex) / 2);
		e->m->max_y = y_complex - k;//fabs((e->max_y + y_complex) / 2);
		if (e->m->min_x > e->m->max_x)
		{
			tmp = e->m->min_x;
			e->m->min_x = e->m->max_x;
			e->m->max_x = tmp;
		}
		if (e->m->min_y > e->m->max_y)
		{
			tmp = e->m->min_y;
			e->m->min_y = e->m->max_y;
			e->m->max_y = tmp;
		}
		k = k * 0.1;
		e->i_max = e->i_max + 15;
	}
	e->m->zoom_x = e->img_x / (e->m->max_x - e->m->min_x);
	e->m->zoom_y = e->img_y / (e->m->max_y - e->m->min_y);
	expose_hook(e);
	return (0);
}
