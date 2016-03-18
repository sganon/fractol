/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:27:52 by sganon            #+#    #+#             */
/*   Updated: 2016/03/18 12:47:25 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	handle_pos(int key, t_jul *ptr)
{
	double	x_dif;
	double	y_dif;

	x_dif = ABS(ptr->max_x - ptr->min_x);
	y_dif = ABS(ptr->max_y - ptr->min_y);
	if (key == UP)
	{
		ptr->min_y -= y_dif / 5;
		ptr->max_y -= y_dif / 5;
	}
	if (key == DOWN)
	{
		ptr->min_y += y_dif / 5;
		ptr->max_y += y_dif / 5;
	}
	if (key == RIGHT)
	{
		ptr->min_x += x_dif / 5;
		ptr->max_x += x_dif / 5;
	}
	if (key == LEFT)
	{
		ptr->min_x -= x_dif / 5;
		ptr->max_x -= x_dif / 5;
	}
}

int			julia_key_events(int key, t_env *e)
{
	if (key == ESC)
		exit(0);
	if (key == KEY_C)
		handle_color(e);
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		handle_pos(key, e->j);
	if (key == KEY_R)
		init_julia(e->j, e);
	expose_hook(e);
	return (1);
}

static void	draw_color(t_env *e, int i, int x, int y)
{
	t_color	u;
	int		p;

	p = x * 4 + y * e->sl;
	if (e->c < 7)
		u.color = hsv_to_rgb(i, e);
	else
		u.color = i * 6;
	if (check_for_x_y(x, y, e))
	{
		e->j->img[p] = u.rgb.b;
		e->j->img[p + 1] = u.rgb.g;
		e->j->img[p + 2] = u.rgb.r;
	}
}

void		julia(t_env *e)
{
	int		x;
	int		y;
	int		i;
	double	tmp;

	x = -1;
	while (++x < e->img_x)
	{
		y = -1;
		while (++y < e->img_y)
		{
			e->j->z_r = x / e->j->zoom_x + e->j->min_x;
			e->j->z_i = y / e->j->zoom_y + e->j->min_y;
			i = 0;
			while (pow(e->j->z_r, 2) + pow(e->j->z_i, 2) <= 4 && i < EJ(i_max))
			{
				tmp = e->j->z_r;
				e->j->z_r = pow(e->j->z_r, 2) - pow(e->j->z_i, 2) + e->j->c_r;
				e->j->z_i = 2 * e->j->z_i * tmp + e->j->c_i;
				i++;
			}
			if (i != e->j->i_max)
				draw_color(e, i, x, y);
		}
	}
}
