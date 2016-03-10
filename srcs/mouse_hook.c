/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 16:48:08 by sganon            #+#    #+#             */
/*   Updated: 2016/03/10 18:16:12 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
//
//
//
#include <stdio.h>


double	get_complex_x(int x, t_env *e)
{
	double	x_o;
	double	c_x;
	
	(void)e;
	x_o = WIN_X - (WIN_X * (e->m->max_x / -e->m->min_x));
	c_x = x - x_o;
	c_x = c_x * (e->m->max_x / (WIN_X * (e->m->max_x / -e->m->min_x)));
	return (c_x);
}

double	get_complex_y(int y, t_env *e)
{
	double y_o;
	double	c_y;
	
	(void)e;
	y_o = WIN_Y / 2;
	c_y = y_o - y;
	c_y = c_y * (-e->m->min_y / WIN_Y);
	return (c_y);
}

int		mouse_events(int button, int x, int y, t_env *e)
{
	double			x_complex;
	double			y_complex;
	static double	k = 0.19;

	x_complex = get_complex_x(x, e);
	y_complex = get_complex_y(y, e);
	printf("x_complex: %f\n", x_complex);
	printf("y_complex: %f\n", y_complex);
	if (button == 1)
	{
		e->m->min_x = x_complex - k * 3;
		e->m->max_x = x_complex + k; 
		e->m->min_y = y_complex + k * 2;
		e->m->max_y = y_complex - k * 2;
		printf("max_x: %f\n", e->m->max_x);
		printf("min_x: %f\n", e->m->min_x);
		printf("max_y: %f\n", e->m->max_y);
		printf("min_y: %f\n", e->m->min_y);
		e->m->i_max += 15;
		k *= 0.9; 
	}
	e->m->zoom_x = e->img_x / (e->m->max_x - e->m->min_x);
	e->m->zoom_y = e->img_y / (e->m->max_y - e->m->min_y);
	expose_hook(e);
	return (0);
}
