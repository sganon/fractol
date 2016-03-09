/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 16:48:08 by sganon            #+#    #+#             */
/*   Updated: 2016/03/02 15:24:56 by sganon           ###   ########.fr       */
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
		c_x = (x - (WIN_X / 2)) * (e->max_x / (WIN_X / 2));
	else
		c_x = (x - (WIN_X / 2)) * ((-e->min_x / 2) / (WIN_X / 4));
	return (c_x);
}
double	get_complex_y(int y, t_env *e)
{
	double	c_y;

	if (y > (WIN_Y / 2))
		c_y = ((WIN_Y / 2) - y) * (-e->min_y / (WIN_Y / 2));
	else
		c_y = ((WIN_Y / 2) - y) * ((e->max_y / 2) / (WIN_Y / 4));
	return (c_y);
}

int		mouse_events(int button, int x, int y, t_env *e)
{
	static double	k = 0.5;
	double			x_complex;
	double			y_complex;

	x_complex = get_complex_x(x, e);
	y_complex = get_complex_y(y, e);
	printf("x_complex:%f\n", x_complex);
	printf("y_complex:%f\n", y_complex);
	if (button == 1)
	{
		e->min_x = x_complex + k;
		e->max_x = x_complex - k;
		printf("min_x:%f\n", e->min_x);
		printf("max_x:%f\n", e->max_x);
		e->min_y = y_complex + k;
		e->max_y = y_complex - k;
		printf("min_y:%f\n", e->min_y);
		printf("max_y:%f\n", e->max_y);
		k = k - 0.01;
		e->i_max = e->i_max + 20;
	}
	e->zoom_x = e->img_x / (e->max_x - e->min_x);
	e->zoom_y = e->img_y / (e->max_y - e->min_y);
	expose_hook(e);
	return (0);
}
