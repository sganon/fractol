/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 16:48:08 by sganon            #+#    #+#             */
/*   Updated: 2016/02/24 19:59:06 by sganon           ###   ########.fr       */
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
	if (x > 0 && x < WIN_X / 2)
		return (e->min_x / x);
	else
		return (e->min_x);
}

double	get_mouse_y(int y, t_env *e)
{
	if (y > WIN_Y / 2)
		return (e->min_y / y);
	if (y > 0 && y < WIN_Y / 2)
		return (e->max_y / y);
	else
		return (e->max_y);
}

int		mouse_events(int button, int x, int y, t_env *e)
{
	static double	k = 1;
	double			mouse_x;
	double			mouse_y;

	mouse_x = get_mouse_x(x, e);
	mouse_y = get_mouse_y(y, e);
	printf("%f\n", mouse_x);
	printf("%f\n", mouse_y);
	if (button == 1)
	{
		e->min_x = mouse_x - k;
		e->max_x = mouse_x + k;
		e->min_y = mouse_y - k;
		e->max_y = mouse_y + k;
		e->i_max = e->i_max + 20;
		k = k * 0.9;
	}
	if (button == 2)
	{
		e->min_x = mouse_x + k;
		e->max_x = mouse_x - k;
		e->min_y = mouse_y + k;
		e->max_y = mouse_y - k;
		e->i_max = e->i_max - 20;
		k = k / 0.9;
	}
	e->zoom_x = e->img_x / (e->max_x - e->min_x);
	e->zoom_y = e->img_y / (e->max_y - e->min_y);
	expose_hook(e);
	return (0);
}
