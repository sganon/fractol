/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 14:40:32 by sganon            #+#    #+#             */
/*   Updated: 2016/03/17 17:36:20 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	handle_pos(int key, t_ship *ptr)
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

int		ship_key_events(int key, t_env *e)
{
	if (key == ESC)
		exit(0);
	if (key == KEY_C)
		handle_color(e);
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		handle_pos(key, e->sh);
	if (key == KEY_R)
		init_ship(e->sh, e);
	expose_hook(e);
	return (1);
}


static void	draw_color(t_env *e, int i, int x, int y)
{
	t_color	u;
	int		p;

	p = x * 4 + y * e->sl;
	if (e->c < 7)
		u.color = HSV_to_RGB(i, e);
	else
		u.color = i * 6;
	if (check_for_x_y(x, y, e))
	{
		e->sh->img[p] = u.rgb.b;
		e->sh->img[p + 1] = u.rgb.g;
		e->sh->img[p + 2] = u.rgb.r;
	}
}

void	ship(t_env *e)
{
	int		x;
	int		y;
	int		i;
	double tmp;

	x = 0;
	while (x < e->img_x - 1)
	{
		y = 0;
		while (y < e->img_y - 1)
		{
			e->sh->c_r = x / e->sh->zoom_x + e->sh->min_x;
			e->sh->c_i = y / e->sh->zoom_y + e->sh->min_y;
			e->sh->z_r = 0;
			e->sh->z_i = 0;
			i = 0;
			while (e->sh->z_r * e->sh->z_r + e->sh->z_i * e->sh->z_i <= 4 && i <= e->sh->i_max)
			{
				tmp = e->sh->z_r;
				e->sh->z_r = ABS(e->sh->z_r * e->sh->z_r - e->sh->z_i * e->sh->z_i) + e->sh->c_r;
				e->sh->z_i = ABS(2 * e->sh->z_i * tmp) + e->sh->c_i;
				i++;
			}
			if (i != e->sh->i_max + 1)
				draw_color(e, i, x, y);
			y++;
		}
		x++;
	}
}
