/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 16:48:08 by sganon            #+#    #+#             */
/*   Updated: 2016/02/26 18:05:23 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
//
//
//
#include <stdio.h>


double	get_mouse_x(int x, t_env *e)
{
	if (x > WIN_X / 2)
		return (e->max_x / x);
	else if (x > 0 && x < WIN_X / 2)
		return (-e->max_x / x);
	else
		return (e->min_x);
}

double	get_mouse_y(int y, t_env *e)
{
	if (y > WIN_Y / 2)
		return (-e->max_y / y);
	else if (y > 0 && y < WIN_Y / 2)
		return (e->max_y / y);
	else
		return (e->max_y);
}

int		mouse_events(int button, int x, int y, t_env *e)
{
	static double	k = 0.8;
	double			x_complex;
	double			y_complex;

	x_complex = (0.6 * x) / WIN_X;
	y_complex = (-1.2 * y) / WIN_Y;
	printf("x_complex:%f\n", x_complex);
	printf("x:%d\n", x);
	printf("y_complex:%f\n", y_complex);
	printf("y:%d\n", y);
	if (button == 1)
	{
		e->min_x = x_complex - k;
		e->max_x = x_complex + k;
		e->min_y = y_complex - k;
		e->max_y = y_complex + k;
		e->i_max = e->i_max + 20;
	}
	e->zoom_x = e->img_x / (e->max_x - e->min_x);
	e->zoom_y = e->img_y / (e->max_y - e->min_y);
	expose_hook(e);
	return (0);
}
